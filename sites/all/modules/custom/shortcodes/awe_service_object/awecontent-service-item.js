/**
 * File: awecontent-service-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for Service item
     */
    AWEContent.Models.ServiceItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "service",
			icon: 'icon-help-circled',
            title: 'Heading',
            description: 'This is description',
			style: 'style-1',
			textTransform: 'none',
			buttonText: 'READ MORE',
			buttonUrl: '',
			buttonTarget:'',
            background_color: '',
            iconColor:'',
			iconBgColor:'',
			titleColor:'',
            sdescriptionColor:'',
			buttonColor: '',
			buttonHoverColor: '',
            hover_color : '',
            fontSizeTitle:-1,
            lineHeightTitle:-1,
            letterSpacingTitle:0,
            fontSizeDescription:-1,
            lineHeightDescription:-1,
            letterSpacingDescription:0,
            boxModelSettings : {},
            customID : '',
            customClass : '',
            customEnableAttributes: 0,
            customDataAttributes: '[] ', // Array Json
            customActionAttributes: '{"newAction": "", "newAttrName": "", "newAttrValue": ""}',
            customEnableAnimations: 0,
            customDataAnimations: '{"type" : "none"}', // Data Object
            lgResponsive: true,
            xsResponsive: true,
            mediumResponsive: true,
            smResponsive: true
        },
        relations: [
            {
                type: Backbone.HasOne,
                key: "boxModelSettings",
                relatedModel: AWEContent.Models.BoxModelSettings
            }
        ],
        createView: function() {
            this.view = new AWEContent.Views.ServiceItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.ServiceItem(cloneModel);
        }
    });

    /**
     * Define View for Service Item
     */
    AWEContent.Views.ServiceItem = AWEContent.Views.Item.extend({
        serviceTemplate: _.template(
            '<div class="service-item s-1 box-icon text-center mb-30 <% if (style!="style-1") { %> hidden <% } %>">\
				<div class="box-image">\
				  <span><i class="<%= classIcon %> service-icon"></i></span>\
				</div>\
				<div class="box-name">\
				  <h3 class="<%= textTransform %> title" data-object="title" data-style="<%= textTransform %>"><%= title %></h3>\
				</div>\
				<p data-object="desc"><%= description %></p>\
			 </div>\
			 <div class="service-item s-2 box box3 text-center <% if (style!="style-2") { %> hidden <% } %>">\
				<div class="box-image">\
				  <span><i class="<%= classIcon %> service-icon"></i></span>\
				</div>\
				<div class="box-content">\
				  <div class="box-name"><a href="#" class="ts-button"><h4 class="<%= textTransform %> title" data-style="<%= textTransform %>" data-object="title"><%= title %></h4></a></div>\
				  <p data-object="desc"><%= description %></p>\
				  <a href="#" class="ts-button btn-base btn-effect text-uppercase mt-10"><%= buttonText %></a>\
				</div>\
			 </div>\
			 <div class="service-item s-3 box-icon box3 box-icon5 text-center <% if (style!="style-3") { %> hidden <% } %>">\
				<div class="box-image">\
				  <span><i class="<%= classIcon %> service-icon"></i></span>\
				</div>\
				<br>\
				<div class="box-name">\
				  <h3 class="bold mt-0 mb-0 <%= textTransform %> title" data-style="<%= textTransform %>" data-object="title"><%= title %></h3>\
				</div>\
				<p data-object="desc"><%= description %></p>\
			 </div>\
			 <div class="service-item s-4 media box box-media box-icon box-icon2 <% if (style!="style-4") { %> hidden <% } %>">\
				<div class="pull-left box-image">\
				  <span><i class="<%= classIcon %> service-icon"></i></span>\
				</div>\
				<div class="media-body">\
				  <div class="box-name pt-0">\
					<a href="#"><h4 class="<%= textTransform %> title" data-style="<%= textTransform %>" data-object="title"><%= title %></h4></a>\
				  </div>\
				  <p data-object="desc"><%= description %></p>\
				</div>\
			 </div>'
        ),
        serviceStyle: _.template(
            '<style>\
            .awe-model-<%= cid %> .ts-service:hover{\
                background-color: <%= color %> !important;\
            }\
            </style>'
        ),
        initialize: function(){
            AWEContent.Views.Item.prototype.initialize.call(this);
            this.listenTo(this.model.get('boxModelSettings'), 'change', this.applySettingsChanged);
        },
        renderItemContent: function() {
            var self = this,
                settings = self.model.toJSON(),
                $service = $('<div class="ts-service awe-item"></div>'),
                css = {
                    'background-color' : settings.background_color,
                },
                fontCssTitle = {
                    'font-size' : settings.fontSizeTitle == -1 ? '' : (settings.fontSizeTitle + 'px'),
                    'line-height' : settings.lineHeightTitle == -1 ? '' : (settings.lineHeightTitle + 'px'),
                    'letter-spacing' : settings.letterSpacingTitle == -1 ? ''  : (settings.letterSpacingTitle + 'px'),
                    'font-family': settings.fontFamilyTitle,
                    'color':settings.titleColor
                },
                fontCssDescription = {
                    'font-size' : settings.fontSizeDescription == -1 ? '' : (settings.fontSizeDescription + 'px'),
                    'line-height' : settings.lineHeightDescription == -1 ? '' : (settings.lineHeightDescription + 'px'),
                    'letter-spacing' : settings.letterSpacingDescription == -1 ? ''  : (settings.letterSpacingDescription + 'px'),
                    'font-family': settings.fontFamilyDescription,
                    'color':settings.sdescriptionColor
                };
            $service.css(css);
            $service.attr({'id' : settings.customID}).addClass(settings.customClass).renderItemDefaultBoxModel(settings.boxModelSettings);
            self.$el.append(this.serviceStyle({cid : self.model.cid, color : settings.hover_color}));
            $service.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $service.html(self.serviceTemplate({classIcon: settings.icon, description : settings.description, title: settings.title, textTransform: settings.textTransform, style: settings.style, buttonText: settings.buttonText}));
            self.iframeJQuery(this.el).delegate('.ts-service', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('.title'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('p'), heightBefore, heightAfter);
				self.initHallo(self.iframeJQuery(this).find('.btn-base'), heightBefore, heightAfter);
            });
            self.$el.defaultResponsive(settings);
            $service.find('.title').css(fontCssTitle);
            $service.find('p').css(fontCssDescription);
			$service.find('i').css('color', settings.iconColor);
			$service.find('.s-4 .box-image').css('background-color', settings.iconBgColor);
			$service.find('.box-image').css('border-color', settings.iconColor);
			$service.find('.btn-base').css('color', settings.buttonColor);
			$service.append('<style>.ts-service .btn-base:before {border-color: ' + settings.buttonColor + ';}</style>');
			$service.append('<style>.ts-service .btn-base:hover {color: ' + settings.buttonHoverColor + ' !important;} .ts-service .btn-base:after {border-color: ' + settings.buttonHoverColor + ';}</style>');
			if(settings.buttonUrl!='')
                $service.find('.ts-button').attr('href',settings.buttonUrl);
            else
                $service.find('.ts-button').attr('href','#');
            if(settings.buttonTarget!='')
                $service.find('.ts-button').attr('target',settings.buttonTarget);
            return $service;
        },
        applySettingsChanged: function(model) {
            var self = this,
				style= "",
                settings = self.model.toJSON(),
                $service = $('> .ts-service', self.el),
				$i = $('.service-icon', self.el),
                heightBefore = self.$el.height(),$service_title, $service_description;
            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $service.renderChangeSettingBoxModel(key, value, model);
                $service_title = $service.find('.title');
                $service_description = $service.find('p');
                switch (key) {
                    case 'icon' :
                        var prevIcon = self.model.previousAttributes().icon;
                        $i.removeClass(prevIcon).addClass(value);
                        break;
					case 'style':
						if(value == "style-1") {
							$service.find('.service-item').addClass('hidden');
							$service.find('.s-1').removeClass('hidden');
						} 
						if (value == "style-2") {
							$service.find('.service-item').addClass('hidden');
							$service.find('.s-2').removeClass('hidden');
						}
						if (value == "style-3") {
							$service.find('.service-item').addClass('hidden');
							$service.find('.s-3').removeClass('hidden');
						}
						if (value == "style-4") {
							$service.find('.service-item').addClass('hidden');
							$service.find('.s-4').removeClass('hidden');
						}
                        break;
					case 'textTransform':
						style = $service.find('.title').attr('data-style');
						$service.find('.title').removeClass(style);
						$service.find('.title').addClass(value);
						$service.find('.title').attr('data-style', value);
                        break;
					case 'buttonUrl':
                        if(value!='')
                            $service.find('.ts-button').attr('href',value);
                        else
                            $service.find('.ts-button').attr('href','#');
                        break;
                    case 'buttonTarget':
                        $service.find('.ts-button').attr('target',settings.buttonTarget);
                        break;
					case 'iconColor' :
                        $service.find('i').css('color', value);
						$service.find('.box-image').css('border-color', value);
                        break;
					case 'iconBgColor' :
                        $service.find('.s-4 .box-image').css('background-color', value);
                        break;
					case 'titleColor' :
                        $service_title.css('color', value);
                        break;
                    case 'sdescriptionColor' :
                        $service_description.css('color', value);
                        break;
					case 'buttonColor' :
						$service.find('.btn-base').css('color', value);
						if(value == "") value = "inherit";
						$service.append('<style>.ts-service .btn-base:before {border-color: ' + value + ';}</style>');
                        break;
					case 'buttonHoverColor' :
						if(value == "") value = "inherit";
						$service.append('<style>.ts-service .btn-base:hover {color: ' + value + ' !important;} .ts-service .btn-base:after {border-color: ' + value + ';}</style>');
                        break;
                    case 'background_color' :
                        $service.css('background-color', value);
                        break;
                    case 'hover_color' :
                        self.generateStyle();
                        break;
                    case 'fontFamilyTitle':
                        $service_title.css('font-family', value);
                        break;

                    case 'fontStyleTitle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $service_title.css(fontStyle);
                        break;

                    case 'fontSizeTitle':
                        value == -1 ? $service_title.css('font-size', '') : $service_title.css('font-size', value + 'px');
                        break;

                    case 'lineHeightTitle' :
                        value == -1 ? $service_title.css('line-height', '') : $service_title.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingTitle':
                        value == -1 ? $service_title.css('letter-spacing', '') : $service_title.css('letter-spacing', value + 'px');
                        break;
                    case 'fontFamilyDescription':
                        $service_description.css('font-family', value);
                        break;

                    case 'fontStyleDescription':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $service_description.css(fontStyle);
                        break;

                    case 'fontSizeDescription':
                        value == -1 ? $service_description.css('font-size', '') : $service_description.css('font-size', value + 'px');
                        break;

                    case 'lineHeightDescription' :
                        value == -1 ? $service_description.css('line-height', '') : $service_description.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingDescription':
                        value == -1 ? $service_description.css('letter-spacing', '') : $service_description.css('letter-spacing', value + 'px');
                        break;
                    case 'customID':
                        $service.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        $service.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $service.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;

                    case 'customActionAttributes':
                        $service.renderChangeSettingsAttributes(key, value);
                        break;

                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $message.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $message.processAnimations(animation, prevAnimation);
                        }

                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $service.processAnimations(animation, prevAnimation);
                        break;
                }
            });

            // Listen event change height of item
            setTimeout(function() {
                self.checkChangeHeight(heightBefore);
            }, 50);
        },
        changeContent: function(el, select){
            var _html = $(el.currentTarget).html();
            switch (select.selector) {
                case '.title':
                    this.model.set('title', _html);
                    break;
				case '.btn-base':
                    this.model.set('buttonText', _html);
                    break;
                case 'p':
                    this.model.set('description', _html);
                    break;
            }
        },
        initHallo: function(select, heightBefore, heightAfter) {
            var self = this;
            select.hallo({
                plugins: {
                    halloformat: {
                        formattings: {
                            bold: true,
                            italic: true,
                            underline: true,
                            strikethrough: true
                        }
                    },
                    hallojustify: {},
                    hallolists: {
                        lists: {
                            ordered: true,
                            unordered: true
                        }
                    }
                },
                create : function(){
                    this.addEventListener("paste", function(e) {
                        e.preventDefault();
                        var text = e.clipboardData.getData("text/plain");
                        AWEContent.documentIframe.execCommand("insertHTML", false, text);

                    });
                },
                editable: true,
                activate: function (event) {
                    heightBefore = $(event.target).height();
                },
                deactivated: function(event) {
                    self.changeContent(event, select);
                    heightAfter = $(event.target).height();
					if($(event.target).attr('data-object') == "title") {
						$('> .ts-service', self.el).find('.title').text($(event.target).text());
					}
					if($(event.target).attr('data-object') == "desc") {
						$('> .ts-service', self.el).find('p').html($(event.target).html());
					}
                    if (heightAfter != heightBefore) {
                        self.resizeItem();
                    }
                }
            });
        },
        generateStyle: function() {
            var self = this,
                settings = this.model.toJSON();

            if (self.updateColor)
                clearTimeout(self.updateColor);

            self.updateColor = setTimeout(function() {

                // update style color
                $('style', self.$el).html(self.serviceStyle({cid : self.model.cid, color : settings.hover_color}));

                // clear inline style for all color
                $('span.title-accr', self.$el).css('color', '');
                $('.ui-accordion-header', self.$el).css('background-color', '');

                // clear timeout
                self.updateColor = false;
            }, 100);
        }
    });

    /**
     * Define view for Service Controller
     * li tag what is contained by items panel
     */
    AWEContent.Views.ServiceItemController = AWEContent.Views.ItemController.extend({
        machineName: 'service',
        controllerHtml: function() {
            return '<div class="title-icon">Service</div><i class="ic ac-icon-star-outline"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.ServiceItem(templateData);
            }

            return new AWEContent.Models.ServiceItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define Service panel
     */
    AWEContent.Views.ServicePanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-service",
        panelName: "service",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;
            
			$('#custom-choose-icons .title-tab', self.el).click( function() {
                var $controller = $(this).closest('#custom-choose-icons');
                AWEContent.Panels.listIconPanel.processIcon($controller);
            });

            $('#custom-choose-icons', self.el).change( function(event, data) {
                if (data) {
                    self.editingModel.set('icon', data.nameIcon);
                    $('.title-tab > i', this).removeClass().addClass(data.nameIcon);
                }
            });
			
			$('#service-style', this.$el).change(function (event, values) {
				self.editingModel.set('style', values.value);
            });
			
			$('#service-texttransform', this.$el).change(function (event, values) {
				self.editingModel.set('textTransform', values.value);
            });
			
			 // for button
            $('#text-service-button-url', this.el).change(function() {
                self.editingModel.set('buttonUrl', $(this).val());
            });
            $('#service-button-target', this.el).change(function(event, values) {
                self.editingModel.set('buttonTarget', values.value);
            });
			
			$('#service-icon-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('iconColor', color);
            });
			$('#service-icon-bg-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('iconBgColor', color);
            });
			$('#service-title-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('titleColor', color);
            });
            $('#service-description-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('sdescriptionColor', color);
            });
			$('#service-button-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('buttonColor', color);
            });
			$('#service-button-hover-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('buttonHoverColor', color);
            });
            $('#service-background-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('background_color', color);
            });
            $('#service-hover-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('hover_color', color);
            });

            $('#service-font-title-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('fontFamilyTitle', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('fontStyleTitle', fontStyle.value);
            }).bind('textAlignChange', function(event, textAlign) {
                self.editingModel.set('textAlignTitle', textAlign.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('fontSizeTitle', fontSize.value);
            }).bind('letterSpacingChange', function(event, letterSpacing) {
                self.editingModel.set('letterSpacingTitle', letterSpacing.value);
            }).bind('lineHeightChange', function(event, lineHeight) {
                self.editingModel.set('lineHeightTitle', lineHeight.value);
            });

            $('#service-font-description-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('fontFamilyDescription', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('fontStyleDescription', fontStyle.value);
            }).bind('textAlignChange', function(event, textAlign) {
                self.editingModel.set('textAlignDescription', textAlign.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('fontSizeDescription', fontSize.value);
            }).bind('letterSpacingChange', function(event, letterSpacing) {
                self.editingModel.set('letterSpacingDescription', letterSpacing.value);
            }).bind('lineHeightChange', function(event, lineHeight) {
                self.editingModel.set('lineHeightDescription', lineHeight.value);
            });

            $('#service-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#text-service-custom-id', self.el).change( function(){
                self.editingModel.set('customID', $(this).val());
            });
            $('#text-service-custom-class', self.el).change( function(){
                self.editingModel.set('customClass', $(this).val());
            });
            $('#service-custom-attributes', this.el).initAttributesPanel(self);
            $('#service-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            //$('#message-style', this.$el).aweSelect('value', settings.messageType);
			$('#custom-choose-icons i', self.el).attr('class', settings.icon);
			$('#service-style', self.el).aweSelect('value', settings.style);
			$('#service-texttransform', self.el).aweSelect('value', settings.textTransform);
			$('#text-service-button-url', this.el).val(settings.buttonUrl);
            $('#service-button-target', this.el).aweSelect('value', settings.buttonTarget);
            $('#service-hover-color', this.$el).aweColorPicker('value', settings.hover_color);
            $('#service-background-color', this.$el).aweColorPicker('value', settings.background_color);
            $('#service-icon-color', this.$el).aweColorPicker('value', settings.iconColor);
			$('#service-icon-bg-color', this.$el).aweColorPicker('value', settings.iconBgColor);
			$('#service-title-color', this.$el).aweColorPicker('value', settings.titleColor);
            $('#service-description-color', this.$el).aweColorPicker('value', settings.sdescriptionColor);
			$('#service-button-color', this.$el).aweColorPicker('value', settings.buttonColor);
			$('#service-button-hover-color', this.$el).aweColorPicker('value', settings.buttonHoverColor);
            $('#service-font-title-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyTitle,
                fontStyle: settings.fontStyleTitle,
                fontSize: settings.fontSizeTitle,
                textAlign: settings.textAlignTitle,
                letterSpacing: settings.letterSpacingTitle,
                lineHeight: settings.lineHeightTitle
            });

            $('#service-font-description-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyDescription,
                fontStyle: settings.fontStyleDescription,
                fontSize: settings.fontSizeDescription,
                textAlign: settings.textAlignDescription,
                letterSpacing: settings.letterSpacingDescription,
                lineHeight: settings.lineHeightDescription
            });
            $('#service-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#text-service-custom-id', this.$el).val(settings.customID);
            $('#text-service-custom-class', this.$el).val(settings.customClass);
            $('#service-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#service-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#service-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Service<\/h2><\/div>"
                },
				"icon":{
                    "type": "section",
                    "custom_choose_icons": {
                        "type": "tabs_icon",
                        "title": "<div class=\"title-tab\"><span>Choose Icons <\/span><i class=\"\"><\/i><\/div>",
                        "tabs": []
                    },
					'style': {
						"type": "select",
						"title": "Service Style",
						"options": {
							"style-1": "Style 1",
							"style-2": "Style 2",
							"style-3": "Style 3",
							"style-4": "Style 4"
						},
						"default_value": "style-1"
					}
                },
                 "custom_feature": {
                      "type": "section",
					  "button_url": {
                        "type": "text_field",
                        "title": "Link",
                        "attributes": {
                          "placeholder": "http:\/\/..."
                        },
                        "default_value": "http:\/\/"
                      },
                      "button_target": {
                        "type": "select",
                        "title": "Target",
                        "options": {
                          "_self" : "_self",
                          "_blank": "_blank",
                          "_parent": "_parent",
                          "_top": "_top",
                        },
                        "default_value": "_self"
                      },
					  "button_color": {
                        "type": "colorpicker",
                        "title": "Button Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                     },
					 "button_hover_color": {
                        "type": "colorpicker",
                        "title": "Button Hover Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                     }
                },
                "custom_color": {
                    "type": "section",
                    "icon_color": {
                        "type": "colorpicker",
                        "title": "Icon Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
					"icon_bg_color": {
                        "type": "colorpicker",
                        "title": "Icon Background Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
					"title_color": {
                        "type": "colorpicker",
                        "title": "Heading Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "description_color": {
                        "type": "colorpicker",
                        "title": "Description Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "background_color": {
                        "type": "colorpicker",
                        "title": "Background Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "hover_color": {
                        "type": "colorpicker",
                        "title": "Background Hover",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    }
                },
                "custom_text": {
                    "type": "section",
                    "label_title_font": {
                        "type": "markup",
                        "markup": "<div class=\"awe-title\"><h3>Heading font<\/h3><\/div>"
                    },
					'texttransform': {
						"type": "select",
						"title": "Text Transform",
						"options": {
							"none": "None",
							"uppercase": "Uppercase",
							"lowercase": "Lowercase",
							"capitalize": "Capitalize"
						},
						"default_value": "none"
					},
                    font_title_field:{
                      type: "font",
                        disabledElements: ['textAlign']
                    },
                    "label_description_font": {
                        "type": "markup",
                        "markup": "<div class=\"awe-title\"><h3>Description font<\/h3><\/div>"
                    },
                    font_description_field:{
                      type: "font",
                        disabledElements: ['textAlign']
                    }
                },
                "custom_box_model": {
                    "type": "section",
                    "column_box_model": {
                        "type": "tabs",
                        "tabs": [{
                            "tab_title": "Border",
                            "contents": {
                                "custom_border": {
                                    "type": "box_border",
                                    "min_value": 0,
                                    "max_value": 100,
                                    "default_value": 0
                                }
                            }
                        }, {
                            "tab_title": "Radius",
                            "contents": {
                                "custom_border_radius": {
                                    "type": "box_model",
                                    "model_type": "border_radius",
                                    allow_type: true,
                                    "min_value": 0,
                                    "max_value": 100,
                                    "default_value": 0
                                }
                            }
                        }, {
                            "tab_title": "Padding",
                            "contents": {
                                "custom_padding": {
                                    "type": "box_model",
                                    "model_type": "padding",
                                    allow_type: true,
                                    "min_value": 0,
                                    "max_value": 100,
                                    "default_value": 0
                                }
                            }
                        }, {
                            "tab_title": "Margin",
                            "contents": {
                                "custom_margin": {
                                    "type": "box_model",
                                    "model_type": "margin",
                                    allow_type: true,
                                    "min_value": 0,
                                    "max_value": 100,
                                    "default_value": 0
                                }
                            }
                        }]
                    }
                },
                "custom_definitions": {
                    "type": "section",
                    "custom_id": {
                        "type": "text_field",
                        "title": "ID",
                        "attributes": {
                            "placeholder": "wrapper"
                        },
                        "default_value": ""
                    },
                    "custom_class": {
                        "type": "text_field",
                        "title": "CSS class",
                        "attributes": {
                            "placeholder": "wrapper"
                        },
                        "default_value": ""
                    },
                    "custom_attributes": {
                        "type": "custom_attributes"
                    },
                    animations: {
                        type: "animations"
                    }
                }
            };
        }
    });

    $(document).ready(function() {
        AWEContent.Controllers.service = new AWEContent.Views.ServiceItemController();
        AWEContent.Panels.service = new AWEContent.Views.ServicePanel();
    });
})(jQuery);
