/**
 * File: awecontent-client-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for heder item
     */
    AWEContent.Models.ClientItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "client",
            nameIcon: 'icon-help-circled',
            fontSize: -1,
            lineHeight: -1,
            color: '',
            hoverColor: '',
            boxModelSettings : {},
            customID : '',
            customClass: '',
            customEnableAttributes: 0,
            customDataAttributes: '[] ', // Array Json ex : [{"attrName":"autoPlay","attrValue":"true"}]
            customActionAttributes : '{"newAction": "", "newAttrName": "", "newAttrValue": ""}',
            customEnableAnimations: 0,
            customDataAnimations: '{"type" : "none"}', // Data Object
            lgResponsive: true,
            xsResponsive: true,
            mediumResponsive: true,
            smResponsive: true
        },
        createView: function() {
            this.view = new AWEContent.Views.ClientItem({model: this});
        },
        relations: [
            {
                type: Backbone.HasOne,
                key: "boxModelSettings",
                relatedModel: AWEContent.Models.BoxModelSettings
            }
        ],
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.ClientItem(cloneModel);
        }
    });

    /**
     * Define View for HeaderItem
     */
    AWEContent.Views.ClientItem = AWEContent.Views.Item.extend({
        initialize : function(){
            AWEContent.Views.Item.prototype.initialize.call(this);
            //this.listenTo(this.model.get('boxModelSettings'), 'change', this.applySettingsChanged);
        },
        itemTemplate: _.template(
            '<div class="box-icon box-icon3">\
			  <div class="box-image">\
				<span><i class="<%= clientClasses %>"></i></span>\
			  </div>\
			</div>'
        ),
        itemStyle: _.template(
            '<style>\
			.<%= itemClass %>.awe-icon .box-image {\n\
                color: <%= color %>;\n\
            }\n\
            .<%= itemClass %>.awe-icon .box-image:hover {\n\
                color: <%= hoverColor %>;\n\
				border-color: <%= hoverColor %>;\n\
            }\n\
			</style>'
        ),
        renderItemContent: function() {
            var self = this,
                settings = self.model.toJSON(),
                $client = $('<div class="awe-icon awe-item"></div>');
                //$style = $('style', $client);

            self.itemClass = 'awe-icon-' + this.cid;
            $client.addClass(self.itemClass).html(self.itemTemplate({clientClasses: settings.nameIcon})).find('i').css({
                'font-size' : settings.fontSize == -1 ? '' : (settings.fontSize + 'px'),
                'line-height' : settings.lineHeight == -1 ?  '' : ( settings.lineHeight + 'px')
            }).renderItemDefaultBoxModel(settings.boxModelSettings);
            self.$el.append(this.itemStyle({
                itemClass: this.itemClass,
                color: settings.color,
                hoverColor: settings.hoverColor
            }));
            $client.addClass(settings.customClass).attr('id', settings.customID);
            $client.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            if (settings.customEnableAnimations) {
                $client.processAnimations(settings.customDataAnimations)
            }
            self.$el.defaultResponsive(settings);
			
            return $client;
        },
        applySettingsChanged: function(model) {
            var self = this,
                $client = $('.awe-icon', self.el),
                $i = $('i', $client),
                $style = $('style', $client),
                settings = model.toJSON(),
                heightBefore = self.$el.height();

            $.each(model.changedAttributes(), function(key, value) {
                self.$el.changeResponsive(key, value);
                $client.renderChangeSettingBoxModel(key, value, model);
                switch (key){
                    case 'nameIcon' :
                        var prevIcon = self.model.previousAttributes().nameIcon;

                        $i.removeClass(prevIcon).addClass(value);
                        break;

                    case 'fontSize' :
                        value == -1 ? $client.find('i').css('fontSize', '') : $client.find('i').css('fontSize', value + 'px');
                        break;

                    case 'lineHeight' :
                        value == -1 ? $client.find('i').css('line-height', '') : $client.find('i').css('line-height', value + 'px');
                        break;

                    case 'color':
                    case 'hoverColor':
                        self.generateStyle();
                        break;

                    case 'customID':
                        $client.attr('id', value);
                        break;

                    case 'customClass' :
                        var prevClass = self.model.previousAttributes().customClass;

                        $client.removeClass(prevClass).addClass(value);
                        break;

                    case 'customEnableAttributes':
                        $client.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;

                    case 'customActionAttributes':
                        $client.renderChangeSettingsAttributes(key, value);
                        break;

                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $client.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $client.processAnimations(animation, prevAnimation);
                        }
                        break;

                    case 'customDataAnimations':
                        $client.processAnimations(settings.customDataAnimations, self.model.previousAttributes().customDataAnimations);
                        break;
                }
            });

            // Listen event change height of item
            setTimeout(function() {
                self.checkChangeHeight(heightBefore);
            }, 50);
        },
        generateStyle: function() {
            var self = this,
                style = '',
                settings = this.model.toJSON();

            if (self.updateColor)
                clearTimeout(self.updateColor);

            self.updateColor = setTimeout(function() {
                var style = self.itemStyle({
                    itemClass: self.itemClass,
                    color: settings.color,
                    hoverColor: settings.hoverColor
                });

                // update style color
                $('style', self.el).html(style);

                // clear timeout
                self.updateColor = false;
            }, 100);
        }
    });

    /**
     * Define view for Header Controller
     * li tag what is contained by items panel
     */
    AWEContent.Views.ClientItemController = AWEContent.Views.ItemController.extend({
        machineName : 'client',
        controllerHtml: function() {
            return '<div class="title-icon">Client</div><i class="ic ac-icon-star-outline"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.ClientItem(templateData);
            }

            return new AWEContent.Models.ClientItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.ClientPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-client",
        panelName: "client",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;

            $('#custom-choose-icons .title-tab', self.el).click( function() {
                var $controller = $(this).closest('#custom-choose-icons');
                AWEContent.Panels.listIconPanel.processIcon($controller);
            });
            $('#custom-choose-icons', self.el).change( function(event, data) {
                if (data) {
                    self.editingModel.set('nameIcon', data.nameIcon);
                    $('.title-tab > i', this).removeClass().addClass(data.nameIcon);
                }
            });
            $('#client-custom-size', self.el).change(function(event, values) {
                self.editingModel.set('fontSize', values.value);
                if (values.value == -1)
                    $('.display-font', $(this)).text('DF');
            });
            $('#client-custom-line-height', self.el).change(function(event, values){
                self.editingModel.set('lineHeight', values.value);
                if (values.value == -1)
                    $('.display-font', $(this)).text('DF');
            });
            $('#client-custom-color', self.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('color', color);
            });
            $('#client-custom-hover', self.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('hoverColor', color);
            });
            $('#client-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#text-client-custom-id', self.el).change( function() {
                self.editingModel.set('customID', $(this).val());
            });
            $('#text-client-custom-css', self.el).change( function() {
                self.editingModel.set('customClass', $(this).val());
            });
            $('#client-custom-attributes', this.el).initAttributesPanel(self);
            $('#client-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            $('#custom-choose-icons', self.el).attr('data-name-icon', settings.nameIcon);
            $('#custom-choose-icons i', self.el).removeClass().addClass(settings.nameIcon);
            $('#client-custom-size', self.el).aweSlider('value', settings.fontSize);
            $('#client-custom-line-height', self.el).aweSlider('value', settings.lineHeight);
            $('#client-custom-color', self.el).aweColorPicker('value', settings.color);
            $('#client-custom-hover', self.el).aweColorPicker('value', settings.hoverColor);
            $('#client-column-box-model', self.el).initBoxModel(settings.boxModelSettings);
            $('#text-client-custom-id', self.el).val(settings.customID);
            $('#text-client-custom-css', self.el).val(settings.customClass);
            $('#client-custom-attributes', this.el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#client-animations input[name=enabled_custom_animation]', this.el).val(settings.customEnableAnimations).trigger('change');
            $('#client-animations input[name=enabled_custom_animation]', this.el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div><h2>Client<\/h2><\/div>"
                },
                "custom_definitions": {
                    "type": "section",
                    "custom_choose_icons": {
                        "type": "tabs_icon",
                        "title": "<div class=\"title-tab\"><span>Choose Icon <\/span><i class=\"\"><\/i><\/div>",
                        "tabs": []
                    },
                    "custom_size": {
                        "type": "slider",
                        "title": "Font Size",
                        "min_value": -1,
                        "unit": "px",
                        "max_value": 100,
                        "default_value": 100,
                        "allow_type": true
                    },
                    "custom_line_height": {
                        "type": "slider",
                        "title": "Line Spacing",
                        "unit": "px",
                        "min_value": -1,
                        "max_value": 100,
                        "default_value": 100,
                        "allow_type": true
                    },
                    "custom_color": {
                        "type": "colorpicker",
                        "title": "Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "custom_hover": {
                        "type": "colorpicker",
                        "title": "Hover color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
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
                "custom_style": {
                    "type": "section",
                    "custom_id": {
                        "type": "text_field",
                        "title": "ID",
                        "attributes": {
                            "placeholder": "Custom ID"
                        },
                        "default_value": ""
                    },
                    "custom_css": {
                        "type": "text_field",
                        "title": "Class",
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
        AWEContent.Controllers.client = new AWEContent.Views.ClientItemController();
        AWEContent.Panels.client = new AWEContent.Views.ClientPanel();
    });
})(jQuery);