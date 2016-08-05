/**
 * File: awecontent-team-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for header item
     */
    AWEContent.Models.TeamItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "team",
            fid: -1,
            styleImage: 'none',
            srcImage : 'http://placehold.it/262x194',
            name: 'My name',
            position: 'My position',
			description: 'Description',
            social: '[] ', // Array Json
            hover: 0,
            enable: 0,
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
            this.view = new AWEContent.Views.TeamItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.TeamItem(cloneModel);
        }
    });

    /**
     * Define View for TeamItem
     */
    AWEContent.Views.TeamItem = AWEContent.Views.Item.extend({
        additionalEvents: {
            'hover  .teamMember' : 'hoverTeam'
        },
        teamTemplate: _.template(
			'<div class="box box-icon text-center">\
			  <a href="#" tabindex="0"><img src="<%= srcImage %>" alt=""></a>\
			  <div class="box-name">\
				<h3><%= name %></h3>\
			  </div>\
			  <p>\
				<i><%= position %></i>\
			  </p>\
			  <p class="desc"><%= description %></p>\
			  <ul class="social social-list <% if (!enable) { %> hidden <% } %>">\
				<%= social %>\
			  </ul>\
			</div>'
        ),
        socialTemplate: _.template(
          '<% _.each(socials, function(social) { %>\
                <li>\
					<a href="<%= social.link %>">\
						<i class="<%= social.icon %>"></i>\
					</a>\
				</li>\
              <% }); %>\
          '
        ),
        initialize: function(){
            AWEContent.Views.Item.prototype.initialize.call(this);
            this.listenTo(this.model.get('boxModelSettings'), 'change', this.applySettingsChanged);
        },
        renderItemContent: function() {
            var self = this,
                html = '',
                socials = [],
                socialHtml = '',
                settings = self.model.toJSON(),
                $team = $('<div class="item-team awe-item our-team-wrapper"></div>');
                /*css = {
                    'background-color' : settings.background_color,
                    'color' : settings.color
                };*/
			
			// get image URLs
            this.$el.aweImageURL({
                fid: [settings.fid],
                styles: [settings.styleImage],
                success: function(el, fid, styles, response) {
                    self.processImageURL(el, fid, styles, response);
                }
            });
			
            if (settings.social != [] ) {
                socials = JSON.parse(settings.social);
                socialHtml = self.socialTemplate({socials: socials});
            }
            html = self.teamTemplate({
                srcImage: settings.srcImage,
                name : settings.name,
                position: settings.position,
				description: settings.description,
                social: socialHtml,
				enable: settings.enable
            })
            $team
                .html(html)
                .renderItemDefaultBoxModel(settings.boxModelSettings);
            //$('.over-member', $team).css(css);
            self.iframeJQuery(this.el).delegate('.item-team', "itemReady", function() {
                var heightBefore, heightAfter;
                self.iframeJQuery(this).find(".teamMember").mouseenter(function(){
                    $(this).addClass("hover");
                })
                .mouseleave(function(){
                    if(!$(this).hasClass('active-hover')){
                        $(this).removeClass("hover");
                    }
                });
                self.initHallo(self.iframeJQuery(this).find('h3'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('i'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.desc'), heightBefore, heightAfter);
            });
            self.$el.defaultResponsive(settings);
            self.$el.attr('id', settings.customID);
            self.$el.addClass(settings.customClass);
            $team.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            if (settings.customEnableAnimations)
                $team.processAnimations(settings.customDataAnimations)
            return $team;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
                $team = $('> .item-team', self.el),
                $i = $('.icon i', self.el),
                heightBefore = self.$el.height();
            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $team.renderChangeSettingBoxModel(key, value, model);
                switch (key) {
					case 'fid' :
                        var prevFid = model.previousAttributes().fid;

                        self.$el.aweImageURL({
                            fid: [settings.fid],
                            styles: [settings.styleImage],
                            success: function(el, fid, styles, response) {
                                self.processImageURL(el, fid, styles, response);
                            }
                        });
                        break;
                    case 'styleImage':
                        var fid = self.model.get('fid');
                        if (fid > 0)
                            //AWEContent.getImageURL(fid, value, self.$el);
                            self.$el.aweImageURL({
                                fid: [settings.fid],
                                styles: [settings.styleImage],
                                success: function(el, fid, styles, response) {
                                    self.processImageURL(el, fid, styles, response);
                                }
                            });
                        break;
                    case 'enable':
                        if (!value) {
							$team.find('.social-list').addClass('hidden');
                        }
                        else {
                        	$team.find('.social-list').removeClass('hidden');
						}
                        break;
                    case 'hover':
                        if (value == 1){
                            $team.find('.teamMember').addClass('active-hover hover');
                        }
                        else{
                            $team.find('.teamMember').removeClass('active-hover hover');
                        }
                        break;
                    case 'social':
                        var socials = [];
                        if (settings.social != [] ) {
                            socials = JSON.parse(settings.social);
                            $team.find('.social-list').html(self.socialTemplate({socials: socials}));
                        }
                        break;
                    case 'customID':
                        self.$el.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        self.$el.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $team.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        $team.renderChangeSettingsAttributes(key, value);
                        break;

                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $team.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $team.processAnimations(animation, prevAnimation);
                        }

                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $team.processAnimations(animation, prevAnimation);
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
                case 'h3':
                    this.model.set('name', _html);
                    break;
                case 'i':
                    this.model.set('position', _html);
                    break;
				case '.desc':
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
                    if (heightAfter != heightBefore) {
                        self.resizeItem();
                    }
                }
            });
        },
		processImageURL: function(el, fid, styles, files) {
            var fid = this.model.get('fid'),
                style = this.model.get('styleImage'),
                fileURLs = files && files[fid]? files[fid]: null;

            if (fileURLs && fileURLs[style] !== undefined) {
                // assign image URL
                this.model.imageURL = fileURLs[style];

                // change image url src
                $('img', this.$el).attr('src', fileURLs[style]);
            }
        }
    });

    /**
     * Define view for Header Controller
     * li tag what is contained by items panel
     */
    AWEContent.Views.TeamItemController = AWEContent.Views.ItemController.extend({
        machineName: 'team',
        controllerHtml: function() {
            return '<div class="title-icon">Team</div><i class="ic ac-icon-star-outline"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.TeamItem(templateData);
            }

            return new AWEContent.Models.TeamItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.teamPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-team",
        panelName: "team",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;
            $('#team-select-image input[name=selected_media]', self.el).change(function () {
                var strFileData = $(this).val().trim(),
                    file = strFileData ? JSON.parse(strFileData) : false,
                    fileURL = file && file.file_url ? file.file_url : '',
                    fid = file && file.fid > 0 ? file.fid : -1;

                // set panel thumbnail by chose image
                $('.image-content > img', self.$el).attr('src', fileURL);

                // set model fid
                self.editingModel.set('fid', fid);
            });
			$('#team-thumb-style', this.el).change(function (event, values) {
                self.editingModel.set('styleImage', values.value);
            });
            /*$('#team-background-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('background_color', color);
            });
            $('#team-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('color', color);
            });*/
            $('#team-enable input', self.$el).change(function (event, scrollEdit) {
                if (!scrollEdit) {
                    self.editingModel.set('hover', parseInt($(this).val()));
                }
            });
            $('#team-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#team-custom-id', this.$el).change( function(){
                self.editingModel.set('customID', $(this).find('input').val());
            });
            $('#team-custom-class', this.$el).change( function(){
                self.editingModel.set('customClass', $(this).find('input').val());
            });
            $('#team-custom-attributes', this.el).initAttributesPanel(self);
            $('#team-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });

            $("#team-enable input[name=toggle_value]", this.el).change(function (event, isInitPanel) {
                var value = parseInt($(this).val());

                if (!isInitPanel)
                    self.editingModel.set("enable", value);
            });

            // Social Panel Settings
            $('#team-enable .togg-status', this.$el).click(function(event) {
                event.preventDefault();

                $(this).toggleClass("active");
                if ($(this).hasClass("active")){
                    $("input[name=toggle_value]", $(this)).val(1).trigger("change");
                    self.editingModel.set('enable', 1);
                    $(this).next('i').show();
                }
                else{
                    $("input[name=toggle_value]", $(this)).val(0).trigger("change");
                    self.editingModel.set('enable', 0);
                    $(this).next('i').hide();
                }
            });

            $('#team-enable .ac-icon-edit', this.$el).click(function(event) {
                event.preventDefault();
                AWEContent.Panels.socialPanel.editModel(self.editingModel);
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            $('#team-select-image img', self.el).attr('src', self.editingModel.imageURL == null ? 'http://placehold.it/200x200' : self.editingModel.imageURL );
            if (AWEContent.Path.imageStyleURL != '') {
                $('#team-thumb-style', self.el).aweSelect('value', settings.styleImage);
            }
			
			//Social
            if (settings.enable) {
                $('#team-enable .togg-status', self.$el).addClass('active');
                $('#team-enable i', self.$el).show()
            }
            else{
                $('#team-enable .togg-status', self.$el).removeClass('active');
                $('#team-enable i', self.$el).hide()
            }
			
            self.editingModel.set('hover', parseInt(0));
            //$('#team-enable input', self.el).val(settings.hover).trigger("change", true);
            /*$('#team-background-color', this.$el).aweColorPicker('value', settings.background_color);
            $('#team-color', this.$el).aweColorPicker('value', settings.color);*/
			$('#team-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#team-custom-id input', this.el).val(settings.customID);
            $('#team-custom-class input', this.el).val(settings.customClass);
            $('#team-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#team-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#team-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Team<\/h2><\/div>"
                },
                custom_style: {
                    'type': 'section',
                    'select_image': {
                        'type': 'button',
                        'title': 'Select Image'
                    },
                    image_style_title: {
                        type: 'markup',
                        markup: '<div class="awe-style-list-title image-style-title"><span>Image Style</span></div>'
                    },
                    'thumb_style': {
                        type: "image_style_list"
                    }
                },
                custom_social: {
                    'type': 'section',
					"enable": {
                        type: 'markup',
                        markup: '<div id="team-enable" class="aw-cus evr-change toggle-pull">\
                                    <span>Enable Social<i class="i-sign ic ac-icon-circle"></i></span>\
                                    <div class="togg-status">\
                                        <div class="butt-status"></div>\
                                        <input type="hidden" name="enabled_custom_attributes" value="0">\
                                    </div>\
                                    <i class="js-edit-animations ic ac-icon-edit"></i>\
                                </div>'
                    }
                },
                /*"custom_color": {
                    "type": "section",
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
                    "color": {
                        "type": "colorpicker",
                        "title": "Text Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    }
                },*/
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

    AWEContent.Views.SocialPanel = AWEContent.Views.DefaultPanel.extend({
        panelName: 'socialPanel',
        className: 'awe-obj-panel child-panel social-panel',
        buildPanel: function() {
            return {
                'title': {
                    type: 'markup',
                    markup: '<h2>Social</h2>'
                },
                add_form: {
                    type: 'section',
                    main: {
                        type: 'markup',
                        markup:
                        '<div class="add-data">\
                            <form>\
                                <div id="alpine-social-choose-icon" class="tab-icon" data-name-icon="ic ac-icon-help">\
                                    <div class="title-tab">\
                                        <span>Choose Icons </span><i class="ic ac-icon-help"></i>\
                                    </div>\
                                </div>\
                                <div class="aw-input">\
                                    <label for="awe-add-attr-value">Link</label>\
                                    <input type="text" placeholder="http://..." class="valdata" id="awe-link-value">\
                                </div>\
                            </form>\
                        </div>\
                        <div class="add-social-link">\
                            <button><i class="ic ac-icon-add"></i>Add Social</button>\
                        </div>'
                    }
                },
                list_links: {
                    type: 'section',
                    social_items: {
                        type: 'markup',
                        markup: '<div class="awe-social-list"></div>'
                    }
                }
            }
        },
        socialItemTemplate: _.template(
            '<div class="item-cus-data">\
                <div class="aw-norm">\
                    <i class="<%= icon %>"></i>\
                    <span class="filldata"><%= link %></span> \
                    <div class="fl-right"><span class="rem-item-data"><i class="ic ac-icon-trash"></i></span></div>\
                </div>\
            </div>'
        ),
        initPanel: function() {
            var self = this;
            AWEContent.Views.DefaultPanel.prototype.initPanel.call(this);

            $('#alpine-social-choose-icon', this.el).click( function() {
                AWEContent.Panels.listIconPanel.processIcon($(this));
            }).change( function(event, data) {
                if (data) {
                    //self.editingModel.set('nameIcon', data.nameIcon);
                    $('.title-tab > i', this).removeClass().addClass(data.nameIcon);
                    $(this).attr('data-name-icon', data.nameIcon);
                }
            });

            $('.add-social-link button', this.$el).click(function(event) {
                event.preventDefault();

                var icon = $('#alpine-social-choose-icon', self.$el).attr('data-name-icon'),
                    link = $('input#awe-link-value', self.$el).val(),
                    socialList = self.editingModel.get('social');

                if (link) {
                    $('.awe-social-list', self.$el).append(self.socialItemTemplate({icon: icon, link: link}));

                    if (socialList)
                        socialList = JSON.parse(socialList);
                    else
                        socialList = [];

                    // add social link to list
                    socialList.push({icon: icon, link: link});

                    // update value to editing model
                    self.editingModel.set('social', JSON.stringify(socialList));

                    // reset add form
                    $('input#awe-link-value', self.$el).val('');
                }
            });

            $('.awe-social-list', this.$el).delegate('.rem-item-data', 'click', function(event) {
                event.preventDefault();

                var $item = $(this).parents('.item-cus-data:first'),
                    id = $item.index(),
                    socialList = JSON.parse(self.editingModel.get('social'));

                // remove item data in social list
                socialList.splice(id, 1);
                $item.remove();

                // update data to social list
                self.editingModel.set('social', JSON.stringify(socialList));
            }).sortable({
                items: '.item-cus-data',
                axis: 'y',
                stop: function(event, ui) {
                    var socialList = [];

                    // get data of new sort list
                    $('.awe-social-list > .item-cus-data', self.$el).each(function() {
                        var icon = $('.aw-norm > i', this).attr('class'),
                            link = $('.aw-norm > span', this).text().trim();

                        socialList.push({icon: icon, link: link});
                    });

                    // update social list
                    self.editingModel.set('social', JSON.stringify(socialList));
                }
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                socialList = this.editingModel.get('social');

            if (socialList)
                socialList = JSON.parse(socialList);
            else
                socialList = [];

            // render list social item
            $('.awe-social-list', this.$el).html('');
            $.each(socialList, function() {
                $('.awe-social-list', self.$el).append(self.socialItemTemplate(this));
            });
        }
    });

    $(document).ready(function() {
        AWEContent.Controllers.team = new AWEContent.Views.TeamItemController();
        AWEContent.Panels.team = new AWEContent.Views.teamPanel();
        AWEContent.Panels.socialPanel = new AWEContent.Views.SocialPanel();
    });
})(jQuery);
