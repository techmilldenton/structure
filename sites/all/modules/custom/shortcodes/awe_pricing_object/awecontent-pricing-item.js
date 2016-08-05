/**
 * File: awecontent-pricing-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for Pricing item
     */
    AWEContent.Models.PricingItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "pricing",
            type: 'BASIC',
            price: '$0',
            unit:'month',
            headerColor:'',
			bodyColor:'',
            typeColor:'',
            priceColor:'',
            //hover_color : '',
            text_hover_color:'',
            feature_color:'',
            /*border_top_color:'',*/
            buttonUrl: '',
            buttonStyle : 'btn-effect-3',
            buttonTarget:'',
            textButton : 'SIGN UP',
            colorButton:'',
            colorButtonHover:'',
            backgroundButton:'',
            backgroundButtonHover:'',
            customEnableListText:1,
            customDataListText: '[{"id":1,"value":"Edit feature list above font box"},{"id":2,"value":"Feature 1"},{"id":5,"value":"Feature 2"}]',
            customActionListText: '{"newAction": "", "newAttrName": "", "newAttrValue": ""}',
            featureText:'<ul class="menu"><li>Feature 1</li><li>Feature 2</li><li>Feature 3</li><li>Feature 4</li></ul>',
            fontSizeType:-1,
            lineHeightType:-1,
            letterSpacingType:-1,
            fontSizePrice:-1,
            lineHeightPrice:-1,
            letterSpacingPrice:-1,
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
            this.view = new AWEContent.Views.PricingItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.PricingItem(cloneModel);
        }
    });

    /**
     * Define View for Pricing Item
     */
    AWEContent.Views.PricingItem = AWEContent.Views.Item.extend({
        additionalEvents: {
           //'keypress .pricing-number' : 'changeValueType'
        },
        pricingTemplate: _.template(
			'<div class="box-col">\
				  <div class="box-col-heading">\
					<h3><%= type %></h3>\
					<strong class="fz-48 price"><%= price %></strong>\
					<p class="mb-0 unit"><i class="bold"><%= unit %></i></p>\
				  </div>\
				  <div class="box-col-content text-center feature-list">\
					<%= featureText %>\
				  </div>\
				  <div class="box-col-action text-center">\
					<a class="btn-base <%= buttonStyle %> text-uppercase mt-10 ts-button" data-style="<%= buttonStyle %>">\
					  <span data-hover="<%= textButton %>"><%= textButton %></span>\
					</a>\
				  </div>\
			  </div>'
        ),
        pricingStyle: _.template(
            '<style>\
            .awe-model-<%= cid %> .ts-pricing-table:hover span,.awe-model-<%= cid %> .ts-pricing-table:hover h2{\
                color: <%= text_hover %> !important;\
            }\
            .awe-model-<%= cid %> .ts-button span {\
                color:<%= colorButton %> !important;\
				border-color:<%= colorButton %> !important;\
                background:<%= backgroundButton %> !important;\
            }\
			.awe-model-<%= cid %> .ts-button span:before {\
                color:<%= colorButtonHover %> !important;\
                background:<%= backgroundButtonHover %> !important;\
            }\
			.awe-model-<%= cid %> .feature-list ul li {\
                color:<%= feature_color %> !important;\
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
                $pricing = $('<div class="ts-pricing-table awe-item"></div>'),
/*                css = {
                    'background-color' : settings.background_color,
                },*/
                fontCssType = {
                    'font-size' : settings.fontSizeType == -1 ? '' : (settings.fontSizeType + 'px'),
                    'line-height' : settings.lineHeightType == -1 ? '' : (settings.lineHeightType + 'px'),
                    'letter-spacing' : settings.letterSpacingType == -1 ? ''  : (settings.letterSpacingType + 'px'),
                    'font-family': settings.fontFamilyType,
                    'color':settings.typeColor
                },
                fontCssPrice = {
                    'font-size' : settings.fontSizePrice == -1 ? '' : (settings.fontSizePrice + 'px'),
                    'line-height' : settings.lineHeightPrice == -1 ? '' : (settings.lineHeightPrice + 'px'),
                    'letter-spacing' : settings.letterSpacingPrice == -1 ? ''  : (settings.letterSpacingPrice + 'px'),
                    'font-family': settings.fontFamilyPrice,
                    'color':settings.priceColor
                };
            //$pricing.css(css);
            $pricing.attr({'id' : settings.customID}).addClass(settings.customClass).renderItemDefaultBoxModel(settings.boxModelSettings);
            self.$el.append(this.pricingStyle({
                cid : self.model.cid, text_hover:settings.text_hover_color,
                colorButton:settings.colorButton,backgroundButton:settings.backgroundButton,
				colorButtonHover:settings.colorButtonHover,backgroundButtonHover:settings.backgroundButtonHover,
				feature_color:settings.feature_color,
            }));
            $pricing.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $pricing.html(self.pricingTemplate({type : settings.type, price: settings.price,unit:settings.unit,featureText:settings.featureText,textButton:settings.textButton, buttonStyle:settings.buttonStyle}));
            self.iframeJQuery(this.el).delegate('.ts-pricing-table', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('h3'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.price'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.unit'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.feature-list'), heightBefore, heightAfter);
            });
            self.$el.defaultResponsive(settings);
            $pricing.find('h3').css(fontCssType);
            $pricing.find('.price').css(fontCssPrice);
			$pricing.find('.unit').css('color', settings.priceColor);
			$pricing.find('.box-col-heading').css('background-color', settings.headerColor);
			$pricing.find('.box-col').css('background-color', settings.bodyColor);
            if(settings.buttonUrl!='')
                $pricing.find('.ts-button').attr('href',settings.buttonUrl);
            else
                $pricing.find('.ts-button').attr('href','#');
            if(settings.buttonTarget!='')
                $pricing.find('.ts-button').attr('target',settings.buttonTarget);
            return $pricing;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
				result = "",
				buttonStyle = "",
                $pricing = $('> .ts-pricing-table', self.el),
                heightBefore = self.$el.height(),$pricing_type,$pricing_price;
            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $pricing.renderChangeSettingBoxModel(key, value, model);
                $pricing_type = $pricing.find('h3');
                $pricing_price = $pricing.find('.price');
                switch (key) {
					case 'typeColor' :
                        $pricing_type.css('color', value);
                        break;
                    case 'priceColor' :
                        $pricing_price.css('color', value);
						$pricing.find('.unit').css('color', value);
                        break;
					case 'headerColor' :
						$pricing.find('.box-col-heading').css('background-color', settings.headerColor);
                        break;
					case 'bodyColor' :
						$pricing.find('.box-col').css('background-color', settings.bodyColor);
                        break;
                    case 'buttonUrl':
                        if(value!='')
                            $pricing.find('.ts-button').attr('href',value);
                        else
                            $pricing.find('.ts-button').attr('href','#');
                        break;
                    case 'buttonTarget':
                        $pricing.find('.ts-button').attr('target',settings.buttonTarget);
                        break;
                    case 'buttonStyle':
                        buttonStyle = $pricing.find('.ts-button').attr('data-style');
						$pricing.find('.ts-button').removeClass(buttonStyle);
						$pricing.find('.ts-button').addClass(value);
						$pricing.find('.ts-button').attr('data-style', buttonStyle);
                        break;
					case 'textButton':
                        $pricing.find('.ts-button span').attr('data-hover',value);
						$pricing.find('.ts-button span').text(value);
                        break;
                    case 'feature_color' :
                        $pricing.find('.feature-list').css('color', value);
                        break;
                    case 'colorButton' :
                        $pricing.find('.ts-button span').css({"color": value, "border-color": value});
                        break;
					case 'colorButtonHover' :
                        if(value == "") value = "inherit";
						$pricing.append('<style>.awe-model-' + self.model.cid + ' .ts-button span:before {color: ' + value + ' !important;}</style>');
						$pricing.append('<style>.awe-model-' + self.model.cid + ' .btn-roll span:after {color: ' + value + ' !important;}</style>');
                        break;
                    case 'backgroundButton' :
                        $pricing.find('.ts-button span').css("background-color", value);
                        break;
					case 'backgroundButtonHover' :
                        if(value == "") value = "inherit";
						$pricing.append('<style>.awe-model-' + self.model.cid + ' .ts-button span:before {background-color: ' + value + ' !important;}</style>');
						$pricing.append('<style>.awe-model-' + self.model.cid + ' .btn-roll span:after {background-color: ' + value + ' !important;}</style>');
                        break;
						
                    case 'fontFamilyType':
                        $pricing_type.css('font-family', value);
                        break;

                    case 'fontStyleType':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $pricing_type.css(fontStyle);
                        break;

                    case 'fontSizeType':
                        value == -1 ? $pricing_type.css('font-size', '') : $pricing_type.css('font-size', value + 'px');
                        break;

                    case 'lineHeightType' :
                        value == -1 ? $pricing_type.css('line-height', '') : $pricing_type.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingType':
                        value == -1 ? $pricing_type.css('letter-spacing', '') : $pricing_type.css('letter-spacing', value + 'px');
                        break;
                    case 'fontFamilyPrice':
                        $pricing_price.css('font-family', value);
                        break;

                    case 'fontStylePrice':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $pricing_price.css(fontStyle);
                        break;

                    case 'fontSizePrice':
                        value == -1 ? $pricing_price.css('font-size', '') : $pricing_price.css('font-size', value + 'px');
                        break;

                    case 'lineHeightPrice' :
                        value == -1 ? $pricing_price.css('line-height', '') : $pricing_price.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingPrice':
                        value == -1 ? $pricing_price.css('letter-spacing', '') : $pricing_price.css('letter-spacing', value + 'px');
                        break;
                    case 'customID':
                        $pricing.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        $pricing.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $pricing.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;

                    case 'customActionAttributes':
                        $pricing.renderChangeSettingsAttributes(key, value);
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
                        $pricing.processAnimations(animation, prevAnimation);
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
            switch(select.selector){
                case 'h3':
                    this.model.set('type', _html);
                    break;
                case '.price':
                    this.model.set('price', _html);
                    break;
                case '.unit':
                    this.model.set('unit', _html);
                    break;
                case '.feature-list':
                    this.model.set('featureText', _html);
                    break;
            }

        },
        changeValueType:function(evt){
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
                $('style', self.$el).html(self.pricingStyle({
                    cid : self.model.cid, text_hover:settings.text_hover_color,colorButton:settings.colorButton,
                    colorButtonHover:settings.colorButtonHover,backgroundButtonHover:settings.backgroundButtonHover,
                }));

                // clear inline style for all color
                $('span.title-accr', self.$el).css('color', '');
                $('.ui-accordion-header', self.$el).css('background-color', '');

                // clear timeout
                self.updateColor = false;
            }, 100);
        }
    });

    /**
     * Define view for Pricing Controller
     * li tag what is contained by items panel
     */
    AWEContent.Views.PricingItemController = AWEContent.Views.ItemController.extend({
        machineName: 'pricing',
        controllerHtml: function() {
            return '<div class="title-icon">Pricing</div><i class="ic ac-icon-star-outline"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.PricingItem(templateData);
            }

            return new AWEContent.Models.PricingItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define Pricing panel
     */
    AWEContent.Views.PricingPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-pricing",
        panelName: "pricing",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;
			$('#pricing-type-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('typeColor', color);
            });
            $('#pricing-price-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('priceColor', color);
            });
			$('#pricing-header-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('headerColor', color);
            });
			$('#pricing-body-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('bodyColor', color);
            });

            $('#pricing-text-hover-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('text_hover_color', color);
            });
			
            $('#pricing-feature-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('feature_color', color);
            });

            // for button
            $('#text-pricing-button-url', this.el).change(function() {
                self.editingModel.set('buttonUrl', $(this).val());
            });
            $('#pricing-button-target', this.el).change(function(event, values) {
                self.editingModel.set('buttonTarget', values.value);
            });
			$('#text-pricing-text-button', this.el).change(function() {
                self.editingModel.set('textButton', $(this).val());
            });
            $('#pricing-button-style', this.el).change(function(event, values) {
                self.editingModel.set('buttonStyle', values.value);
            });
            $('#pricing-color-button', this.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('colorButton', color);
            });
            $('#pricing-background-button', this.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';

                self.editingModel.set('backgroundButton', color);
            });
            $('#pricing-color-button-hover', this.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('colorButtonHover', color);
            });
            $('#pricing-background-button-hover', self.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';

                self.editingModel.set('backgroundButtonHover', color);
            });
            // end button

            $('#pricing-font-type-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('fontFamilyType', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('fontStyleType', fontStyle.value);
            }).bind('textAlignChange', function(event, textAlign) {
                self.editingModel.set('textAlignType', textAlign.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('fontSizeType', fontSize.value);
            }).bind('letterSpacingChange', function(event, letterSpacing) {
                self.editingModel.set('letterSpacingType', letterSpacing.value);
            }).bind('lineHeightChange', function(event, lineHeight) {
                self.editingModel.set('lineHeightType', lineHeight.value);
            });

            $('#pricing-font-price-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('fontFamilyPrice', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('fontStylePrice', fontStyle.value);
            }).bind('textAlignChange', function(event, textAlign) {
                self.editingModel.set('textAlignPrice', textAlign.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('fontSizePrice', fontSize.value);
            }).bind('letterSpacingChange', function(event, letterSpacing) {
                self.editingModel.set('letterSpacingPrice', letterSpacing.value);
            }).bind('lineHeightChange', function(event, lineHeight) {
                self.editingModel.set('lineHeightPrice', lineHeight.value);
            });

            $('#pricing-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#text-pricing-custom-id', self.el).change( function(){
                self.editingModel.set('customID', $(this).val());
            });
            $('#pricing-pricing-custom-class', self.el).change( function(){
                self.editingModel.set('customClass', $(this).val());
            });
            $('#pricing-custom-attributes', this.el).initAttributesPanel(self);
            $('#pricing-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            $('#pricing-type-color', this.$el).aweColorPicker('value', settings.typeColor);
            $('#pricing-price-color', this.$el).aweColorPicker('value', settings.priceColor);
			$('#pricing-header-color', this.$el).aweColorPicker('value', settings.headerColor);
			$('#pricing-body-color', this.$el).aweColorPicker('value', settings.bodyColor);
            $('#pricing-feature-color', this.$el).aweColorPicker('value', settings.feature_color);
            // for button
            $('#text-pricing-button-url', this.el).val(settings.buttonUrl);
			$('#text-pricing-text-button', this.el).val(settings.textButton);
            $('#pricing-button-target', this.el).aweSelect('value', settings.buttonTarget);
            $('#pricing-button-style', this.el).aweSelect('value', settings.buttonStyle);
            $('#pricing-color-button', this.$el).aweColorPicker('value', settings.colorButton);
            $('#pricing-color-button-hover', this.$el).aweColorPicker('value', settings.colorButtonHover);
            $('#pricing-background-button', this.$el).aweColorPicker('value', settings.backgroundButton);
            $('#pricing-background-button-hover', this.$el).aweColorPicker('value', settings.backgroundButtonHover);
            //end button
            $('#pricing-font-type-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyType,
                fontStyle: settings.fontStyleType,
                fontSize: settings.fontSizeType,
                textAlign: settings.textAlignType,
                letterSpacing: settings.letterSpacingType,
                lineHeight: settings.lineHeightType
            });

            $('#pricing-font-price-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyPrice,
                fontStyle: settings.fontStylePrice,
                fontSize: settings.fontSizePrice,
                textAlign: settings.textAlignPrice,
                letterSpacing: settings.letterSpacingPrice,
                lineHeight: settings.lineHeightPrice
            });
            $('#pricing-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#text-pricing-custom-id', this.$el).val(settings.customID);
            $('#text-pricing-custom-class', this.$el).val(settings.customClass);
            $('#pricing-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#pricing-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#pricing-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Pricing Table<\/h2><\/div>"
                },

                "custom_color": {
                    "type": "section",
                    "header_color": {
                        "type": "colorpicker",
                        "title": "Header Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
					"body_color": {
                        "type": "colorpicker",
                        "title": "Body Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
					"type_color": {
                        "type": "colorpicker",
                        "title": "Text type Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "price_color": {
                        "type": "colorpicker",
                        "title": "Price Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "feature_color": {
                        "type": "colorpicker",
                        "title": "Feature Text Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    }
                },
                 "custom_feature": {
                      "type": "section",
					  "text_button": {
                        "type": "text_field",
                        "title": "Button Text",
                        "attributes": {
                          "placeholder": ""
                        },
                        "default_value": ""
                      },
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
                      
                      "button_style": {
                        "type": "select",
                        "title": "Button Style",
                        "options": {
                          "btn-effect-3" : "Style 1",
                          "btn-roll": "Style 2"
                        },
                        "default_value": "style-1"
                   	 },
                    
                    "color_button": {
                        "type": "colorpicker",
                        "title": "Button text color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                      },
                      "background_button": {
                        "type": "colorpicker",
                        "title": "Button background",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                      },
                      "color_button_hover": {
                        "type": "colorpicker",
                        "title": "Button hover text color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                      },
                      "background_button_hover": {
                        "type": "colorpicker",
                        "title": "Button hover background",
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
                    "label_type_font": {
                        "type": "markup",
                        "markup": "<div class=\"awe-title\"><h3>Type text font<\/h3><\/div>"
                    },
                    font_type_field:{
                      type: "font",
                        disabledElements: ['textAlign']
                    },
                    "label_price_font": {
                        "type": "markup",
                        "markup": "<div class=\"awe-title\"><h3>Price text font<\/h3><\/div>"
                    },
                    font_price_field:{
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
        AWEContent.Controllers.pricing = new AWEContent.Views.PricingItemController();
        AWEContent.Panels.pricing = new AWEContent.Views.PricingPanel();
    });
})(jQuery);
