/**
 * File:awecontent-dialog.js
 * Author: MegaDrupal
 * Website: http://megadrupal.com/
 */
(function ($) {
    'use strict';
    AWEContent.Views.Dialog = Backbone.View.extend({
        initialize: function() {
            $('body').append(this.$el);
        },
        events: {
            'click .pp-footer > a.pp-save': 'save',
            'click .pp-footer > a.pp-cancel': 'close'
        },
        save: function(event) {
            if (event)
                event.preventDefault();
        },
        open: function(event) {
            if (event)
                event.preventDefault()
            this.$el.addClass('pp-active').removeAttr('style');
        },
        close: function(event) {
            if (event)
                event.preventDefault();
            this.$el.removeClass('pp-active');
        }
    });

    AWEContent.Views.TemplateDialog = AWEContent.Views.Dialog.extend({
        id: 'save-template-dialog',
        className: 'md-popup',
        type: 'section',
        savedElement: null,
        changedBgColor: false,
        showMsg: false,
        template: _.template(
            '<div class="tb">\
                <div class="tb-cell">\
                    <div class="popup-inner">\
                        <div class="pp-heading"><h2>Section Template</h2></div>\
                        <div class="pp-body">\
                            <div class="pp-title">\
                                <h4>Title</h4>\
                                <input type="text">\
                                <span class="md-message">This field is required</span>\
                            </div>\
                            <div class="pp-content">\
                                <h4>Template Cover</h4>\
                                <div class="cover-uploader">\
                                    <input type="file">\
                                    <span><i>If you don\'t choose a cover image. An image will be auto generate base on template view.</i></span>\
                                </div>\
                                <div class="image-thumb" style="display: none">\
                                    <img src="" alt="">\
                                    <a href="#" class="remove-thumb" title="Remove">×</a>\
                                </div>\
                            </div>\
                            <textarea id="ac-template-data" style="display: none"></textarea>\
                        </div>\
                        <div class="pp-footer">\
                            <a href="#" class="awe-actionbutton pp-save">Choose</a>\
                            <a href="#" class="pp-cancel">Cancel</a>\
                        </div>\
                    </div>\
                </div>\
            </div>'
        ),
        initialize: function() {
            AWEContent.Views.Dialog.prototype.initialize.call(this);

            // render dialog
            this.$el.append(this.template());

            // set template type
            this.type = AWEContent.templateType;

            if (this.type == 'page')
                $('.pp-heading h2', this.$el).html('Page template');

            // handle click remove cover image
            $('.remove-thumb', this.$el).click(function(event) {
                event.preventDefault();
                $('.image-thumb', self.$el).hide();
                $('.cover-uploader', self.$el).show();
            });
        },
        open: function(template) {
            // set value for elements on dialog
            $('.pp-title > input', this.$el).removeClass('pp-error').val(template.title);
            $('.pp-title > span.md-message', this.$el).hide();
            $('.pp-content .cover-uploader input', this.$el).val('');
            $('#ac-template-data', this.$el).val(JSON.stringify(template));

            if (template.tid && template.tid > 0) {
                $('.pp-content .cover-uploader').hide();


                $('.pp-content .image-thumb > img').attr('src', template.thumbnail);
                $('.pp-content .image-thumb').show();
            }

            AWEContent.Views.Dialog.prototype.open.call(this);
        },
        save: function(event) {
            AWEContent.Views.Dialog.prototype.save.call(this, event);
            var self = this,
                title = $('.pp-title > input', this.$el).val().trim();

            if (title) { // Implements post template to server
                var template = JSON.parse($('#ac-template-data', this.$el).val().trim());

                // prepare template data
                template.title = title;
                template.type = this.type;

                // process upload template
                if ($('.image-thumb', this.$el).is(':visible')) {
                    self.uploadTemplate(false, template, true);
                }
                else {
                    if ($('.pp-content .cover-uploader > input', this.$el)[0].files.length) {
                        self.uploadTemplate($('.pp-content .cover-uploader > input', this.$el)[0].files[0], template);
                        if (this.changedBgColor)
                            this.savedElement.css('background-color', '');
                    }
                    else {
                        // set style for render template image
                        if (this.type == 'section') {
                            this.changedBgColor = false;
                            if (template.data.settings.bgColor == '') {
                                this.changedBgColor = true;
                                this.savedElement.css('background-color', '#FFFFFF');
                            }
                            this.savedElement.removeClass('creating');
                        }
                        else
                            $('.awe-section', this.savedElement).removeClass('creating');

                        // Render cover image
                        html2canvas(this.savedElement[0], {
                            proxy: AWEContent.Path.templateProxy,
                            onrendered: function(canvas) {
                                var resizedHeight= canvas.height,
                                    resizedWidth = canvas.width,
                                    newCanvas = canvas;

                                if (resizedHeight > 1000) {
                                    resizedWidth = resizedWidth*(1000/resizedHeight);
                                    resizedHeight = 1000;

                                    if (resizedWidth < 248) {
                                        resizedHeight = resizedHeight*(248/resizedWidth);
                                        resizedWidth = 248;
                                    }
                                    newCanvas = AWEContent.compressImage(canvas, resizedWidth, resizedHeight);
                                }

                                // Upload template to server
                                self.uploadTemplate(newCanvas.toDataURL("image/jpg"), template);

                                // Re-add class creating to section
                                if (self.type == 'section') {
                                    if (self.changedBgColor)
                                        self.savedElement.css('background-color', '');
                                    self.savedElement.addClass('creating')
                                }
                                else
                                    $('.awe-section', self.savedElement).addClass('creating');
                            },
                            logging: false,
                            useCORS: true,
                            allowTaint: false
                        });
                    }
                }

                // Close save dialog
                this.close();
            }
            else { // Show error message
                $('.pp-title > input', this.$el).addClass('pp-error');
                $('.pp-title > span.md-message', this.$el).show();
            }
        },
        uploadTemplate: function(fileData, templateData, keepOldThumbnail) {
            var formData = new FormData(),
                uploadRequest = new XMLHttpRequest();

            if ($.type(templateData) != 'string')
                templateData = JSON.stringify(templateData);

            // convert template data before upload
            if (keepOldThumbnail)
                formData.append('keep_thumbnail', 1);
            else if (fileData) {
                // Add upload data to FormData
                if ($.type(fileData) == 'object')
                    formData.append("thumbnailData", fileData);
                else {
                    var blobsFile = this.spitThumbnailImageData(fileData);
                    $.each(blobsFile, function(index, blob) {
                        formData.append('thumbnail_data_' + index, blob)
                    });
                }
            }

            formData.append("templateData", templateData);
            formData.append('act', 'save_template');

            // Create request to upload template data file
            if (keepOldThumbnail || fileData) {
                uploadRequest.open("POST", AWEContent.Path.uploadTemplate); // POST template
                uploadRequest.onreadystatechange = function () {
                    if (this.readyState === 4) {
                        if (this.status === 200) {
                            var response = JSON.parse(this.responseText.trim());

                            if (response.status == 1) {
                                $(window).trigger('aweUploadTemplateSuccess', response.template);
                                if (self.showMsg)
                                    alert('Template has been created.')
                            }
                            else
                                alert(response.msg);
                        }
                        else
                            console.log('Template upload failed');
                    }
                }

                // send template data
                uploadRequest.send(formData);
            }
        },
        spitThumbnailImageData: function(thumbnailData) {
            var length = thumbnailData.length,
                start = 0,
                blobLen = 1000000,
                end = start + blobLen,
                blobs = [];

            while(start < length) {
                blobs.push(thumbnailData.slice(start, end));
                start = end;
                end = start + blobLen;
            }

            return blobs;
        }
    });

    /**
     * Define view for page template dialog
     */
    AWEContent.Views.PageTemplateDialog = AWEContent.Views.Dialog.extend({
        id: 'page-templates-dialog',
        className: 'md-popup',
        isReady: false,
        template: _.template(
            '<div class="tb">\
                <div class="tb-cell">\
                    <div class="popup-inner">\
                        <div class="pp-heading"><h2>Choose page template</h2></div>\
                        <div class="pp-body">\
                            <div class="awe-templates-list-wrapper">\
                                <div class="awe-templates-list clearfix">\
                                    <div class="awe-page-tpl-item active">\
                                        <div class="template-container">\
                                            <div class="template-thumbnail">\
                                                <div style="background-color: #d6d6d6; width: 220px; height: 260px"></div>\
                                            </div>\
                                            <h3 class="template-title">Blank</h3>\
                                            <input type="hidden" value="[]">\
                                        </div>\
                                    </div>\
                                </div>\
                                <div class="template-load-more">\
                                    <div class="awe-overlay" style="display: none">\
                                        <div id="followingBallsG">\
                                            <div id="followingBallsG_1" class="followingBallsG"></div>\
                                            <div id="followingBallsG_2" class="followingBallsG"></div>\
                                            <div id="followingBallsG_3" class="followingBallsG"></div>\
                                            <div id="followingBallsG_4" class="followingBallsG"></div>\
                                        </div>\
                                    </div>\
                                    <a href="#" class="awe-actionbutton pp-load-more">Load more</a>\
                                </div>\
                            </div>\
                        </div>\
                        <div class="pp-footer">\
                            <a href="#" class="awe-actionbutton pp-save">Choose</a>\
                            <a href="#" class="pp-cancel">Cancel</a>\
                        </div>\
                    </div>\
                </div>\
            </div>'
        ),
        itemTemplate: _.template(
            '<div class="awe-page-tpl-item">\
                <div class="template-container">\
                    <div class="template-thumbnail"><img alt="" src="<%= template.thumbnail %>" /></div>\
                    <h3 class="template-title"><%= template.title %></h3>\
                    <input type="hidden" value=\'<%= template.data %>\'>\
                </div>\
            </div>'
        ),
        initialize: function() {
            var self = this;

            AWEContent.Views.Dialog.prototype.initialize.call(this);
            this.numberTemplates = 0;
            this.dbStart = null; //use when load template from database
            this.allowLoadMore = false;
            this.templateLoading = false;

            // render dialog content
            this.$el.append(this.template);

            // init scroll-bar for list template
            $('.awe-templates-list-wrapper', this.$el).perfectScrollbar().scroll(function() {
                if (self.allowLoadMore) {
                    var $yScrollRail = $('.ps-scroll-y-rail'),
                        yRailHeight = $yScrollRail.height(),
                        $yScrollBar = $('.ps-scrollbar-y', $yScrollRail);

                    if (yRailHeight - $yScrollBar.height() - parseInt($yScrollBar.css('top')) < 10 && !self.templateLoading) {
                        self.loadTemplates();
                    }
                }
            });

            // handle choose template
            self.$el.delegate('.awe-page-tpl-item', 'click', function(event) {
                if (!$(this).hasClass('active')) {
                    $('.awe-page-tpl-item.active', self.$el).removeClass('active');
                    $(this).addClass('active');
                }
                else {
                    var sectionData = JSON.parse($('input', $(this)).val().trim());
                    self.close(event, sectionData)
                }
            });

            // handle click load more button
            $('.pp-load-more', this.$el).click(function(event) {
                event.preventDefault();
                if (!self.templateLoading)
                    self.loadTemplates();
            });

            // implements load template from server
            this.isReady = false;
            this.loadTemplates(true);
        },
        loadTemplates: function(firstLoad) {
            var self = this;

            // set flag is loading
            this.templateLoading = true;
            $('.awe-overlay', this.$el).show();
            $('.pp-load-more', this.$el).hide();

            // request to server get page templates
            var type = (AWEContent.buildTemplateType && AWEContent.buildTemplateType !== undefined) ? AWEContent.buildTemplateType : 'page';
            $.post(AWEContent.Path.templateActionURL, {
                act: 'load_templates',
                current: this.numberTemplates,
                db_start: this.dbStart,
                type: type
            }, function(response) {
                if (response) {
                    if ($.type(response) == 'string')
                        response = JSON.parse(response.trim());

                    // change title dialog
                    if(type === 'block'){
                        $('.pp-heading h2', this.$el).text('Choose block template');
                    } else {
                        $('.pp-heading h2', this.$el).text('Choose page template');
                    }

                    // set flag load infinitive
                    self.allowLoadMore = response.load_more;
                    if (self.allowLoadMore)
                        $('.template-load-more', self.$el).show();
                    else
                        $('.template-load-more', self.$el).hide();

                    // render page template
                    $.each(response.templates, function() {
                        var template = this;
                        $('.awe-templates-list', self.$el).append(self.itemTemplate({template: template}));
                    });

                    // update list template scroll-bar
                    $('.awe-templates-list-wrapper', this.$el).perfectScrollbar('update');
                    $('.ps-scrollbar-x-rail', self.$el).remove();

                    // update number templates on dialog
                    if (self.numberTemplates == 0)
                        self.numberTemplates += response.templates.length-1;
                    else
                        self.numberTemplates += response.templates.length;
                    if (response.db_start) {
                      self.dbStart = response.db_start;
                    }
                    if (firstLoad)
                        self.isReady = true;

                    // set flag to define load template is finished
                    self.templateLoading = false;
                    $('.awe-overlay', self.$el).hide();
                    $('.pp-load-more', self.$el).show();
                }
            });
        },
        save: function(event) {
            AWEContent.Views.Dialog.prototype.save.call(this, event);

            if ($('.awe-page-tpl-item.active', this.$el).length) {
                var sectionsData = JSON.parse($('.awe-page-tpl-item.active input', this.$el).val().trim());

                this.close(event, sectionsData);
                return true;
            }

            // alert to choose template dialog
            alert('You must select a template.');
        },
        close: function(event, sectionsData) {
            if (sectionsData)
                this.$el.trigger('close',[sectionsData]);

            AWEContent.Views.Dialog.prototype.close.call(this, event);
        },
        open: function(event) {
            AWEContent.Views.Dialog.prototype.open.call(this, event);

            $('.awe-page-tpl-item.active', this.$el).removeClass('active');
            $('.awe-page-tpl-item:first', this.$el).addClass('active');
        }
    });

    AWEContent.Views.SectionCategoriesDialog = AWEContent.Views.Dialog.extend({
        id: 'edit-template-sections',
        className: 'md-popup',
        template: _.template(
            '<div class="tb">\
                <div class="tb-cell">\
                    <div class="popup-inner">\
                        <div class="pp-heading"><h2>Edit section category</h2></div>\
                        <div class="pp-body">\
                            <ul class="pp-list">\
                                <li>\
                                    <div class="pp-list-section">\
                                        <span class="pp-section-title" contenteditable="false">Header</span>\
                                        <div class="pp-control">\
                                            <div class="pp-control-item pp-sort" title="Sort">\
                                                <i class="ic ac-icon-move"></i>\
                                            </div>\
                                            <div class="pp-control-item pp-edit" title="Edit">\
                                                <i class="ic ac-icon-edit"></i>\
                                            </div>\
                                            <div class="pp-control-item pp-del" title="Delete">\
                                                <i class="ic ac-icon-trash"></i>\
                                            </div>\
                                        </div>\
                                    </div>\
                                </li>\
                            </ul>\
                        </div>\
                        <div class="pp-footer">\
                            <a href="#" class="awe-actionbutton pp-save">Save</a>\
                            <a href="#" class="pp-cancel">Cancel</a>\
                        </div>\
                    </div>\
                </div>\
            </div>\
            <div class="pp-list-section section-form-template" style="display: none">\
                <span class="pp-section-title" contenteditable="false">Header</span>\
                <div class="pp-control">\
                    <div class="pp-control-item pp-sort" title="Sort"><i class="ic ac-icon-move"></i></div>\
                    <div class="pp-control-item pp-edit" title="Edit"><i class="ic ac-icon-edit"></i></div>\
                    <div class="pp-control-item pp-del" title="Delete"><i class="ic ac-icon-trash"></i></div>\
                </div>\
            </div>'
        ),
        initialize: function() {
            AWEContent.Views.Dialog.prototype.initialize.call(this);
            var self = this;

            // render dialog content
            this.$el.append(this.template());

            $('ul.pp-list', this.$el).sortable({
                axis: 'y',
                containment: 'parent',
                handle: '.pp-sort',
                tolerance: 'pointer'
            });

            this.$el.delegate('.pp-edit', 'click', function() {
                $(this).parent().prev().attr('contenteditable', true).focus()
            }).delegate('.pp-del', 'click', function() {
                $(this).parents('li:first').hide();
            }).delegate('.pp-section-title', 'blur', function() {
                $(this).attr('contenteditable', false);
            });

            $('.ac-tpl-add-btn', this.$el).click(function(event) {
                event.preventDefault();
                var $newSection = $('<li></li>').append($('.section-form-template', self.$el).clone().removeClass('section-form-template').removeAttr('style')),
                    numberSections = $('.pp-body ul.pp-list li', self.$el).length;

                $('.pp-section-title', $newSection).text('Title' + numberSections).attr('contenteditable', true).focus();
                $('ul.pp-list', self.$el).append($newSection);
            });
        },
        open: function($filters) {
            var self = this;

            $('.pp-body ul.pp-list', this.$el).empty();
            $filters.each(function() {
                var machineName = $(this).data('filter').replace('.', ''),
                    title = $(this).html(),
                    $sectionItem = $('<li></li>').append($('.section-form-template', self.$el).clone().removeClass('section-form-template').removeAttr('style'));

                $('.pp-section-title', $sectionItem).text(title);
                $sectionItem.attr('data-machine-name', machineName);
                $('.pp-body ul.pp-list', self.$el).append($sectionItem);
            });

            AWEContent.Views.Dialog.prototype.open.call(this);
        },
        save: function(event) {
            if (event)
                event.preventDefault();

            if (confirm(Drupal.t('All change will be saved to server and could not restore. Are you sure?'))) {
                var self = this,
                    sectionsData = [];

                $('.pp-body ul.pp-list li', this.$el).each(function () {
                    var title = $('.pp-section-title', $(this)).text(),
                        sectionData = {
                            deleted: 0,
                            title: title,
                            machineName: ($(this).data('machine-name')) ? $(this).data('machine-name') : title.toLowerCase().replace(/[^a-z0-9-]/g, '-').replace(/^-|-$]/g, '')
                        };

                    if (!$(this).is(':visible'))
                        sectionData.deleted = 1;

                    sectionsData.push(sectionData);
                });

                $.post(AWEContent.Path.templateActionURL, {act: 'up_sec_categories', sections: sectionsData}, function (response) {
                    if (response.status) {
                        self.$el.removeClass('pp-active');
                        $('#filters ul.template-filter a:not(#all, #favourite)').each(function () {
                            $(this).parent().remove();
                        });
                        $('#save-template-dialog .pp-categories select').empty();
                        $.each(response.sections, function (machineName, title) {
                            $('#filters ul.template-filter').append('<li><a href="#" data-filter=".' + machineName + '">' + title + '</a></li>');
                        });
                    }
                    else
                        alert(Drupal.t('Server update section categories failed.'));

                });
            }

            AWEContent.Views.Dialog.prototype.save.call(this);
        }
    });
})(jQuery);
