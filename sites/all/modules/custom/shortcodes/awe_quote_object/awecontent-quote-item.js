/**
 * File: awecontent-quote-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for header item
     */
    AWEContent.Models.QuoteItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "quote",
            fid: -1,
            styleImage: 'none',
            srcImage : 'http://placehold.it/90x90',
			title: 'Title',
			description: 'Description',
			position: 'Position',
			style: 'style-1',
			title_color: '',
			color: '',
			pos_color: '',
			textTransform: 'none',
			fontSizeTitle:-1,
            lineHeightTitle:-1,
            letterSpacingTitle:-1,
            fontSizeDesc:-1,
            lineHeightDesc:-1,
            letterSpacingDesc:-1,
			fontSizePos:-1,
            lineHeightPos:-1,
            letterSpacingPos:-1,
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
            this.view = new AWEContent.Views.QuoteItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.QuoteItem(cloneModel);
        }
    });

    /**
     * Define View for QuoteItem
     */
    AWEContent.Views.QuoteItem = AWEContent.Views.Item.extend({
        quoteTemplate: _.template(
            '<div class="quote <% if (style=="style-3") { %> hidden <% } %>">\
                  <div class="quote-wrapper">\
                    <div class="quote-content">\
                      <p class="mb-0 info-desc" data-object="text"><%= description %></p>\
                    </div>\
                  </div>\
                  <div class="quote-detail <% if (style=="style-2") { %> hidden <% } %>">\
					  <img class="quote-image" src="<%= srcImage %>" alt="">\
					  <div class="quote-info">\
						<div class="box-name pb-0">\
						  <h4 class="<%= textTransform %>" data-object="name"><%= title %></h4>\
						</div>\
						<p class="position"><%= position %></p>\
					  </div>\
				  </div>\
             </div>\
			 <div class="testi <% if (style!="style-3") { %> hidden <% } %>">\
				 <div class="quote-content">\
					<div class="col-md-10 col-md-offset-1 col-sm-10 col-sm-offset-1 col-xs-8 col-xs-offset-2">\
					  <p class="mb-0 info-desc" data-object="text"><%= description %></p>\
					</div>\
				 </div>\
				 <div class="box-name pb-0">\
                  	<h4 data-object="name">Mr. Frankie Kao</h4>\
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
                $quote = $('<div class="item-quote awe-item"></div>'),
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
                },
				fontCssPos = {
                    'font-size' : settings.fontSizePos == -1 ? '' : (settings.fontSizePos + 'px'),
                    'line-height' : settings.lineHeightPos == -1 ? '' : (settings.lineHeightPos + 'px'),
                    'letter-spacing' : settings.letterSpacingPos == -1 ? ''  : (settings.letterSpacingPos + 'px'),
                    'font-family': settings.fontFamilyPos
                };
			
			// get image URLs
            this.$el.aweImageURL({
                fid: [settings.fid],
                styles: [settings.styleImage],
                success: function(el, fid, styles, response) {
                    self.processImageURL(el, fid, styles, response);
                }
            });
			
            html = self.quoteTemplate({
                srcImage: settings.srcImage,
				title : settings.title,
				description: settings.description,
				position: settings.position,
				textTransform: settings.textTransform,
				style: settings.style
            })
            $quote
                .html(html)
                .renderItemDefaultBoxModel(settings.boxModelSettings);
				
			$quote.find('h4').css('color', settings.title_color);
			$quote.find('.info-desc').css('color', settings.color);
			$quote.find('.position').css('color', settings.pos_color);
			
			self.iframeJQuery(this.el).delegate('.item-quote', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('h4'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.info-desc'), heightBefore, heightAfter);
				self.initHallo(self.iframeJQuery(this).find('.position'), heightBefore, heightAfter);
            });
			
            self.$el.defaultResponsive(settings);
            self.$el.attr('id', settings.customID);
            self.$el.addClass(settings.customClass);
            $quote.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            if (settings.customEnableAnimations)
                $quote.processAnimations(settings.customDataAnimations)
				
			$quote.find('h4').css(fontCssTitle);
            $quote.find('.info-desc').css(fontCssDesc);
			$quote.find('.position').css(fontCssPos);
			
            return $quote;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
                $quote = $('> .item-quote', self.el),
				$quote_title = $quote.find('h4'),
                $quote_desc = $quote.find('.info-desc'),
				$quote_pos = $quote.find('.position'),
                heightBefore = self.$el.height();
            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $quote.renderChangeSettingBoxModel(key, value, model);
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
					case 'style':
						if(value == "style-1") {
							$quote.find('.quote').removeClass('hidden');
							$quote.find('.quote-detail').removeClass('hidden');
							$quote.find('.testi').addClass('hidden');
						}
						else if(value == "style-2") {
							$quote.find('.quote').removeClass('hidden');
							$quote.find('.quote-detail').addClass('hidden');
							$quote.find('.testi').addClass('hidden');
						}
						else {
							$quote.find('.quote').addClass('hidden');
							$quote.find('.testi').removeClass('hidden');
						}
                        break;
					case 'title_color' :
                        $quote.find('h4').css('color', value);
                        break;
					case 'color' :
                        $quote.find('.info-desc').css('color', value);
                        break;
					case 'pos_color' :
                        $quote.find('.position').css('color', value);
                        break;
					case 'textTransform':
						$quote.find('h4').removeAttr('class');
						$quote.find('h4').attr('class', value);
                        break;
					case 'fontFamilyTitle':
                        $quote_title.css('font-family', value);
                        break;

                    case 'fontStyleTitle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $quote_title.css(fontStyle);
                        break;

                    case 'fontSizeTitle':
                        value == -1 ? $quote_title.css('font-size', '') : $quote_title.css('font-size', value + 'px');
                        break;

                    case 'lineHeightTitle' :
                        value == -1 ? $quote_title.css('line-height', '') : $quote_title.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingTitle':
                        value == -1 ? $quote_title.css('letter-spacing', '') : $quote_title.css('letter-spacing', value + 'px');
                        break;
                    case 'fontFamilyDesc':
                        $quote_desc.css('font-family', value);
                        break;

                    case 'fontStyleDesc':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $quote_desc.css(fontStyle);
                        break;

                    case 'fontSizeDesc':
                        value == -1 ? $quote_desc.css('font-size', '') : $quote_desc.css('font-size', value + 'px');
                        break;

                    case 'lineHeightDesc' :
                        value == -1 ? $quote_desc.css('line-height', '') : $quote_desc.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingDesc':
                        value == -1 ? $quote_desc.css('letter-spacing', '') : $quote_desc.css('letter-spacing', value + 'px');
                        break;
					
					case 'fontFamilyPos':
                        $quote_pos.css('font-family', value);
                        break;

                    case 'fontStylePos':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $quote_pos.css(fontStyle);
                        break;

                    case 'fontSizePos':
                        value == -1 ? $quote_pos.css('font-size', '') : $quote_pos.css('font-size', value + 'px');
                        break;

                    case 'lineHeightPos' :
                        value == -1 ? $quote_pos.css('line-height', '') : $quote_pos.css('line-height', value + 'px');
                        break;
                    case 'letterSpacingPos':
                        value == -1 ? $quote_pos.css('letter-spacing', '') : $quote_pos.css('letter-spacing', value + 'px');
                        break;
					
                    case 'customID':
                        self.$el.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        self.$el.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $quote.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        $quote.renderChangeSettingsAttributes(key, value);
                        break;

                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $quote.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $quote.processAnimations(animation, prevAnimation);
                        }

                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $quote.processAnimations(animation, prevAnimation);
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
                case 'h4':
                    this.model.set('title', _html);
                    break;
				case '.position':
                    this.model.set('position', _html);
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
					if($(event.target).attr('data-object') == "name") {
						$('> .item-quote', self.el).find('h4').text($(event.target).text());
					}
					if($(event.target).attr('data-object') == "text") {
						$('> .item-quote', self.el).find('.info-desc').text($(event.target).text());
					}
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
    AWEContent.Views.QuoteItemController = AWEContent.Views.ItemController.extend({
        machineName: 'quote',
        controllerHtml: function() {
            return '<div class="title-icon">Testimonial</div><i class="ic ac-icon-star-outline"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.QuoteItem(templateData);
            }

            return new AWEContent.Models.QuoteItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.quotePanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-quote",
        panelName: "quote",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;
            $('#quote-select-image input[name=selected_media]', self.el).change(function () {
                var strFileData = $(this).val().trim(),
                    file = strFileData ? JSON.parse(strFileData) : false,
                    fileURL = file && file.file_url ? file.file_url : '',
                    fid = file && file.fid > 0 ? file.fid : -1;

                // set panel thumbnail by chose image
                $('.image-content > img', self.$el).attr('src', fileURL);

                // set model fid
                self.editingModel.set('fid', fid);
            });
            $('#quote-thumb-style', this.el).change(function (event, values) {
                self.editingModel.set('styleImage', values.value);
            });
            $('#quote-enable input', self.$el).change(function (event, scrollEdit) {
                if (!scrollEdit) {
                    self.editingModel.set('hover', parseInt($(this).val()));
                }
            });
            $('#quote-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#quote-custom-id', this.$el).change( function(){
                self.editingModel.set('customID', $(this).find('input').val());
            });
            $('#quote-custom-class', this.$el).change( function(){
                self.editingModel.set('customClass', $(this).find('input').val());
            });
            $('#quote-custom-attributes', this.el).initAttributesPanel(self);
            $('#quote-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });
			$('#quote-texttransform', this.$el).change(function (event, values) {
				self.editingModel.set('textTransform', values.value);
            });
			$('#quote-font-title-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
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

            $('#quote-font-desc-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
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
			
			$('#quote-font-pos-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('fontFamilyPos', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('fontStylePos', fontStyle.value);
            }).bind('textAlignChange', function(event, textAlign) {
                self.editingModel.set('textAlignPos', textAlign.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('fontSizePos', fontSize.value);
            }).bind('letterSpacingChange', function(event, letterSpacing) {
                self.editingModel.set('letterSpacingPos', letterSpacing.value);
            }).bind('lineHeightChange', function(event, lineHeight) {
                self.editingModel.set('lineHeightPos', lineHeight.value);
            });
			
			$('#quote-style', this.$el).change(function (event, values) {
				self.editingModel.set('style', values.value);
            });
			
			$('#quote-title-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('title_color', color);
            });
			$('#quote-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('color', color);
            });
			$('#quote-pos-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('pos_color', color);
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            $('#quote-select-image img', self.el).attr('src', self.editingModel.imageURL == null ? 'http://placehold.it/200x200' : self.editingModel.imageURL );
            if (AWEContent.Path.imageStyleURL != '') {
                $('#quote-thumb-style', self.el).aweSelect('value', settings.styleImage);
            }
            self.editingModel.set('hover', parseInt(0));
			$('#quote-texttransform', self.el).aweSelect('value', settings.textTransform);
            $('#quote-enable input', self.el).val(settings.hover).trigger("change", true);
            $('#quote-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#quote-custom-id input', this.el).val(settings.customID);
            $('#quote-custom-class input', this.el).val(settings.customClass);
            $('#quote-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#quote-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#quote-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
			
			$('#quote-font-title-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyTitle,
                fontStyle: settings.fontStyleTitle,
                fontSize: settings.fontSizeTitle,
                textAlign: settings.textAlignTitle,
                letterSpacing: settings.letterSpacingTitle,
                lineHeight: settings.lineHeightTitle
            });

            $('#quote-font-desc-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyDesc,
                fontStyle: settings.fontStyleDesc,
                fontSize: settings.fontSizeDesc,
                textAlign: settings.textAlignDesc,
                letterSpacing: settings.letterSpacingDesc,
                lineHeight: settings.lineHeightDesc
            });
			
			$('#quote-font-pos-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyPos,
                fontStyle: settings.fontStylePos,
                fontSize: settings.fontSizePos,
                textAlign: settings.textAlignPos,
                letterSpacing: settings.letterSpacingPos,
                lineHeight: settings.lineHeightPos
            });
			
			$('#quote-style', self.el).aweSelect('value', settings.style);
			$('#quote-title-color', this.$el).aweColorPicker('value', settings.title_color);
			$('#quote-color', this.$el).aweColorPicker('value', settings.color);
			$('#quote-pos-color', this.$el).aweColorPicker('value', settings.pos_color);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Testimonial<\/h2><\/div>"
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
                    },
					'style': {
						"type": "select",
						"title": "Testimonial Style",
						"options": {
							"style-1": "Style 1",
							"style-2": "Style 2",
							"style-3": "Style 3"
						},
						"default_value": "style-1"
					},
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
                    },
					"pos_color": {
                        "type": "colorpicker",
                        "title": "Position Color",
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
                    },
					"label_pos_font": {
                        "type": "markup",
                        "markup": "<div class=\"awe-title\"><h3>Position text font<\/h3><\/div>"
                    },
                    font_pos_field:{
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
        AWEContent.Controllers.quote = new AWEContent.Views.QuoteItemController();
        AWEContent.Panels.quote = new AWEContent.Views.quotePanel();
    });
})(jQuery);
