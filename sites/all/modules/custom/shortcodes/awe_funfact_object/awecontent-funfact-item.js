/**
 * File: awecontent-funfact-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for Funfact item
     */
    AWEContent.Models.FunfactItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "funfact",
			icon: 'icon-help-circled',
            number: 0,
            title: 'This is title',
            background_color: '',
            numberColor:'',
            titleColor:'',
            hover_color : '',
			iconColor:'',
            fontSizeNumber:-1,
            lineHeightNumber:-1,
            letterSpacingNumber:-1,
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
            this.view = new AWEContent.Views.FunfactItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.FunfactItem(cloneModel);
        }
    });

    /**
     * Define View for Funfact Item
     */
    AWEContent.Views.FunfactItem = AWEContent.Views.Item.extend({
        additionalEvents: {
           'keypress .funfact-number' : 'changeValueNumber'
        },
        funfactTemplate: _.template(
			'<div class="box-count">\
				<div class="box-image">\
				  <i class="icon <%= classIcon %>"></i>\
				</div>\
				<div class="box-count-number fz-36">\
				  <span><%= number %></span>\
				</div>\
				<p class="bold"><%= title %></p>\
			</div>'
        ),
        funfactStyle: _.template(
            '<style>\
            .awe-model-<%= cid %> .ts-funfact:hover{\
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
                $funfact = $('<div class="ts-funfact awe-item"></div>'),
                css = {
                    'background-color' : settings.background_color,
                },
                fontCssNumber = {
                    'font-size' : settings.fontSizeNumber == -1 ? '' : (settings.fontSizeNumber + 'px'),
                    'line-height' : settings.lineHeightNumber == -1 ? '' : (settings.lineHeightNumber + 'px'),
                    'letter-spacing' : settings.letterSpacingNumber == -1 ? ''  : (settings.letterSpacingNumber + 'px'),
                    'font-family': settings.fontFamilyNumber,
                    'color':settings.numberColor
                },
                fontCssTitle = {
                    'font-size' : settings.fontSizeTitle == -1 ? '' : (settings.fontSizeTitle + 'px'),
                    'line-height' : settings.lineHeightTitle == -1 ? '' : (settings.lineHeightTitle + 'px'),
                    'letter-spacing' : settings.letterSpacingTitle == -1 ? ''  : (settings.letterSpacingTitle + 'px'),
                    'font-family': settings.fontFamilyTitle,
                    'color':settings.titleColor
                };
            $funfact.css(css);
            $funfact.attr({'id' : settings.customID}).addClass(settings.customClass).renderItemDefaultBoxModel(settings.boxModelSettings);
            self.$el.append(this.funfactStyle({cid : self.model.cid, color : settings.hover_color}));
            $funfact.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $funfact.html(self.funfactTemplate({classIcon: settings.icon, title : settings.title, number: settings.number}));
            self.iframeJQuery(this.el).delegate('.ts-funfact', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('.box-count-number span'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('p'), heightBefore, heightAfter);
            });
            self.$el.defaultResponsive(settings);
            $funfact.find('.box-count-number span').css(fontCssNumber);
            $funfact.find('p').css(fontCssTitle);
			$funfact.find('i').css('color', settings.iconColor);
            return $funfact;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
                $funfact = $('> .ts-funfact', self.el),
				$i = $('.icon', self.el),
                heightBefore = self.$el.height(),$funfact_number,$funfact_title;
            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $funfact.renderChangeSettingBoxModel(key, value, model);
                $funfact_number = $funfact.find('.box-count-number span');
                $funfact_title = $funfact.find('p');
                switch (key) {
					case 'icon' :
                        var prevIcon = self.model.previousAttributes().icon;
                        $i.removeClass(prevIcon).addClass(value);
                        break;
					case 'numberColor' :
                        $funfact_number.css('color', value);
                        break;
                    case 'titleColor' :
                        $funfact_title.css('color', value);
                        break;
                    case 'background_color' :
                        $funfact.css('background-color', value);
                        break;
                    case 'hover_color' :
                        self.generateStyle();
                        break;
					case 'iconColor' :
                        $funfact.find('i').css('color', value);
                        break;
                    case 'fontFamilyNumber':
                        $funfact_number.css('font-family', value);
                        break;

                    case 'fontStyleNumber':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $funfact_number.css(fontStyle);
                        break;

                    case 'fontSizeNumber':
                        value == -1 ? $funfact_number.css('font-size', '') : $funfact_number.css('font-size', value + 'px');
                        break;

                    case 'lineHeightNumber' :
                        value == -1 ? $funfact_number.css('line-height', '') : $funfact_number.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingNumber':
                        value == -1 ? $funfact_number.css('letter-spacing', '') : $funfact_number.css('letter-spacing', value + 'px');
                        break;
                    case 'fontFamilyTitle':
                        $funfact_title.css('font-family', value);
                        break;

                    case 'fontStyleTitle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $funfact_title.css(fontStyle);
                        break;

                    case 'fontSizeTitle':
                        value == -1 ? $funfact_title.css('font-size', '') : $funfact_title.css('font-size', value + 'px');
                        break;

                    case 'lineHeightTitle' :
                        value == -1 ? $funfact_title.css('line-height', '') : $funfact_title.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingTitle':
                        value == -1 ? $funfact_title.css('letter-spacing', '') : $funfact_title.css('letter-spacing', value + 'px');
                        break;
                    case 'customID':
                        $funfact.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        $funfact.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $funfact.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;

                    case 'customActionAttributes':
                        $funfact.renderChangeSettingsAttributes(key, value);
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
                        $funfact.processAnimations(animation, prevAnimation);
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
                case 'p':
                    this.model.set('title', _html);
                    break;
                case '.box-count-number span':
                    this.model.set('number', _html);
                    break;
            }

        },
        changeValueNumber:function(evt){
            var charCode = (evt.which) ? evt.which : event.keyCode
            if (charCode > 31 && (charCode < 48 || charCode > 57)){
                alert('Please input a number')
               return false;
           }
            return true;
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
                $('style', self.$el).html(self.funfactStyle({cid : self.model.cid, color : settings.hover_color}));

                // clear inline style for all color
                $('span.title-accr', self.$el).css('color', '');
                $('.ui-accordion-header', self.$el).css('background-color', '');

                // clear timeout
                self.updateColor = false;
            }, 100);
        }
    });

    /**
     * Define view for Funfact Controller
     * li tag what is contained by items panel
     */
    AWEContent.Views.FunfactItemController = AWEContent.Views.ItemController.extend({
        machineName: 'funfact',
        controllerHtml: function() {
            return '<div class="title-icon">FunFact</div><i class="ic ac-icon-star-outline"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.FunfactItem(templateData);
            }

            return new AWEContent.Models.FunfactItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define Funfact panel
     */
    AWEContent.Views.FunfactPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-funfact",
        panelName: "funfact",
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
			$('#funfact-number-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('numberColor', color);
            });
            $('#funfact-title-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('titleColor', color);
            });
            $('#funfact-background-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('background_color', color);
            });
            $('#funfact-hover-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('hover_color', color);
            });
			$('#funfact-icon-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('iconColor', color);
            });

            $('#funfact-font-number-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('fontFamilyNumber', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('fontStyleNumber', fontStyle.value);
            }).bind('textAlignChange', function(event, textAlign) {
                self.editingModel.set('textAlignNumber', textAlign.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('fontSizeNumber', fontSize.value);
            }).bind('letterSpacingChange', function(event, letterSpacing) {
                self.editingModel.set('letterSpacingNumber', letterSpacing.value);
            }).bind('lineHeightChange', function(event, lineHeight) {
                self.editingModel.set('lineHeightNumber', lineHeight.value);
            });

            $('#funfact-font-title-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
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

            $('#funfact-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#text-funfact-custom-id', self.el).change( function(){
                self.editingModel.set('customID', $(this).val());
            });
            $('#text-funfact-custom-class', self.el).change( function(){
                self.editingModel.set('customClass', $(this).val());
            });
            $('#funfact-custom-attributes', this.el).initAttributesPanel(self);
            $('#funfact-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
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
            $('#funfact-hover-color', this.$el).aweColorPicker('value', settings.hover_color);
			$('#funfact-icon-color', this.$el).aweColorPicker('value', settings.iconColor);
            $('#funfact-background-color', this.$el).aweColorPicker('value', settings.background_color);
            $('#funfact-number-color', this.$el).aweColorPicker('value', settings.numberColor);
            $('#funfact-title-color', this.$el).aweColorPicker('value', settings.titleColor);
            $('#funfact-font-number-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyNumber,
                fontStyle: settings.fontStyleNumber,
                fontSize: settings.fontSizeNumber,
                textAlign: settings.textAlignNumber,
                letterSpacing: settings.letterSpacingNumber,
                lineHeight: settings.lineHeightNumber
            });

            $('#funfact-font-title-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyTitle,
                fontStyle: settings.fontStyleTitle,
                fontSize: settings.fontSizeTitle,
                textAlign: settings.textAlignTitle,
                letterSpacing: settings.letterSpacingTitle,
                lineHeight: settings.lineHeightTitle
            });
            $('#funfact-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#text-funfact-custom-id', this.$el).val(settings.customID);
            $('#text-funfact-custom-class', this.$el).val(settings.customClass);
            $('#funfact-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#funfact-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#funfact-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Funfact<\/h2><\/div>"
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
                    "number_color": {
                        "type": "colorpicker",
                        "title": "Text number Color",
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
                    "label_number_font": {
                        "type": "markup",
                        "markup": "<div class=\"awe-title\"><h3>Number text font<\/h3><\/div>"
                    },
                    font_number_field:{
                      type: "font",
                        disabledElements: ['textAlign']
                    },
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
        AWEContent.Controllers.funfact = new AWEContent.Views.FunfactItemController();
        AWEContent.Panels.funfact = new AWEContent.Views.FunfactPanel();
    });
})(jQuery);
