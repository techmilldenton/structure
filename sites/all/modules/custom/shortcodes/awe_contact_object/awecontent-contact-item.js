/**
 * File: awecontent-contact-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for Contact item
     */
    AWEContent.Models.ContactItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "contact",
			icon: 'icon-help-circled',
            title: 'This is title',
            background_color: '',
            titleColor:'',
			iconColor:'',
            hover_color : '',
            fontSizeTitle:-1,
            lineHeightTitle:-1,
            letterSpacingTitle:-1,
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
            this.view = new AWEContent.Views.ContactItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.ContactItem(cloneModel);
        }
    });

    /**
     * Define View for Contact Item
     */
    AWEContent.Views.ContactItem = AWEContent.Views.Item.extend({
        contactTemplate: _.template(
			'<p class="contact-info"><i class="icon <%= classIcon %>"></i><span><%= title %></span></p>'
        ),
        initialize: function(){
            AWEContent.Views.Item.prototype.initialize.call(this);
            this.listenTo(this.model.get('boxModelSettings'), 'change', this.applySettingsChanged);
        },
        renderItemContent: function() {
            var self = this,
                settings = self.model.toJSON(),
                $contact = $('<div class="ts-contact awe-item"></div>'),
                css = {
                    'background-color' : settings.background_color,
                },
                fontCssTitle = {
                    'font-size' : settings.fontSizeTitle == -1 ? '' : (settings.fontSizeTitle + 'px'),
                    'line-height' : settings.lineHeightTitle == -1 ? '' : (settings.lineHeightTitle + 'px'),
                    'letter-spacing' : settings.letterSpacingTitle == -1 ? ''  : (settings.letterSpacingTitle + 'px'),
                    'font-family': settings.fontFamilyTitle,
                    'color':settings.titleColor
                };
            $contact.css(css);
            $contact.attr({'id' : settings.customID}).addClass(settings.customClass).renderItemDefaultBoxModel(settings.boxModelSettings);
            //self.$el.append(this.contactStyle({cid : self.model.cid, color : settings.hover_color}));
            $contact.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $contact.html(self.contactTemplate({classIcon: settings.icon, title : settings.title}));
            self.iframeJQuery(this.el).delegate('.ts-contact', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('span'), heightBefore, heightAfter);
            });
            self.$el.defaultResponsive(settings);
            $contact.find('span').css(fontCssTitle);
			$contact.find('i').css('color', settings.iconColor);
			if (settings.fontStyleTitle) {
			  $contact.append('<style>.ts-contact span ' + settings.fontStyleTitle.split(",")[0].replace('"font-weight"', 'font-weight') + '}</style>');
			}
            return $contact;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
                $contact = $('> .ts-contact', self.el),
				$i = $('.icon', self.el),
                heightBefore = self.$el.height(),$contact_title;
            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $contact.renderChangeSettingBoxModel(key, value, model);
                $contact_title = $contact.find('span');
                switch (key) {
					case 'icon' :
                        var prevIcon = self.model.previousAttributes().icon;
                        $i.removeClass(prevIcon).addClass(value);
                        break;
                    case 'titleColor' :
                        $contact_title.css('color', value);
                        break;
					case 'iconColor' :
                        $contact.find('i').css('color', value);
                        break;
                    case 'background_color' :
                        $contact.css('background-color', value);
                        break;
                    case 'hover_color' :
                        self.generateStyle();
                        break;
                  	
                    case 'fontFamilyTitle':
                        $contact_title.css('font-family', value);
                        break;

                    case 'fontStyleTitle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $contact_title.css(fontStyle);
                        break;

                    case 'fontSizeTitle':
                        value == -1 ? $contact_title.css('font-size', '') : $contact_title.css('font-size', value + 'px');
                        break;

                    case 'lineHeightTitle' :
                        value == -1 ? $contact_title.css('line-height', '') : $contact_title.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingTitle':
                        value == -1 ? $contact_title.css('letter-spacing', '') : $contact_title.css('letter-spacing', value + 'px');
                        break;
                    case 'customID':
                        $contact.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        $contact.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $contact.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;

                    case 'customActionAttributes':
                        $contact.renderChangeSettingsAttributes(key, value);
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
                        $contact.processAnimations(animation, prevAnimation);
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
                case 'span':
                    this.model.set('title', _html);
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
        generateStyle: function() {
            var self = this,
                settings = this.model.toJSON();

            if (self.updateColor)
                clearTimeout(self.updateColor);

            self.updateColor = setTimeout(function() {

                // update style color
                //$('style', self.$el).html(self.contactStyle({cid : self.model.cid, color : settings.hover_color}));

                // clear inline style for all color
                $('span.title-accr', self.$el).css('color', '');
                $('.ui-accordion-header', self.$el).css('background-color', '');

                // clear timeout
                self.updateColor = false;
            }, 100);
        }
    });

    /**
     * Define view for Contact Controller
     * li tag what is contained by items panel
     */
    AWEContent.Views.ContactItemController = AWEContent.Views.ItemController.extend({
        machineName: 'contact',
        controllerHtml: function() {
            return '<div class="title-icon">Contact</div><i class="ic ac-icon-star-outline"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.ContactItem(templateData);
            }

            return new AWEContent.Models.ContactItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define Contact panel
     */
    AWEContent.Views.ContactPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-contact",
        panelName: "contact",
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
            $('#contact-title-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('titleColor', color);
            });
			$('#contact-icon-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('iconColor', color);
            });
            $('#contact-background-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('background_color', color);
            });
            $('#contact-hover-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('hover_color', color);
            });

            $('#contact-font-title-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
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

            $('#contact-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#text-contact-custom-id', self.el).change( function(){
                self.editingModel.set('customID', $(this).val());
            });
            $('#text-contact-custom-class', self.el).change( function(){
                self.editingModel.set('customClass', $(this).val());
            });
            $('#contact-custom-attributes', this.el).initAttributesPanel(self);
            $('#contact-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
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
            $('#contact-hover-color', this.$el).aweColorPicker('value', settings.hover_color);
            $('#contact-background-color', this.$el).aweColorPicker('value', settings.background_color);
            $('#contact-title-color', this.$el).aweColorPicker('value', settings.titleColor);
			$('#contact-icon-color', this.$el).aweColorPicker('value', settings.iconColor);

            $('#contact-font-title-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyTitle,
                fontStyle: settings.fontStyleTitle,
                fontSize: settings.fontSizeTitle,
                textAlign: settings.textAlignTitle,
                letterSpacing: settings.letterSpacingTitle,
                lineHeight: settings.lineHeightTitle
            });
            $('#contact-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#text-contact-custom-id', this.$el).val(settings.customID);
            $('#text-contact-custom-class', this.$el).val(settings.customClass);
            $('#contact-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#contact-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#contact-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Contact<\/h2><\/div>"
                },
                "custom_color": {
                    "type": "section",
					"custom_choose_icons": {
                        "type": "tabs_icon",
                        "title": "<div class=\"title-tab\"><span>Choose Icons <\/span><i class=\"\"><\/i><\/div>",
                        "tabs": []
                    },
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
					"title_color": {
                        "type": "colorpicker",
                        "title": "Title Color",
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
                        "markup": "<div class=\"awe-title\"><h3>Title text font<\/h3><\/div>"
                    },
                    font_title_field:{
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
        AWEContent.Controllers.contact = new AWEContent.Views.ContactItemController();
        AWEContent.Panels.contact = new AWEContent.Views.ContactPanel();
    });
})(jQuery);
