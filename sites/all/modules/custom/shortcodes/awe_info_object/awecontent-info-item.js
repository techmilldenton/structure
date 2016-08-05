/**
 * File: awecontent-message-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for header item
     */
    AWEContent.Models.InfoItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "info",
            fid: -1,
			style: 'style-1',
            styleImage: 'none',
            srcImage : 'http://placehold.it/360x220',
            title: 'Title',
            description: 'Description',
			overlay: 1,
			overlay_title: 'Title',
			overlay_text: 'Text Content',
			buttonText: 'READ MORE',
			textTransform: 'none',
            title_color: '',
            color: '',
			buttonColor: '',
			buttonHoverColor: '',
			titleHoverColor: '',
			textHoverColor: '',
			bgHoverColor: '',
			buttonUrl: '',
			buttonTarget:'',
			buttonStyle : 'btn-effect',
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
            this.view = new AWEContent.Views.InfoItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.InfoItem(cloneModel);
        }
    });

    /**
     * Define View for InfoItem
     */
    AWEContent.Views.InfoItem = AWEContent.Views.Item.extend({
        infoTemplate: _.template(
            '<div class="box-group-1 box <%= style %> <% if (style=="style-3" || style=="style-4") { %> hidden <% } %>" data-style="<%= style %>">\
			  <div class="box-image box-image1">\
				<img src="<%= srcImage %>" alt="">\
				<div class="box-overlay2 <% if (!overlay) { %> hidden <% } %>">\
				  <div class="box-overlay-wrapper">\
					<div class="box-overlay-content">\
						<div class="overlay-icon <% if (style=="style-2") { %> hidden <% } %>">\
						  <a class="ts-button box-overlay-link" href="#">\
							<i class="fa fa-link"></i>\
						  </a>\
						</div>\
						<div class="overlay-info <% if (style!="style-2") { %> hidden <% } %>">\
						  <span class="fz-18 overlay-title"><%= overlay_title %></span>\
						  <span class="fz-24 overlay-text"><%= overlay_text %></span>\
						  <a href="#" class="<%= buttonStyle %> btn-base text-uppercase mt-10 ts-button" data-style="<%= buttonStyle %>" data-object="button"><%= buttonText %></a>\
						</div>\
					</div>\
				  </div>\
				</div>\
			  </div>\
			  <div class="box-name"><a href="#"><h4 class="<%= textTransform %>" data-style="<%= textTransform %>"><%= title %></h4></a></div>\
			  <p class="info-desc"><%= description %></p>\
			  <a class="<%= buttonStyle %> btn-base text-uppercase mt-10 ts-button <% if (style=="style-2") { %> hidden <% } %>" data-style="<%= buttonStyle %>" data-object="button"><%= buttonText %></a>\
			</div>\
			<div class="box-group-2 box <% if (style!="style-3" && style!="style-4") { %> hidden <% } %>" data-style="<%= style %>">\
			  <div class="box-image">\
				<img src="<%= srcImage %>" alt="">\
				<div class="box-overlay <% if (!overlay) { %> hidden <% } %>">\
				  <a class="box-overlay-content box-overlay-link fz-18 ts-button" href="#"><i class="fa fa-link"></i></a>\
				</div>\
			  </div>\
			  <div class="box-content <% if (style=="style-3") { %> pr-0 mr-0 pb-25 <% } %>">\
				<div class="box-name"><h4 class="<%= textTransform %>" data-style="<%= textTransform %>"><%= title %></h4></div>\
				<p class="info-desc"><%= description %></p>\
				<a href="#" class="<%= buttonStyle %> btn-base text-uppercase mt-10 ts-button" data-style="<%= buttonStyle %>"><%= buttonText %></a>\
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
                $info = $('<div class="media awe-item info-item"></div>'),
                css = {
                    'color' : settings.color
                },
				fontCssTitle = {
                    'font-size' : settings.fontSizeTitle == -1 ? '' : (settings.fontSizeTitle + 'px'),
                    'line-height' : settings.lineHeightTitle == -1 ? '' : (settings.lineHeightTitle + 'px'),
                    'letter-spacing' : settings.letterSpacingTitle == -1 ? ''  : (settings.letterSpacingTitle + 'px'),
                    'font-family': settings.fontFamilyTitle
                },
				fontCssDescription = {
                    'font-size' : settings.fontSizeDescription == -1 ? '' : (settings.fontSizeDescription + 'px'),
                    'line-height' : settings.lineHeightDescription == -1 ? '' : (settings.lineHeightDescription + 'px'),
                    'letter-spacing' : settings.letterSpacingDescription == -1 ? ''  : (settings.letterSpacingDescription + 'px'),
                    'font-family': settings.fontFamilyDescription
                };
			
			// get image URLs
            this.$el.aweImageURL({
                fid: [settings.fid],
                styles: [settings.styleImage],
                success: function(el, fid, styles, response) {
                    self.processImageURL(el, fid, styles, response);
                }
            });
			
            html = self.infoTemplate({
                srcImage: settings.srcImage,
                title : settings.title,
                description: settings.description,
				buttonStyle: settings.buttonStyle,
				style: settings.style,
				overlay_title: settings.overlay_title,
				overlay_text: settings.overlay_text,
				buttonText: settings.buttonText,
				textTransform: settings.textTransform,
				overlay:settings.overlay
            })
			$info
                .html(html)
                .css(css)
                .renderItemDefaultBoxModel(settings.boxModelSettings);
			
			$info.find('h4').css('color', settings.title_color);
			$info.find('.btn-base').css({'color': settings.buttonColor, 'border-color': settings.buttonColor});
			$info.append('<style>.awe-model-' + self.model.cid + ' .btn-base:before {border-color: ' + settings.buttonColor + ';} .awe-model-' + self.model.cid + ' .btn-base:after {border-color: ' + settings.buttonHoverColor + ';} .awe-model-' + self.model.cid + ' .btn-base:hover {color: ' + settings.buttonHoverColor + ' !important; border-color: ' + settings.buttonHoverColor + ' !important;}</style>');
			$info.find('.box-overlay2').css('background-color', settings.bgHoverColor);
			$info.find('.box-overlay').css('background-color', settings.bgHoverColor);
			$info.find('.overlay-title').css('color', settings.titleHoverColor);
			$info.find('.overlay-text').css('color', settings.textHoverColor);
			
			$info.find('h4').css(fontCssTitle);
			$info.find('.info-desc').css(fontCssDescription);
			
            self.iframeJQuery(this.el).delegate('.media', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('h4'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.info-desc'), heightBefore, heightAfter);
				self.initHallo(self.iframeJQuery(this).find('.overlay-title'), heightBefore, heightAfter);
				self.initHallo(self.iframeJQuery(this).find('.overlay-text'), heightBefore, heightAfter);
				self.initHallo(self.iframeJQuery(this).find('.ts-button'), heightBefore, heightAfter);
            });
            self.$el.defaultResponsive(settings);
            self.$el.attr('id', settings.customID);
            self.$el.addClass(settings.customClass);
            $info.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            if (settings.customEnableAnimations)
                $info.processAnimations(settings.customDataAnimations)
				
            if(settings.buttonUrl!='')
                $info.find('.ts-button').attr('href',settings.buttonUrl);
            else
                $info.find('.ts-button').attr('href','#');
            if(settings.buttonTarget!='')
                $info.find('.ts-button').attr('target',settings.buttonTarget);
				
            return $info;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
                $info = $('> .media', self.el),
                $i = $('.icon i', self.el),
				style = "",
				buttonStyle = "",
                heightBefore = self.$el.height();
            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $info.renderChangeSettingBoxModel(key, value, model);
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
						style = $info.find('.box').attr('data-style');
						$info.find('.box').removeClass(style);
						$info.find('.box').addClass(value);
						$info.find('.box').attr('data-style', value);
						if(value=="style-1") {
							$info.find('.box-overlay2').removeClass('hidden');
							$info.find('.overlay-icon').removeClass('hidden');
							$info.find('.overlay-info').addClass('hidden');
							$info.find('.box > .ts-button').removeClass('hidden');
							$info.find('.box-group-1').removeClass('hidden');
							$info.find('.box-group-2').addClass('hidden');
						}
						if(value=="style-2") {
							$info.find('.box-overlay2').removeClass('hidden');
							$info.find('.overlay-icon').addClass('hidden');
							$info.find('.overlay-info').removeClass('hidden');
							$info.find('.box > .ts-button').addClass('hidden');
							$info.find('.box-group-1').removeClass('hidden');
							$info.find('.box-group-2').addClass('hidden');
						}
						if(value=="style-3") {
							$info.find('.box-group-1').addClass('hidden');
							$info.find('.box-group-2').removeClass('hidden');
							$info.find('.box-group-2 .box-content').addClass('pr-0 mr-0 pb-25');
						}
						if(value=="style-4") {
							$info.find('.box-group-1').addClass('hidden');
							$info.find('.box-group-2').removeClass('hidden');
							$info.find('.box-group-2 .box-content').removeClass('pr-0 mr-0 pb-25');
						}
                        break;
					case 'overlay':
                        if (value) {
							$info.find('.box-overlay2').removeClass('hidden');
							$info.find('.box-overlay').removeClass('hidden');
                        }
                        else {
							$info.find('.box-overlay2').addClass('hidden');
							$info.find('.box-overlay').addClass('hidden');
						}
                        break;
					case 'textTransform':
						style = $info.find('h4').attr('data-style');
						$info.find('h4').removeClass(style);
						$info.find('h4').addClass(value);
						$info.find('h4').attr('data-style', value);
                        break;
                    case 'title_color' :
                        $info.find('h4').css('color', value);
                        break;
                    case 'color' :
                        $('.media' , self.el).css('color', value);
                        break;
					case 'buttonColor' :
						$('.media' , self.el).find('.btn-base').css('color', value);
						if(value == "") value = "inherit";
						$info.append('<style>.awe-model-' + self.model.cid + ' .btn-base:before {border-color: ' + value + ';} .awe-model-' + self.model.cid + ' .btn-base {border-color: ' + value + ' !important;}</style>');
                        break;
					case 'buttonHoverColor' :
						if(value == "") value = "inherit";
						$info.append('<style>.awe-model-' + self.model.cid + ' .btn-base:after {border-color: ' + value + ';} .awe-model-' + self.model.cid + ' .btn-base:hover {color: ' + value + ' !important; border-color: ' + value + ' !important;} </style>');
                        break;
					case 'titleHoverColor' :
						$('.media' , self.el).find('.overlay-title').css('color', value);
                        break;
					case 'textHoverColor' :
						$('.media' , self.el).find('.overlay-text').css('color', value);
                        break;
					case 'bgHoverColor' :
						$('.media' , self.el).find('.box-overlay2').css('background-color', value);
						$('.media' , self.el).find('.box-overlay').css('background-color', value);
                        break;
						
					case 'fontFamilyTitle':
                        $info.find('h4').css('font-family', value);
                        break;

                    case 'fontStyleTitle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $info.find('h4').css(fontStyle);
                        break;
					case 'fontSizeTitle':
                        value == -1 ? $info.find('h4').css('font-size', '') : $info.find('h4').css('font-size', value + 'px');
                        break;

                    case 'lineHeightTitle' :
                        value == -1 ? $info.find('h4').css('line-height', '') : $info.find('h4').css('line-height', value + 'px');
                        break;
                    case 'letterSpacingTitle':
                        value == -1 ? $info.find('h4').css('letter-spacing', '') : $info.find('h4').css('letter-spacing', value + 'px');
                        break;
						
					case 'fontFamilyDescription':
                        $info.find('.info-desc').css('font-family', value);
                        break;

                    case 'fontStyleDescription':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '', 'font-style': ''};
                        $info.find('.info-desc').css(fontStyle);
                        break;

                    case 'fontSizeDescription':
                        value == -1 ? $info.find('.info-desc').css('font-size', '') : $info.find('.info-desc').css('font-size', value + 'px');
                        break;

                    case 'lineHeightDescription' :
                        value == -1 ? $info.find('.info-desc').css('line-height', '') : $info.find('.info-desc').css('line-height', value + 'px');
                        break;
                    case 'letterSpacingDescription':
                        value == -1 ? $info.find('.info-desc').css('letter-spacing', '') : $info.find('.info-desc').css('letter-spacing', value + 'px');
                        break;
						
					case 'buttonUrl':
                        if(value!='')
                            $info.find('.ts-button').attr('href',value);
                        else
                            $info.find('.ts-button').attr('href','#');
                        break;
                    case 'buttonTarget':
                        $info.find('.ts-button').attr('target',settings.buttonTarget);
                        break;
					case 'buttonStyle':
						buttonStyle = $info.find('.btn-base').attr('data-style');
						$info.find('.btn-base').removeClass(buttonStyle);
						$info.find('.btn-base').addClass(value);
						$info.find('.btn-base').attr('data-style', value);
                        break;

                    case 'customID':
                        self.$el.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        self.$el.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $info.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        $info.renderChangeSettingsAttributes(key, value);
                        break;

                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $info.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $info.processAnimations(animation, prevAnimation);
                        }

                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $info.processAnimations(animation, prevAnimation);
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
				case '.overlay-title':
                    this.model.set('overlay_title', _html);
                    break;
				case '.overlay-text':
                    this.model.set('overlay_text', _html);
                    break;
                case '.info-desc':
                    this.model.set('description', _html);
                    break;
				case '.ts-button':
                    this.model.set('buttonText', _html);
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
					if($(event.target).attr('data-object') == "button") {
						$('> .media', self.el).find('.btn-base').text($(event.target).text());
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
    AWEContent.Views.InfoItemController = AWEContent.Views.ItemController.extend({
        machineName: 'info',
        controllerHtml: function() {
            return '<div class="title-icon">Info Box</div><i class="ic ac-icon-star-outline"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.InfoItem(templateData);
            }

            return new AWEContent.Models.InfoItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.infoPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-info",
        panelName: "info",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;
            $('#info-select-image input[name=selected_media]', self.el).change(function () {
                var strFileData = $(this).val().trim(),
                    file = strFileData ? JSON.parse(strFileData) : false,
                    fileURL = file && file.file_url ? file.file_url : '',
                    fid = file && file.fid > 0 ? file.fid : -1;

                // set panel thumbnail by chose image
                $('img', self.$el).attr('src', fileURL);

                // set model fid
                self.editingModel.set('fid', fid);
            });
			$('#info-thumb-style', this.el).change(function (event, values) {
                self.editingModel.set('styleImage', values.value);
            });
			$('#info-style', this.$el).change(function (event, values) {
				self.editingModel.set('style', values.value);
            });
			$("#info-overlay input[name=toggle_value]", this.el).change(function (event, isInitPanel) {
                var value = parseInt($(this).val());

                if (!isInitPanel)
                    self.editingModel.set("overlay", value);
            });
			$('#info-texttransform', this.$el).change(function (event, values) {
				self.editingModel.set('textTransform', values.value);
            });
            $('#info-title-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('title_color', color);
            });
            $('#info-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('color', color);
            });
			
			// for button
            $('#text-info-button-url', this.el).change(function() {
                self.editingModel.set('buttonUrl', $(this).val());
            });
            $('#info-button-target', this.el).change(function(event, values) {
                self.editingModel.set('buttonTarget', values.value);
            });
			$('#info-button-style', this.el).change(function(event, values) {
                self.editingModel.set('buttonStyle', values.value);
            });
			$('#info-button-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('buttonColor', color);
            });
			$('#info-button-hover-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('buttonHoverColor', color);
            });
			$('#info-title-hover-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('titleHoverColor', color);
            });
			$('#info-text-hover-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('textHoverColor', color);
            });
			$('#info-bg-hover-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('bgHoverColor', color);
            });

            $('#info-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#info-custom-id', this.$el).change( function(){
                self.editingModel.set('customID', $(this).find('input').val());
            });
            $('#info-custom-class', this.$el).change( function(){
                self.editingModel.set('customClass', $(this).find('input').val());
            });
            $('#info-custom-attributes', this.el).initAttributesPanel(self);
            $('#info-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });
			
			$('#info-font-title-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
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
			
			$('#info-font-description-field', this.$el).bind('fontFamilyChange', function(event, fontName) {
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


        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            $('#info-select-image img', self.el).attr('src', self.editingModel.imageURL == null ? 'http://placehold.it/360x220' : self.editingModel.imageURL );
            if (AWEContent.Path.imageStyleURL != '') {
                $('#info-thumb-style', self.el).aweSelect('value', settings.styleImage);
            }
			
			$('#info-style', self.el).aweSelect('value', settings.style);
            $('#info-enable input', self.el).val(settings.hover).trigger("change", true);
			$("#info-overlay input[name=toggle_value]", self.el).val(settings.overlay).trigger("change", true);
			$('#info-texttransform', self.el).aweSelect('value', settings.textTransform);
            $('#info-title-color', this.$el).aweColorPicker('value', settings.title_color);
            $('#info-color', this.$el).aweColorPicker('value', settings.color);
			$('#info-button-color', this.$el).aweColorPicker('value', settings.buttonColor);
			$('#info-button-hover-color', this.$el).aweColorPicker('value', settings.buttonHoverColor);
			$('#info-title-hover-color', this.$el).aweColorPicker('value', settings.titleHoverColor);
			$('#info-text-hover-color', this.$el).aweColorPicker('value', settings.textHoverColor);
			$('#info-bg-hover-color', this.$el).aweColorPicker('value', settings.bgHoverColor);
			$('#text-info-button-url', this.el).val(settings.buttonUrl);
			$('#info-button-target', this.el).aweSelect('value', settings.buttonTarget);
			$('#info-button-style', this.el).aweSelect('value', settings.buttonStyle);
            $('#info-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#info-custom-id input', this.el).val(settings.customID);
            $('#info-custom-class input', this.el).val(settings.customClass);
            $('#info-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#info-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#info-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
			
			$('#info-font-title-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyTitle,
                fontStyle: settings.fontStyleTitle,
                fontSize: settings.fontSizeTitle,
                textAlign: settings.textAlignTitle,
                letterSpacing: settings.letterSpacingTitle,
                lineHeight: settings.lineHeightTitle
            });
			
			$('#info-font-description-field', this.$el).aweFont('options', {
                fontFamily: settings.fontFamilyDescription,
                fontStyle: settings.fontStyleDescription,
                fontSize: settings.fontSizeDescription,
                textAlign: settings.textAlignDescription,
                letterSpacing: settings.letterSpacingDescription,
                lineHeight: settings.lineHeightDescription
            });
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Info Box<\/h2><\/div>"
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
						"title": "Info Box Style",
						"options": {
							"style-1": "Style 1",
							"style-2": "Style 2",
							"style-3": "Style 3",
							"style-4": "Style 4"
						},
						"default_value": "style-1"
					},
					"overlay": {
					  "type": "toggle",
					  "title": "Enable Overlay"
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
                    },
					"title_hover_color": {
                        "type": "colorpicker",
                        "title": "Title Hover Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
					"text_hover_color": {
                        "type": "colorpicker",
                        "title": "Text Hover Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
					"bg_hover_color": {
                        "type": "colorpicker",
                        "title": "Background Hover Color",
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
                          "btn-effect" : "Button Effect 1",
                          "btn-effect-2" : "Button Effect 2",
                          "btn-effect-3": "Button Effect 3"
                        },
                        "default_value": "btn-effect"
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
        AWEContent.Controllers.info = new AWEContent.Views.InfoItemController();
        AWEContent.Panels.info = new AWEContent.Views.infoPanel();
    });
})(jQuery);