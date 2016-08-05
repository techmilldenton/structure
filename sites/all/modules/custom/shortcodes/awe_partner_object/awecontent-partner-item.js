/**
 * File: awecontent-partner-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for header item
     */
    AWEContent.Models.PartnerItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "partner",
			icon: 'icon-help-circled',
			title: 'Title',
			description: 'Description',
			title_color: '',
			color: '',
			iconColor:'',
			iconHoverColor:'',
			textTransform: 'none',
			fontSizeTitle:-1,
            lineHeightTitle:-1,
            letterSpacingTitle:-1,
            fontSizeDesc:-1,
            lineHeightDesc:-1,
            letterSpacingDesc:-1,
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
            this.view = new AWEContent.Views.PartnerItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.PartnerItem(cloneModel);
        }
    });

    /**
     * Define View for PartnerItem
     */
    AWEContent.Views.PartnerItem = AWEContent.Views.Item.extend({
        partnerTemplate: _.template(
            '<div class="media box box-icon box-icon3 box-media">\
				  <div class="col-md-3 col-sm-4">\
					<div class="pull-left box-image">\
						<span><i class="<%= classIcon %>"></i></span>\
					</div>\
				  </div>\
				  <div class="col-md-9 col-sm-8">\
					<div class="media-body">\
					  <div class="box-name">\
						<h3 class="<%= textTransform %>"><%= title %></h3>\
					  </div>\
					  <p class="info-desc"><%= description %></p>\
					</div>\
				  </div>\
			  </div>'
        ),
        initialize: function(){
            AWEContent.Views.Item.prototype.initialize.call(this);
            this.listenTo(this.model.get('boxModelSettings'), 'change', this.applySettingsChanged);
        },
        renderItemContent: function() {
            var self = this,
                html = '',
                settings = self.model.toJSON(),
                $partner = $('<div class="item-partner awe-item"></div>'),
				fontCssTitle = {
                    'font-size' : settings.fontSizeTitle == -1 ? '' : (settings.fontSizeTitle + 'px'),
                    'line-height' : settings.lineHeightTitle == -1 ? '' : (settings.lineHeightTitle + 'px'),
                    'letter-spacing' : settings.letterSpacingTitle == -1 ? ''  : (settings.letterSpacingTitle + 'px'),
                    'font-family': settings.fontFamilyTitle
                },
                fontCssDesc = {
                    'font-size' : settings.fontSizeDesc == -1 ? '' : (settings.fontSizeDesc + 'px'),
                    'line-height' : settings.lineHeightDesc == -1 ? '' : (settings.lineHeightDesc + 'px'),
                    'letter-spacing' : settings.letterSpacingDesc == -1 ? ''  : (settings.letterSpacingDesc + 'px'),
                    'font-family': settings.fontFamilyDesc
                };
			
            html = self.partnerTemplate({
				title : settings.title,
				description: settings.description,
				textTransform: settings.textTransform,
				classIcon: settings.icon
            })
            $partner
                .html(html)
                .renderItemDefaultBoxModel(settings.boxModelSettings);
				
			$partner.find('h3').css('color', settings.title_color);
			$partner.find('.info-desc').css('color', settings.color);
			$partner.find('.box-icon3 .box-image').css('color', settings.iconColor);
			$partner.append('<style>.box-icon3:hover .box-image {color: ' + settings.iconHoverColor + ' !important; border-color: ' + settings.iconHoverColor + ';}</style>');
			
			self.iframeJQuery(this.el).delegate('.item-partner', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('h3'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.info-desc'), heightBefore, heightAfter);
            });
			
            self.$el.defaultResponsive(settings);
            self.$el.attr('id', settings.customID);
            self.$el.addClass(settings.customClass);
            $partner.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            if (settings.customEnableAnimations)
                $partner.processAnimations(settings.customDataAnimations)
				
			$partner.find('h3').css(fontCssTitle);
            $partner.find('.info-desc').css(fontCssDesc);
			
            return $partner;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
                $partner = $('> .item-partner', self.el),
				$i = $('.box-image i', self.el),
				$partner_title = $partner.find('h3'),
                $partner_desc = $partner.find('.info-desc'),
                heightBefore = self.$el.height();
            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $partner.renderChangeSettingBoxModel(key, value, model);
                switch (key) {
					case 'icon' :
                        var prevIcon = self.model.previousAttributes().icon;
                        $i.removeClass(prevIcon).addClass(value);
                        break;
					case 'title_color' :
                        $partner.find('h3').css('color', value);
                        break;
					case 'color' :
                        $partner.find('.info-desc').css('color', value);
                        break;
					
					case 'iconColor' :
                        $partner.find('.box-icon3 .box-image').css('color', value);
                        break;
					case 'iconHoverColor' :
                        if(value == "") value = "#FFB600";
						$partner.append('<style>.box-icon3:hover .box-image {color: ' + value + ' !important; border-color: ' + value + ';}</style>');
                        break;
						
					case 'textTransform':
						$partner.find('.box-name h3').removeAttr('class');
						$partner.find('.box-name h3').attr('class', value);
                        break;
					case 'fontFamilyTitle':
                        $partner_title.css('font-family', value);
                        break;

                    case 'fontStyleTitle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $partner_title.css(fontStyle);
                        break;

                    case 'fontSizeTitle':
                        value == -1 ? $partner_title.css('font-size', '') : $partner_title.css('font-size', value + 'px');
                        break;

                    case 'lineHeightTitle' :
                        value == -1 ? $partner_title.css('line-height', '') : $partner_title.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingTitle':
                        value == -1 ? $partner_title.css('letter-spacing', '') : $partner_title.css('letter-spacing', value + 'px');
                        break;
                    case 'fontFamilyDesc':
                        $partner_desc.css('font-family', value);
                        break;

                    case 'fontStyleDesc':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $partner_desc.css(fontStyle);
                        break;

                    case 'fontSizeDesc':
                        value == -1 ? $partner_desc.css('font-size', '') : $partner_desc.css('font-size', value + 'px');
                        break;

                    case 'lineHeightDesc' :
                        value == -1 ? $partner_desc.css('line-height', '') : $partner_desc.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingDesc':
                        value == -1 ? $partner_desc.css('letter-spacing', '') : $partner_desc.css('letter-spacing', value + 'px');
                        break;
					
					
                    case 'customID':
                        self.$el.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        self.$el.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $partner.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        $partner.renderChangeSettingsAttributes(key, value);
                        break;

                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $partner.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $partner.processAnimations(animation, prevAnimation);
                        }

                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $partner.processAnimations(animation, prevAnimation);
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
                    this.model.set('title', _html);
                    break;
                case '.info-desc':
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
        }
    });

    /**
     * Define view for Header Controller
     * li tag what is contained by items panel
     */
    AWEContent.Views.PartnerItemController = AWEContent.Views.ItemController.extend({
        machineName: 'partner',
        controllerHtml: function() {
            return '<div class="title-icon">Partner</div><i class="ic ac-icon-star-outline"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.PartnerItem(templateData);
            }

            return new AWEContent.Models.PartnerItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.partnerPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-partner",
        panelName: "partner",
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
			
			$('#partner-enable input', self.$el).change(function (event, scrollEdit) {
                if (!scrollEdit) {
                    self.editingModel.set('hover', parseInt($(this).val()));
                }
            });
            $('#partner-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#partner-custom-id', this.$el).change( function(){
                self.editingModel.set('customID', $(this).find('input').val());
            });
            $('#partner-custom-class', this.$el).change( function(){
                self.editingModel.set('customClass', $(this).find('input').val());
            });
            $('#partner-custom-attributes', this.el).initAttributesPanel(self);
            $('#partner-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });
			$('#partner-texttransform', this.$el).change(function (event, values) {
				self.editingModel.set('textTransform', values.value);
            });
			$('#partner-font-title-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
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

            $('#partner-font-desc-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('fontFamilyDesc', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('fontStyleDesc', fontStyle.value);
            }).bind('textAlignChange', function(event, textAlign) {
                self.editingModel.set('textAlignDesc', textAlign.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('fontSizeDesc', fontSize.value);
            }).bind('letterSpacingChange', function(event, letterSpacing) {
                self.editingModel.set('letterSpacingDesc', letterSpacing.value);
            }).bind('lineHeightChange', function(event, lineHeight) {
                self.editingModel.set('lineHeightDesc', lineHeight.value);
            });
			
			$('#partner-title-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('title_color', color);
            });
			$('#partner-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('color', color);
            });
			$('#partner-icon-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('iconColor', color);
            });
			$('#partner-icon-hover-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('iconHoverColor', color);
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            self.editingModel.set('hover', parseInt(0));
			$('#custom-choose-icons i', self.el).attr('class', settings.icon);
			$('#partner-texttransform', self.el).aweSelect('value', settings.textTransform);
            $('#partner-enable input', self.el).val(settings.hover).trigger("change", true);
            $('#partner-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#partner-custom-id input', this.el).val(settings.customID);
            $('#partner-custom-class input', this.el).val(settings.customClass);
            $('#partner-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#partner-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#partner-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
			
			$('#partner-font-title-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyTitle,
                fontStyle: settings.fontStyleTitle,
                fontSize: settings.fontSizeTitle,
                textAlign: settings.textAlignTitle,
                letterSpacing: settings.letterSpacingTitle,
                lineHeight: settings.lineHeightTitle
            });

            $('#partner-font-desc-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyDesc,
                fontStyle: settings.fontStyleDesc,
                fontSize: settings.fontSizeDesc,
                textAlign: settings.textAlignDesc,
                letterSpacing: settings.letterSpacingDesc,
                lineHeight: settings.lineHeightDesc
            });
			
			$('#partner-title-color', this.$el).aweColorPicker('value', settings.title_color);
			$('#partner-color', this.$el).aweColorPicker('value', settings.color);
			$('#partner-icon-color', this.$el).aweColorPicker('value', settings.iconColor);
			$('#partner-icon-hover-color', this.$el).aweColorPicker('value', settings.iconHoverColor);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Partner<\/h2><\/div>"
                },
				"icon":{
                    "type": "section",
                    "custom_choose_icons": {
                        "type": "tabs_icon",
                        "title": "<div class=\"title-tab\"><span>Choose Icons <\/span><i class=\"\"><\/i><\/div>",
                        "tabs": []
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
					"icon_hover_color": {
                        "type": "colorpicker",
                        "title": "Icon Hover Color",
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
                },
				"custom_text": {
                    "type": "section",
                    "label_title_font": {
                        "type": "markup",
                        "markup": "<div class=\"awe-title\"><h3>Title text font<\/h3><\/div>"
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
                    "label_desc_font": {
                        "type": "markup",
                        "markup": "<div class=\"awe-title\"><h3>Description text font<\/h3><\/div>"
                    },
                    font_desc_field:{
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
        AWEContent.Controllers.partner = new AWEContent.Views.PartnerItemController();
        AWEContent.Panels.partner = new AWEContent.Views.partnerPanel();
    });
})(jQuery);
