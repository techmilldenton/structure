/**
 * File: awecontent-history-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for header item
     */
    AWEContent.Models.HistoryItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "history",
            fid: -1,
            styleImage: 'none',
            srcImage : 'http://placehold.it/267x179',
			title: '. Title',
			year: '1920',
			description: 'Description',
			title_color: '',
			year_color: '',
			color: '',
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
            this.view = new AWEContent.Views.HistoryItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.HistoryItem(cloneModel);
        }
    });

    /**
     * Define View for HistoryItem
     */
    AWEContent.Views.HistoryItem = AWEContent.Views.Item.extend({
        historyTemplate: _.template(
            '<div class="media box">\
				<div class="col-md-3 col-sm-4 col-xs-12 col-xs-12 pull-left pl-0">\
					<img src="<%= srcImage %>" alt="">\
				</div>\
				<div class="col-md-9 col-sm-8 pull-right">\
				  <div class="heading-title">\
					<h5 class="<%= textTransform %>"><span class="year"><%= year %> </span><span class="title"><%= title %></span></h5>\
				  </div>\
				  <p class="info-desc"><%= description %></p>\
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
                $history = $('<div class="item-history awe-item"></div>'),
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
			
			// get image URLs
            this.$el.aweImageURL({
                fid: [settings.fid],
                styles: [settings.styleImage],
                success: function(el, fid, styles, response) {
                    self.processImageURL(el, fid, styles, response);
                }
            });
			
            html = self.historyTemplate({
                srcImage: settings.srcImage,
				title : settings.title,
				year : settings.year,
				description: settings.description,
				textTransform: settings.textTransform
            })
            $history
                .html(html)
                .renderItemDefaultBoxModel(settings.boxModelSettings);
				
			$history.find('h5 .title').css('color', settings.title_color);
			$history.find('h5 .year').css('color', settings.year_color);
			$history.find('.info-desc').css('color', settings.color);
			
			self.iframeJQuery(this.el).delegate('.item-history', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('h5 .title'), heightBefore, heightAfter);
				self.initHallo(self.iframeJQuery(this).find('h5 .year'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.info-desc'), heightBefore, heightAfter);
            });
			
            self.$el.defaultResponsive(settings);
            self.$el.attr('id', settings.customID);
            self.$el.addClass(settings.customClass);
            $history.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            if (settings.customEnableAnimations)
                $history.processAnimations(settings.customDataAnimations)
				
			$history.find('h5').css(fontCssTitle);
            $history.find('.info-desc').css(fontCssDesc);
			
            return $history;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
                $history = $('> .item-history', self.el),
				$history_title = $history.find('h5'),
                $history_desc = $history.find('.info-desc'),
                heightBefore = self.$el.height();
            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $history.renderChangeSettingBoxModel(key, value, model);
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
					case 'title_color' :
                        $history.find('h5 .title').css('color', value);
                        break;
					case 'year_color' :
                        $history.find('h5 .year').css('color', value);
                        break;
					case 'color' :
                        $history.find('.info-desc').css('color', value);
                        break;
					case 'textTransform':
						$history.find('h5').removeAttr('class');
						$history.find('h5').attr('class', value);
                        break;
					case 'fontFamilyTitle':
                        $history_title.css('font-family', value);
                        break;

                    case 'fontStyleTitle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $history_title.css(fontStyle);
                        break;

                    case 'fontSizeTitle':
                        value == -1 ? $history_title.css('font-size', '') : $history_title.css('font-size', value + 'px');
                        break;

                    case 'lineHeightTitle' :
                        value == -1 ? $history_title.css('line-height', '') : $history_title.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingTitle':
                        value == -1 ? $history_title.css('letter-spacing', '') : $history_title.css('letter-spacing', value + 'px');
                        break;
                    case 'fontFamilyDesc':
                        $history_desc.css('font-family', value);
                        break;

                    case 'fontStyleDesc':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $history_desc.css(fontStyle);
                        break;

                    case 'fontSizeDesc':
                        value == -1 ? $history_desc.css('font-size', '') : $history_desc.css('font-size', value + 'px');
                        break;

                    case 'lineHeightDesc' :
                        value == -1 ? $history_desc.css('line-height', '') : $history_desc.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingDesc':
                        value == -1 ? $history_desc.css('letter-spacing', '') : $history_desc.css('letter-spacing', value + 'px');
                        break;
					
					
                    case 'customID':
                        self.$el.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        self.$el.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $history.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        $history.renderChangeSettingsAttributes(key, value);
                        break;

                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $history.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $history.processAnimations(animation, prevAnimation);
                        }

                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $history.processAnimations(animation, prevAnimation);
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
                case 'h5 .title':
                    this.model.set('title', _html);
                    break;
				case 'h5 .year':
                    this.model.set('year', _html);
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
    AWEContent.Views.HistoryItemController = AWEContent.Views.ItemController.extend({
        machineName: 'history',
        controllerHtml: function() {
            return '<div class="title-icon">History</div><i class="ic ac-icon-star-outline"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.HistoryItem(templateData);
            }

            return new AWEContent.Models.HistoryItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.historyPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-history",
        panelName: "history",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;
            $('#history-select-image input[name=selected_media]', self.el).change(function () {
                var strFileData = $(this).val().trim(),
                    file = strFileData ? JSON.parse(strFileData) : false,
                    fileURL = file && file.file_url ? file.file_url : '',
                    fid = file && file.fid > 0 ? file.fid : -1;

                // set panel thumbnail by chose image
                $('.image-content > img', self.$el).attr('src', fileURL);

                // set model fid
                self.editingModel.set('fid', fid);
            });
            $('#history-thumb-style', this.el).change(function (event, values) {
                self.editingModel.set('styleImage', values.value);
            });
            $('#history-enable input', self.$el).change(function (event, scrollEdit) {
                if (!scrollEdit) {
                    self.editingModel.set('hover', parseInt($(this).val()));
                }
            });
            $('#history-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#history-custom-id', this.$el).change( function(){
                self.editingModel.set('customID', $(this).find('input').val());
            });
            $('#history-custom-class', this.$el).change( function(){
                self.editingModel.set('customClass', $(this).find('input').val());
            });
            $('#history-custom-attributes', this.el).initAttributesPanel(self);
            $('#history-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });
			$('#history-texttransform', this.$el).change(function (event, values) {
				self.editingModel.set('textTransform', values.value);
            });
			$('#history-font-title-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
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

            $('#history-font-desc-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
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
			
			$('#history-title-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('title_color', color);
            });
			$('#history-year-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('year_color', color);
            });
			$('#history-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('color', color);
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            $('#history-select-image img', self.el).attr('src', self.editingModel.imageURL == null ? 'http://placehold.it/200x200' : self.editingModel.imageURL );
            if (AWEContent.Path.imageStyleURL != '') {
                $('#history-thumb-style', self.el).aweSelect('value', settings.styleImage);
            }
            self.editingModel.set('hover', parseInt(0));
			$('#history-texttransform', self.el).aweSelect('value', settings.textTransform);
            $('#history-enable input', self.el).val(settings.hover).trigger("change", true);
            $('#history-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#history-custom-id input', this.el).val(settings.customID);
            $('#history-custom-class input', this.el).val(settings.customClass);
            $('#history-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#history-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#history-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
			
			$('#history-font-title-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyTitle,
                fontStyle: settings.fontStyleTitle,
                fontSize: settings.fontSizeTitle,
                textAlign: settings.textAlignTitle,
                letterSpacing: settings.letterSpacingTitle,
                lineHeight: settings.lineHeightTitle
            });

            $('#history-font-desc-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyDesc,
                fontStyle: settings.fontStyleDesc,
                fontSize: settings.fontSizeDesc,
                textAlign: settings.textAlignDesc,
                letterSpacing: settings.letterSpacingDesc,
                lineHeight: settings.lineHeightDesc
            });
			
			$('#history-title-color', this.$el).aweColorPicker('value', settings.title_color);
			$('#history-year-color', this.$el).aweColorPicker('value', settings.year_color);
			$('#history-color', this.$el).aweColorPicker('value', settings.color);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>History<\/h2><\/div>"
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
				"custom_color": {
                    "type": "section",
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
					"year_color": {
                        "type": "colorpicker",
                        "title": "Year Color",
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
        AWEContent.Controllers.history = new AWEContent.Views.HistoryItemController();
        AWEContent.Panels.history = new AWEContent.Views.historyPanel();
    });
})(jQuery);
