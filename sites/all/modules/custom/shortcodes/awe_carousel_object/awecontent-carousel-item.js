(function($) {
    "use strict";
    AWEContent.Models.CarouselSlide = Backbone.RelationalModel.extend({
        defaults: {
            content: []
        },
        relations: [
            {
                type: Backbone.HasMany,
                key: 'content',
                relatedModel: AWEContent.Models.Column,
                relatedCollection: AWEContent.Collections.ListColumn
            }
        ],
        clone: function(){
            var column = new AWEContent.Collections.ListColumn();
            this.get('content').each( function( data) {
                column.add( data.clone());
            });
            return new AWEContent.Models.CarouselSlide({
                content:  column
            });
        },
        createView: function(){
            this.view = new AWEContent.Views.CarouselSlide({model: this});
            return this.view.$el;
        }
    });

    AWEContent.Views.CarouselSlide = Backbone.View.extend({
        tagName: 'div',
        className: 'awe-carousel-slide',
        event: {
        },
        htmlTemplate: _.template(' <div class="awe-custom custom-obj custom-carousel"><ul><li class="awe-carousel-delete"><i class="ic ac-icon-trash"></i></li></ul></div><div class="content-slide"></div>'),
        initialize: function(){
            var self = this,
                viewListColumn = new AWEContent.Views.ListColumn({ collection: this.model.get('content')});
            // Render Data Content
            self.$el.append(self.htmlTemplate);
            self.$ctSlide = $('.content-slide', self.el);
            self.$ctSlide.append(viewListColumn.$el);
        }
    });

    AWEContent.Collections.ListCarousel = Backbone.Collection.extend({
        model: AWEContent.Models.CarouselSlide
    });

    AWEContent.Models.CarouselItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: 'carousel',
            items: 2,
            itemsResponsive: 0,
            itemsDesktopSmall :3,
            itemsTablet: 2,
            itemsMobile : 1,
            autoPlay: 0,
            timeAutoPlay: 5,
            stopOnHover : 0,
            navigation: 0,
            navigationStyle : 'none',
            pagination: 1,
            paginationStyle : 'none',
            mouseDrag: 0,
            touchDrag: 0,
            effect: 'fade',
            slides: [],
            boxModelSettings : {},
            customID : '',
            customClass : '',
            customEnableAttributes: 0,
            customDataAttributes: '[]',// Array Json ex : [{"attrName":"autoPlay","attrValue":"true"}]
            customActionAtrributes: '{"newAction": "", "newAttrName": "", "newAttrValue": ""}',
            customEnableAnimations: 0,
            customDataAnimations: '', // Data Object {"type":"spinin","duration":"5000","delay":"0","advance":{"direction":"clockwise","numberOfSpin":"3"}}
            previewAnimations : 0,
            lgResponsive: true,
            xsResponsive: true,
            mediumResponsive: true,
            smResponsive: true
        },
        relations: [
            {
                type: Backbone.HasMany,
                key: "slides",
                relatedModel: AWEContent.Models.CarouselSlide,
                relatedCollection: AWEContent.Collections.ListCarousel,
                reverseRelation: {
                    key: 'carouselItem'
                }
            },
            {
                type: Backbone.HasOne,
                key: 'boxModelSettings',
                relatedModel: AWEContent.Models.BoxModelSettings
            }
        ],
        hasContentLayout: true,
        getContentColumnModel: function($column, colID) {
            var $owlSlide = $column.closest('.owl-item'),
                indexModel = $owlSlide.index(),
                slideModel = this.get('slides').at(indexModel);
            return slideModel.get("content").at(colID);
        },
        createView: function(){
            this.view = new AWEContent.Views.CarouselItem({model: this})
        },
        clone: function(){
            var cloneModel = {},
                listCarousel = new  AWEContent.Collections.ListCarousel();
            this.get('slides').each( function(carouselSlide) {
                listCarousel.add(carouselSlide.clone());
            });
            $.each(this.toJSON(), function(key,value){
                if (key != 'slides')
                    cloneModel[key] = value;
            });
            cloneModel.slides = listCarousel;
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.CarouselItem(cloneModel);
        }
    });
    AWEContent.Views.CarouselItem = AWEContent.Views.Item.extend({
        additionalEvents: {
            'click >.awe-carousel > .awe-carousel-control > ul > .js-carousel-next' : 'nextSlide',
            'click >.awe-carousel > .awe-carousel-control > ul > .js-carousel-prev' : 'prevSlide'
        },
        htmlControl: _.template('<ul><li class="js-carousel-next"><i class="ic ac-icon-edit">Next</i></li><li class="js-carousel-prev"><i class="ic ac-icon-clone"> Previous</i></li></ul>'),
        initialize: function(){
            var self = this;
            AWEContent.Views.Item.prototype.initialize.call(this);
            this.listenTo(this.model.get("boxModelSettings"), "change", this.applySettingsChanged);
			
            // Dynamic add or remove slide
            var query = '>.awe-carousel >.awe-carousel-content >.owl-wrapper-outer >.owl-wrapper >.owl-item >.awe-carousel-slide >.content-slide>.row >.awe-col>.awe-col-content >.awe-col-wrapper';
            if (!this.$el.closest('.awe-carousel').length) {
                this.$el.delegate( query, 'actionChangeCollection', function (event, data) {
                    event.stopPropagation();
                    if (data.action === 'relational:add' || data.action === 'relational:remove') {
                        // Check items use plugin owlcarousel
                        var itemsUseOwlcarousel = ['slideshow', 'carousel'],
                            machineName = data.model.get('machine_name');
                        if($.inArray(machineName, itemsUseOwlcarousel) != -1) {
                            if (data.action == 'relational:add') {
                                self.iframeJQuery(data.model.view.el).bind('itemReady', function () {
                                    setTimeout(function () {
                                        $('> .awe-custom > ul > .js-obj-delete', data.model.view.el).trigger('click');
                                    },150);
                                });
                            }
                        }
                        else {
                            // Check last slide
                            var $slide = $(this).closest('.owl-item'),
                                indexSlide = $slide.index(),
                                totalSlide =  self.model.get('slides').length;
                            if (indexSlide == totalSlide - 1) {
                                // Create new slide
                                self.addSlide();
                                self.goToSlide(indexSlide);
                            }
                            else if ((indexSlide == totalSlide - 2)) {
                                var modelSlide = self.model.get('slides').at(indexSlide),
                                    modelLast = self.model.get('slides').at(indexSlide + 1);
                                if (checkEmpty(modelSlide) && checkEmpty(modelLast)) {
                                    self.removeSlide(indexSlide + 1);
                                    self.goToSlide(indexSlide);
                                }
                            }
                        }
                    }
                    function checkEmpty(model) {
                        var flagEmpty = true;
                        model.get('content').each(function (col, idCol) {
                            if (col.get('items').length) {
                                flagEmpty = false;
                                return flagEmpty;
                            }
                        });
                        return flagEmpty;
                    }
                });
            }

            // user click button add or remove slide
            var queryCustom = '>.awe-carousel >.awe-carousel-content >.owl-wrapper-outer >.owl-wrapper >.owl-item >.awe-carousel-slide >.custom-carousel';
            this.$el.delegate(queryCustom + ' .awe-carousel-new-insert', 'click', function (event) {
                var $slide = $(event.target).closest('.owl-item'),
                    index = $slide.index();
                self.addSlide(index + 1);
            });
            this.$el.delegate(queryCustom + ' .awe-carousel-delete', 'click', function (event) {
                var $slide = $(event.target).closest('.owl-item'),
                    index = $slide.index();
                if ($slide.siblings('.owl-item').length > 1)
                    self.removeSlide(index);
            });
            // Event resize
            self.$el.bind('resize', function () {
                self.reInit();
            });
        },
        renderItemContent: function(){
            var self = this,
                $carousel = $('<div class="awe-item awe-carousel"><div class="awe-carousel-content"></div><div class="awe-carousel-control"></div></div>'),
                settings = self.model.toJSON();
            self.$carousel = $carousel;
            self.$content = $('.awe-carousel-content', $carousel);
            self.$control = $('.awe-carousel-control', $carousel).append(self.htmlControl());

            // Setting option for ownCarousel
            self.stOwnCarousel = {
                items: settings.items,
                itemsDesktop : [1199, settings.items],
                itemsDesktopSmall: [979, settings.itemsDesktopSmall],
                itemsTablet: [768, settings.itemsTablet],
                itemsMobile: [479, settings.itemsMobile],
                autoPlay: false,
                stopOnHover: settings.stopOnHover ? true : false,
                navigation: settings.navigation ? true : false,
                pagination: settings.pagination ? true : false,
                navigationText: ["<i class='icon fontello icon-angle-left'></i>","<i class='icon fontello icon-angle-right'></i>"],
                mouseDrag: false,// settings.mouseDrag ?  true : false
                touchDrag: false, // settings.touchDrag ? true : false
                addClassActive: 'active',
                transitionStyle: settings.effect
            };
            if (settings.navigation) {
                $carousel.addClass(settings.navigationStyle);
            }
            // Add Slide for Carousel
            self.model.get('slides').each(function(slide, idSlide){
                self.$content.append(slide.createView());
            });
            self.$carousel
                .attr({
                    'id' : settings.customID
                })
                .addClass(settings.customClass)
                .renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            self.$carousel.renderItemDefaultBoxModel(settings.boxModelSettings);
            if (settings.customEnableAnimations) {
                var animation = settings.customDataAnimations;
                self.$carousel.processAnimations(animation)
            }
            self.$el.defaultResponsive(settings);
            // Set Owncarousel
            self.iframeJQuery(self.el).delegate('> .awe-carousel', "itemReady", function() {
                self.refreshColumn();
//                self.ownCaurousel = self.iframeJQuery('> .awe-carousel-content', this).owlCarousel(self.stOwnCarousel);
            });
            // Add owlCarousel library
            AWEContent.Library.addLibrary('owlCarousel', function() {
                var interval = setInterval(function() {
                    if ($('.awe-carousel', self.el).length) {
                        clearInterval(interval);
                        self.ownCaurousel = self.iframeJQuery('> .awe-carousel > .awe-carousel-content', self.el).owlCarousel(self.stOwnCarousel);
                    }
                }, 50);
            });
            return $carousel;
        },
        reInit: function(){
            var self = this;
            self.ownCaurousel.data('owlCarousel').reinit(self.stOwnCarousel);
        },
        nextSlide: function () {
            this.ownCaurousel.data('owlCarousel').next();
        },
        prevSlide: function () {
            this.ownCaurousel.data('owlCarousel').prev();
        },
        goToSlide: function (index) {
            this.ownCaurousel.data('owlCarousel').goTo(index);
        },
        applySettingsChanged: function(model){
            var self = this,
                settings = model.toJSON();

            $.each(model.changed, function(key, value){
                self.$el.changeResponsive(key, value);
                self.$carousel.renderChangeSettingBoxModel(key, value, model);
                switch (key) {
                    case 'items':
                        self.stOwnCarousel.items = value;
                        self.reInit();
                        break;
                    case 'itemsResponsive':
                        $.extend(self.stOwnCarousel, {
                            itemsDesktop : 4,
                            itemsDesktopSmall: 3,
                            itemsTablet: 2,
                            itemsMobile: 1
                        });
                        break;
                    case 'itemsDesktopSmall':
                        self.stOwnCarousel.itemsDesktopSmall = settings.itemsDesktopSmall ;
                        break;
                    case 'itemsTablet':
                        self.stOwnCarousel.itemsTablet = settings.itemsTablet;
                        break;
                    case 'itemsMobile':
                        self.stOwnCarousel.itemsMobile= settings.itemsMobile;
                        break;
                    case 'autoPlay':
                    case 'timeAutoPlay':
                        if (settings.autoPlay){
                            self.stOwnCarousel.autoPlay = settings.timeAutoPlay *1000
                        }
                        else {
                            self.stOwnCarousel.autoPlay = false;
                        }
                        //self.reInit();
                        break;
                    case 'stopOnHover':
                        self.stOwnCarousel.stopOnHover = settings.stopOnHover ? true : false;
                        self.reInit();
                        break;
                    case 'navigation':
                        self.stOwnCarousel.navigation = settings.navigation ? true : false;
                        self.reInit();
                        break;
                    case 'navigationStyle':
                        var prevNavStyle = model.previousAttributes().navigationStyle;
                        self.$carousel.removeClass(prevNavStyle).addClass(settings.navigationStyle);
                        break;
                    case 'pagination':
                        self.stOwnCarousel.pagination = settings.pagination ? true : false;
                        self.reInit();
                        break;
                    case 'paginationStyle':
                        var prevPagStyle = model.previousAttributes().paginationStyle;
                        self.$carousel.removeClass(prevPagStyle).addClass(settings.paginationStyle);
                        break;
//                    case 'mouseDrag':
//                        self.stOwnCarousel.mouseDrag = settings.mouseDrag ? true : false;
//                        self.reInit();
//                        break;
//                    case 'touchDrag':
//                        self.stOwnCarousel.touchDrag = settings.touchDrag ? true : false;
//                        self.reInit();
//                        break;
                    case 'effect':
                        self.stOwnCarousel.transitionStyle = settings.effect;
                        self.reInit();
                        break;
                    case 'customID':
                        self.$carousel.attr('id', value); break;
                    case 'customClass':
                        var prevClass = model.previousAttributes().customClass;
                        self.$carousel.removeClass(prevClass).addClass(value); break;
                    case 'customEnableAttributes':
                        self.$carousel.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        self.$carousel.renderChangeSettingsAttributes(key, value);
                        break;
                    case 'customEnableAnimations':
                    case 'customDataAnimations':
                        var animation = value,
                            prevAnimation = self.model.previousAttributes().customDataAnimations;
                        self.$carousel.processAnimations(animation, prevAnimation);
                        break;
                    case 'previewAnimations' :
                        if (value) {
                            var animation = settings.customDataAnimations,
                                prevAnimation = self.model.previousAttributes().customDataAnimations;
                            self.model.set('previewAnimations', 0);
                            self.$carousel.processAnimations(animation, prevAnimation);
                        }
                        break;
                }
            })
        },
        refreshColumn: function(){
            var self = this;
            AWEContent.Panels.toolbarPanel.updateSortableColumn();
        },
        addSlide: function(index){
            var self = this,
                boxModelColumn = new AWEContent.Models.BoxModelSettings(),
                column = new AWEContent.Models.Column({
                    items : new AWEContent.Collections.ListItem(),
                    settings: new AWEContent.Models.ColumnSettings({boxModelSettings: boxModelColumn}),
                    classes: new AWEContent.Models.BootstrapGrid()
                }),
                listColumn = new AWEContent.Collections.ListColumn([column]),
                newModel = new AWEContent.Models.CarouselSlide({ content: listColumn}),
                $view = newModel.createView();
            self.model.get('slides').add(newModel, {at : index});
            self.ownCaurousel.data('owlCarousel').addItem($view, index);
            self.refreshColumn();
        },
        removeSlide: function(index){
            var self = this,
                modelSlide = self.model.get('slides').at(index);
            self.ownCaurousel.data('owlCarousel').removeItem(index);
            self.model.get('slides').remove(modelSlide, {at : index});
            modelSlide.destroy();
            self.refreshColumn();
        }
    });
    AWEContent.Views.CarouselItemController = AWEContent.Views.ItemController.extend({
        machineName: 'carousel',
        controllerHtml: function(){
            return '<div class="title-icon">Carousel Slider</div><i class="ic ac-icon-slideshow"></i>';
        },
        createItemModel: function(templateData){
            var boxModelColumn = new AWEContent.Models.BoxModelSettings(),
                column = new AWEContent.Models.Column({
                    items : new AWEContent.Collections.ListItem(),
                    settings: new AWEContent.Models.ColumnSettings({boxModelSettings: boxModelColumn}),
                    classes: new AWEContent.Models.BootstrapGrid()
                }),
                carouselSlide = new AWEContent.Models.CarouselSlide({ content: new AWEContent.Collections.ListColumn([column])}),
                modelCarouselItem;
            if (templateData != undefined){
                var slides = new AWEContent.Collections.ListCarousel();
                $.each(templateData.slides, function(index, slide){
                    var columns = new AWEContent.Collections.ListColumn();
                    $.each(slide.content, function(indexColumn, columnData){
                        var columnModel = AWEContent.createColumnFromTemplate(columnData);
                        columns.add(columnModel);
                    });
                    slide.content = columns;
                    slides.add(new AWEContent.Models.CarouselSlide(slide));
                });
                templateData.slides = slides;
                modelCarouselItem = new AWEContent.Models.CarouselItem(templateData);
                var lastSlide = modelCarouselItem.get('slides').at(modelCarouselItem.get('slides').length - 1),
                    flagNull = true;
                lastSlide.get('content').each( function (modelCol, idCol) {
                    if (modelCol.get('items').length > 0) {
                        flagNull = false;
                        return false;
                    }
                });
                if (!flagNull) {
                    modelCarouselItem.get('slides').add(carouselSlide);
                }
                return modelCarouselItem;
            }
            modelCarouselItem = new AWEContent.Models.CarouselItem({slides: new AWEContent.Collections.ListCarousel([carouselSlide])});
            return modelCarouselItem;
        }
    });
    AWEContent.Views.CarouselPanel = AWEContent.Views.ItemPanel.extend({
        tagName: 'div',
        className: 'awe-obj-panel panel-carousel',
        panelName: 'carousel',
        initPanel: function(){
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;
            $('#carousel-items', self.el).change(function(event, values){
                self.editingModel.set('items', values.value);
                if (values.value == 1) {
                    $('#carousel-effect', self.el).css('display', '');
                }
                else {
                    $('#carousel-effect', self.el).hide();
                }
            });
            $('#carousel-items-responsive input', self.el).change(function(event, isPanel){
                var responsive =  parseInt($(this).val());
                if (!isPanel){
                    self.editingModel.set('itemsResponsive',responsive);
                }
                if (responsive) {
                    $('#carousel-items-desktop, #carousel-items-desktop-small, #carousel-items-tablet, #carousel-items-mobile', self.el).css('display', '');
                }
                else {
                    $('#carousel-items-desktop, #carousel-items-desktop-small, #carousel-items-tablet, #carousel-items-mobile', self.el).hide();
                }
            });
            $('#carousel-items-desktop-small', self.el).change(function(event, values){
                self.editingModel.set('itemsDesktopSmall', values.value);
            });
            $('#carousel-items-tablet', self.el).change(function(event, values){
                self.editingModel.set('itemsTablet', values.value);
            });
            $('#carousel-items-mobile', self.el).change(function(event, values){
                self.editingModel.set('itemsMobile', values.value);
            });
            $('#carousel-effect', self.el).change( function(event, values){
                self.editingModel.set('effect', values.value);
            });
            $('#carousel-auto-play input', self.el).change(function(event, isPanel){
                var auto =  parseInt($(this).val());
                if (!isPanel){
                    self.editingModel.set('autoPlay',auto);
                }
                if (auto) {
                    $('#carousel-time-auto-play, #carousel-stop-on-hover', self.el).css('display', '');
                }
                else {
                    $('#carousel-time-auto-play, #carousel-stop-on-hover', self.el).hide();
                }
            });
            $('#carousel-time-auto-play', self.el).change(function(event, values){
                self.editingModel.set('timeAutoPlay', values.value);
            });
            $('#carousel-stop-on-hover input', self.el).change(function(event, isPanel){
                if (!isPanel){
                    self.editingModel.set('stopOnHover',parseInt($(this).val()));
                }
            });
            $('#carousel-navigation input', self.el).change(function(event, isPanel){
                var enable = parseInt($(this).val());
                if (!isPanel){
                    self.editingModel.set('navigation',enable);
                }
                if (enable) {
                    $('#carousel-navigation-style', self.el).css('display', '');
                }
                else {
                    $('#carousel-navigation-style', self.el).hide();
                }
            });
            $('#carousel-navigation-style', self.el).change( function(event, values){
                self.editingModel.set('navigationStyle', values.value);
            });
            $('#carousel-pagination input', self.el).change(function(event, isPanel){
                var enable = parseInt($(this).val());
                if (!isPanel){
                    self.editingModel.set('pagination',enable);
                }
                if (enable) {
                    $('#carousel-pagination-style', self.el).css('display', '');
                }
                else {
                    $('#carousel-pagination-style', self.el).hide();
                }
            });
            $('#carousel-pagination-style', self.el).change( function(event, values){
                self.editingModel.set('paginationStyle', values.value);
            });
            $('#carousel-mouse-drag input', self.el).change(function(event, isPanel){
                if (!isPanel){
                    self.editingModel.set('mouseDrag',parseInt($(this).val()));
                }
            });
            $('#carousel-touch-drag input', self.el).change(function(event, isPanel){
                if (!isPanel){
                    self.editingModel.set('touchDrag',parseInt($(this).val()));
                }
            });
            $('#carousel-box-tab', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#text-carousel-custom-id', self.el).change( function(){
                self.editingModel.set('customID', $(this).val());
            });
            $('#text-carousel-custom-classes', self.el).change( function(){
                self.editingModel.set('customClass', $(this).val());
            });
            $('#carousel-custom-attributes', this.el).initAttributesPanel(self);
            $('#carousel-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data) {
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });
        },
        setPanelElementsValue: function () {
            var self = this,
                settings = self.editingModel.toJSON();
            $('#carousel-items', self.el).aweSlider('value', settings.items);
            $('#carousel-items-responsive input', self.el).val(settings.itemsResponsive).trigger('change', {isPanel:true});
            $('#carousel-items-desktop-small', self.el).aweSlider('value', settings.itemsDesktopSmall);
            $('#carousel-items-tablet', self.el).aweSlider('value', settings.itemsTablet);
            $('#carousel-items-mobile', self.el).aweSlider('value', settings.itemsMobile);
            $('#carousel-auto-play input', self.el).val(settings.autoPlay).trigger('change', {isPanel:true});
            $('#carousel-time-auto-play', self.el).aweSlider('value', settings.timeAutoPlay);
            $('#carousel-effect', self.el).aweSelect('value', settings.effect);
            $('#carousel-stop-on-hover input', self.el).val(settings.stopOnHover).trigger('change', {isPanel:true});
            $('#carousel-navigation input', self.el).val(settings.navigation).trigger('change', {isPanel:true});
            $('#carousel-navigation-style', self.el).aweSelect('value', settings.navigationStyle);
            $('#carousel-pagination input', self.el).val(settings.pagination).trigger('change', {isPanel:true});
            $('#carousel-pagination-style', self.el).aweSelect('value', settings.paginationStyle);
            $('#carousel-mouse-drag input', self.el).val(settings.mouseDrag).trigger('change', {isPanel:true});
            $('#carousel-touch-drag input', self.el).val(settings.touchDrag).trigger('change', {isPanel:true});
            $('#carousel-box-tab', self.el).initBoxModel(settings.boxModelSettings);
            $('#text-carousel-custom-id', self.el).val(settings.customID);
            $('#text-carousel-custom-classes', self.el).val(settings.customClass);
            $('#carousel-custom-attributes', this.el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#carousel-animations input[name=enabled_custom_animation]', this.el).val(settings.customEnableAnimations).trigger('change');
            $('#carousel-animations input[name=enabled_custom_animation]', this.el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function(){
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Slide Carousel<\/h2><\/div>"
                },
                options_carousel : {
                    type: 'section',
                    items: {
                        "type": "slider",
                        "title": "Items",
                        "values": [1, 2, 3, 4, 5, 6],
                        "default_value": 4,
                        "allow_type": true
                    },
                    items_responsive: {
                        "type": "toggle",
                        "title": "Custom Responsive",
                        "default_value": 0
                    },
                    items_desktop_small : {
                        "type": "slider",
                        "title": "Desktop Small",
                        "values": [1, 2, 3, 4, 5, 6],
                        "default_value": 4,
                        "allow_type": true
                    },
                    items_tablet: {
                        "type": "slider",
                        "title": "Tablet",
                        "values": [1, 2, 3, 4, 5, 6],
                        "default_value": 4,
                        "allow_type": true
                    },
                    items_mobile : {
                        "type": "slider",
                        "title": "Mobile",
                        "values": [1, 2, 3, 4, 5, 6],
                        "default_value": 4,
                        "allow_type": true
                    },
                    effect: {
                        type: "select",
                        title: "Effect",
                        options: {
                            "fade" : "Fade",
                            "backSlide" : "Back Slide",
                            "goDown": "Go Down",
                            "fadeUp": "Fade Up"
                        },
                        default_value: "style1"
                    },
                    auto_play: {
                        "type": "toggle",
                        "title": "Auto Play",
                        "default_value": 0
                    },
                    time_auto_play : {
                        "type": "slider",
                        "title": "Duration",
                        "values": [1, 2, 3, 4, 5, 6, 7, 8, 9 , 10],
                        "default_value": 4,
                        "unit": "s",
                        "allow_type": true
                    },
                    stop_on_hover: {
                        "type": "toggle",
                        "title": "Stop On Hover",
                        "default_value": 0
                    },
                    navigation: {
                        "type": "toggle",
                        "title": "Navigation",
                        "default_value": 0
                    },
                    navigation_style: {
                        type: "select",
                        title: "Navigation Style",
                        options: {
                            "none" : "None",
                            "nav-left" : "Right",
                            "nav-right" : "Left"
                        },
                        default_value: "style1"
                    },
                    pagination: {
                        "type": "toggle",
                        "title": "Pagination",
                        "default_value": 0
                    },
                    pagination_style : {
                        type: "select",
                        title: "Pagination Style ",
                        options: {
                            "style1" : "Style1",
                            "style2" : "Style2",
                            "style3": "Style3",
                            "style4": "Style4"
                        },
                        default_value: "style1"
                    },
                    mouse_drag: {
                        "type": "toggle",
                        "title": "Mouse Drag",
                        "default_value": 0
                    },
                    touch_drag: {
                        "type": "toggle",
                        "title": "Touch Drag",
                        "default_value": 0
                    }
                },
                'box_settings' : {
                    type: "section",
                    box_tab: {
                        type: "tabs",
                        tabs: [
                            {
                                tab_title: "Border",
                                contents: {
                                    header_border: {
                                        type: "box_border",
                                        min_value: 0,
                                        max_value: 100,
                                        default_value: 0
                                    }
                                }
                            },
                            {
                                tab_title: "Radius",
                                contents: {
                                    header_boder_radius: {
                                        type: "box_model",
                                        model_type: "border_radius",
                                        min_value: 0,
                                        max_value: 100,
                                        allow_type: true
                                    }
                                }
                            },
                            {
                                tab_title: "Padding",
                                contents: {
                                    header_padding: {
                                        type: "box_model",
                                        model_type: "padding",
                                        allow_type: true,
                                        min_value: 0,
                                        max_value: 100
                                    }
                                }
                            },
                            {
                                tab_title: "Margin",
                                contents: {
                                    header_margin: {
                                        type: "box_model",
                                        model_type: "margin",
                                        allow_type: true,
                                        min_value: 0,
                                        max_value: 100
                                    }
                                }
                            }
                        ]
                    }
                },
                'definitions' : {
                    type: "section",
                    custom_id: {
                        type: "text_field",
                        title: "ID",
                        default_value: "ID"
                    },
                    custom_classes: {
                        type: "text_field",
                        title: "Classes",
                        default_value: "className"
                    },
                    custom_attributes: {
                        type: "custom_attributes"
                    },
                    animations: {
                        type: "animations"
                    }
                }
            }
        }
    });
    $(document).ready(function() {
        AWEContent.Controllers.carousel = new AWEContent.Views.CarouselItemController();
        AWEContent.Panels.carousel = new AWEContent.Views.CarouselPanel();
    });
})(jQuery);