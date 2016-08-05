/**
 * File: awecontent-lib.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function ($) {
    /**
     * Define color picker plugin for color element
     * @param options
     */
    $.fn.aweColorPicker = function(options, extra) {
        var $el = this;

        if ($.type(options) == 'string') {
            if ($el.data('color-initialized')) {
                var params = Array.prototype.slice.call(arguments, 1);

                switch (options) {
                    case 'value':
                        if (params.length) {
                            $('input[name=awe-color-picker]', $el).spectrum('set', params[0])
                        }
                        else {
                            return $('input[name=awe-color-picker]', $el).spectrum('get');
                        }
                        break;

                    default :
                        throw Error('aweColorPicker: no such method "'+options+'"');
                }

                return $el;
            }
            else {
                throw Error('Error: cannot call methods on aweColorPicker prior to initialization')

            }
        }

        // Call init spectrum on element
        var changeCallback = options.change,
            moveCallback = options.move,
            hideCallback = options.hide;

        options.change = function(color) {
            if (changeCallback)
                changeCallback(color);

            $el.trigger('change', color);
        }
        options.move = function(color) {
            if (moveCallback)
                moveCallback(color);

            $el.trigger('change', color);
        }
        options.hide = function(color) {
            if (hideCallback)
                hideCallback(color);
            $el.trigger('change', color);
        }
        $('input[name=awe-color-picker]', $el).spectrum(options).click(function(event) {
            event.preventDefault();
            $(this).spectrum('toggle');
        });
        $el.data('color-initialized', 1);

        return $el;
    }

    $.fn.aweBorderElementInit = function (options) {
        var $el = this;

        $(".border-unit-spectrum", $el).spectrum({
            preferredFormat: "hex",
            allowEmpty: true,
            showInput : true,
            appendTo: '#awe-spectrum-wrapper',
            change: function (color) {
                if ($(".trigger-uniform", $el).hasClass("enabled")) {
                    $(".border-unit-spectrum", $el).spectrum("set", color);
                    $(".md-box", $(this).parents(".list-box")).trigger("change");
                }
                else
                    $(this).parents(".md-box").first().trigger("change");
            },
            move: function (color) {
                if ($(".trigger-uniform", $el).hasClass("enabled"))
                    $("input[name=changing-color]", $el).val(color.toString()).trigger("change");
                else
                    $("input[name=changing-color]", $(this).parent().parent()).val(color.toString()).trigger("change");
            },
            hide: function (color) {
                if ($(".trigger-uniform", $el).hasClass("enabled"))
                    $('.md-box', $el).trigger("change", {isCancel: true});
                else
                    $('.md-box', $el).eq(0).trigger("change", {isCancel: true});
                $(this).closest(".md-box").removeClass("hover");
            },
            beforeShow: function () {
                $(this).closest(".md-box").addClass("hover");
            }
        });
        $("span.add", $el).click(function (event) {
            event.preventDefault();

            var current = parseInt($("span.display-font", $(this).parents(".md-box")).text()) + 1;

            if ($(".trigger-uniform", $el).hasClass("enabled")) {
                $("span.display-font", $(this).parents(".list-box")).text(current);
                $(".md-box", $(this).parents(".list-box")).trigger("change");
            }
            else {
                $("span.display-font", $(this).parents(".md-box")).text(current);
                $(this).parents(".md-box").first().trigger("change");
            }
        });
        $("span.abstract", $el).click(function (event) {
            event.preventDefault();

            var current = parseInt($("span.display-font", $(this).parents(".md-box")).text()),
                newValue = (current - 1 > 0) ? current - 1 : 0;

            if ($(".trigger-uniform", $el).hasClass("enabled")) {
                $("span.display-font", $(this).parents(".list-box")).text(newValue);
                $(".md-box", $(this).parents(".list-box")).trigger("change");
            }
            else {
                $("span.display-font", $(this).parents(".md-box")).text(newValue);
                $(this).parents(".md-box").first().trigger("change");
            }
        });
        $("span.display-font", $el).blur(function () {
            var allowValues = JSON.parse($(".list-border-values", $(this).parents(".list-box")).val()),
                currentValue = parseInt($(this).text());

            if ($.inArray(parseInt(currentValue), allowValues) == -1)
                currentValue = allowValues[0];

            if ($(".trigger-uniform", $el).hasClass("enabled")) {
                $("span.display-font", $(this).parents(".list-box")).text(currentValue).trigger("change");
                $(".md-box", $(this).parents(".list-box")).trigger("change");
            }
            else {
                $(this).text(currentValue).trigger("change");
                $(this).parents(".md-box").first().trigger("change");
            }
        });
        $(".toggle-enable", $el).click(function (event) {
            event.preventDefault();

            $('.togg-status', this).toggleClass("active");
            if ($('.togg-status', this).hasClass("active"))
                $("input[name=toggle_value]", $(this)).val(1).trigger("change");
            else
                $("input[name=toggle_value]", $(this)).val(0).trigger("change");
        });
        $("input[name=toggle_value]", $el).change(function () {
            var tabId = $(this).parents(".ui-tabs-panel").attr("aria-labelledby"),
                $tabController = $("> .select-tab li[aria-labelledby=" + tabId + "]", $(this).parents(".md-tab"));

            if (parseInt($(this).val())) {
                $(this).parent().addClass("active");
                $(".list-box", $(this).parent().parent().parent()).show();
                $tabController.addClass("enable");
            }
            else {
                $(this).parent().removeClass("active");
                $(".list-box", $(this).parent().parent().parent()).hide();
                $tabController.removeClass("enable");
            }
        });

        $(".trigger-uniform", $el).click(function () {
            $(this).toggleClass("enabled").trigger("change");
        }).change(function () {
            if ($(this).hasClass("enabled"))
                $(this).parent().addClass("constraint");
            else
                $(this).parent().removeClass("constraint");
        });
        $(".type-border", $el).click(function () {
            var styles = ["none", "solid", "dotted", "dashed", "double"],
                currentValue = $(this).text(),
                newValueIndex = $.inArray(currentValue, styles) + 1;

            if (newValueIndex >= styles.length)
                newValueIndex = 0;

            if ($(".trigger-uniform", $el).hasClass("enabled")) {
                $("span.type-border", $(this).parents(".list-box")).text(styles[newValueIndex]);
                $(".md-box", $(this).parents(".list-box")).trigger("change");
            }
            else {
                $(this).text(styles[newValueIndex]);
                $(this).parents(".md-box").first().trigger("change");
            }
        });
    }

    $.fn.aweSlider = function (options, extra) {
        var $el = this,
            default_options = {
                allowType: false,
                allowGreaterMax: true,
                allowLowerMin: true
            };

        // callback to process font size for display value element
        function setDisplayFontSize(setValue) {
            var numberChars = setValue.toString().length;

            if (numberChars > 3)
                $('.display-font', $el).css('font-size', parseInt(36*3/numberChars));
            else
                $('.display-font', $el).css('font-size', '');
        }

        // callback to set value when use slider widget
        function setSliderValue(value) {
            var initOptions = $el.data('options'),
                setVal;

            // check value is set
            if (isNaN(value) || (!initOptions.allowLowerMin && value < initOptions.min))
                setVal = initOptions.min;
            else if (!initOptions.allowGreaterMax && value > initOptions.max)
                setVal = initOptions.max;
            else
                setVal = parseInt(value);

            // process font-size for display value element
            setDisplayFontSize(setVal);

            // reset min value for slider when accepts type value lower than default max value
            if (initOptions.allowLowerMin && $('.slider-val', $el).slider('option', 'min') > value)
                $('.slider-val', $el).slider('option', 'min', setVal);

            // reset max value for slider when accepts type value greater than default max value
            if (initOptions.allowGreaterMax && $('.slider-val', $el).slider('option', 'max') < setVal)
                $('.slider-val', $el).slider('option', 'max', setVal);

            // set display element
            $(".display-font", $el).text(setVal);
            $(".slider-val", $el).slider("value", setVal);

            if ($.isNumeric(value))
                value = parseInt(value);

            $el.trigger('change', {original: original, value: value});
        }

        // callback to set value when use button widget
        function setButtonValue(value, original) {
            var allowValues = JSON.parse($("input[name=slider_values]", $el).val()),
                $display = $("span.display-font", $el),
                newValue;

            // check new value is set with config options
            if ($.type(allowValues[0]) !== 'string')
                value = parseInt(value);
            else
                value = ''+value;

            newValue = value;
            if ($.inArray(value, allowValues) == -1) {
                if (!options.allowType)
                    newValue = allowValues[0];
            }

            // set font size for display element
            setDisplayFontSize(newValue);

            $display.text(newValue);
            if ($.isNumeric(newValue))
                newValue = parseInt(newValue);
            if ($.isNumeric(original))
                original = parseInt(original);
            $el.trigger("change", {original: original, value: newValue});
        }

        // process call methods
        if ($.type(options) == 'string') {
            if ($el.data('awe-slider-initialized')) {
                var params = Array.prototype.slice.call(arguments, 1);

                switch (options) {
                    case 'value':
                        var initOptions = $el.data('options');

                        if (params.length) { // set value for slider
                            if (initOptions.type == 'slider') // set value for slider widget
                                setSliderValue(Number(params[0]));
                            else// set for button widget
                                setButtonValue(params[0]);
                        }
                        else { // get current value
                            $('.frame-display .display-font', $el).text();
                        }
                        break;

                    default:
                        throw Error("aweSlider: no such method: '" + options + "'");
                }

                return $el;
            }
            else
                throw new Error('Error: cannot call methods on aweSlider prior to initialization')
        }


        // process init for plugin
        options = $.extend({}, default_options, options);

        if (options.type == "button") {
            $("span.add", $(this)).click(function (event) {
                event.preventDefault();

                var allowValues = JSON.parse($("input[name=slider_values]", $(this).parents(".md-box")).val()),
                    $display = $("span.display-font", $(this).parents(".md-box")),
                    currentValue = $.type(allowValues[0]) === 'string' ? $display.text(): parseInt($display.text()),
                    currentIndex = $.inArray(currentValue, allowValues),
                    newValueIndex = (currentIndex + 1 >= allowValues.length) ? 0 : currentIndex + 1,
                    newValue = allowValues[newValueIndex];

                $display.text(allowValues[newValueIndex]);
                // convert type of value
                if ($.isNumeric(currentValue))
                    currentValue = parseInt(currentValue);
                if ($.isNumeric(newValue))
                    newValue = parseInt(newValue);

                // create event change for element
                $el.trigger('change', {original: currentValue, value: newValue});
            });
            $("span.abstract", $(this)).mousedown(function (event) {
                event.preventDefault();

                var allowValues = JSON.parse($("input[name=slider_values]", $(this).parents(".md-box")).val()),
                    $display = $("span.display-font", $(this).parents(".md-box")),
                    currentValue = $.type(allowValues[0]) === 'string' ? $display.text() : parseInt($display.text()),
                    currentIndex = $.inArray(currentValue, allowValues),
                    newValueIndex = (currentIndex - 1 >= 0) ? currentIndex - 1 : allowValues.length - 1,
                    newValue = allowValues[newValueIndex];

                $display.text(allowValues[newValueIndex]);

                // convert type of value
                if ($.isNumeric(currentValue))
                    currentValue = parseInt(currentValue);
                if ($.isNumeric(newValue))
                    newValue = parseInt(newValue);

                // create change event for element
                $el.trigger('change', {original: currentValue, value: newValue});
            });

            if (options.allowType) {
                var original;

                $("span.display-font", $(this)).blur(function () {
                    var typeValue = $("span.display-font", $(this).parents(".md-box")).text();
                    setButtonValue(typeValue, original);
                });
            }
        }
        else {
            var original;

            $(".slider-val", $el).slider({
                range: "min",
                min: parseInt(options.min),
                max: parseInt(options.max),
                step: parseInt(options.step),
                value: parseInt(options.default),
                start: function(event, ui) {
                    original = ui.value;
                },
                slide: function (event, ui) {
                    setDisplayFontSize(ui.value);
                    $(".display-font", $(this).parents(".md-box")).text(ui.value);
                },
                stop: function(event, ui) {
                    $el.trigger('change', {original: original, value: ui.value});
                }
            });

            if (options.allowType)
                $(".display-font", $el).blur(function () {
                    var typeLength = $(this).text().length,
                        typeValue = Number($(this).text());

                    setSliderValue(typeValue);
                }).click(function(event) {
                    event.preventDefault();
                    original = $('.slider-val', $el).slider('value');
                });
        }

        // set flag to define element is initialized
        $el.data('awe-slider-initialized', true).data('options', options);

        return $el;
    }

    $.fn.aweBoxModelElementInit = function () {
        var $el = this;

        $(".toggle-enable", $el).click(function (event) {
            event.preventDefault();

            $('.togg-status', this).toggleClass("active");
            if ($('.togg-status', this).hasClass("active"))
                $("input[name=toggle_value]", $(this)).val(1).trigger("change");
            else
                $("input[name=toggle_value]", $(this)).val(0).trigger("change");
        });
        $("input[name=toggle_value]", $el).change(function () {
            var tabId = $(this).parents(".ui-tabs-panel").attr("aria-labelledby"),
                $tabController = $("> .select-tab li[aria-labelledby=" + tabId + "]", $(this).parents(".md-tab"));

            if (parseInt($(this).val())) {
                $(this).parent().addClass("active");
                $(".list-box", $(this).parent().parent().parent()).show();
                $tabController.addClass("enable");
            }
            else {
                $(this).parent().removeClass("active");
                $(".list-box", $(this).parent().parent().parent()).hide();
                $tabController.removeClass("enable");
            }
        });

        $(".trigger-uniform", $el).click(function () {
            $(this).toggleClass("enabled").trigger("change");
        }).change(function () {
            if ($(this).hasClass("enabled"))
                $(this).parent().addClass("constraint");
            else
                $(this).parent().removeClass("constraint");
        });

        $(".md-box:first", $el).change(function (event, values) {
            if ($(".trigger-uniform", $(this).parents(".list-box")).hasClass("enabled"))
                $(".md-box", $(this).parents(".list-box")).not($(this)).aweSlider('value', values.value);
        });
    }

    $.fn.aweCustomAttributesElementInit = function () {
        var $el = this;

        this.click(function () {
            $('>.togg-status', this).toggleClass("active");
            if ($(".togg-status", this).hasClass("active")) {
                $("input[name=enabled_custom_attributes]", $(".togg-status", this)).val(1).trigger("change");
                $(".togg-status", this).next().show().trigger("click");
            }
            else {
                $(".togg-status", this).next().hide();
                $("input[name=enabled_custom_attributes]", $(".togg-status", this)).val(0).trigger("change");
                if (AWEContent.Panels.customAttributesPanel.isOpenned)
                    AWEContent.Panels.customAttributesPanel.closePanel();
            }
        });

        $("input[name=enabled_custom_attributes]", this).change(function () {
            if (parseInt($(this).val())) {
                $(this).parent().addClass("active");
                $(this).parent().next().show();
                $('input[name=attributes_data]', $el).trigger('change');
            }
            else {
                $(this).parent().removeClass("active");
                $(this).parent().next().hide();
                $el.removeClass('enable');
            }
        });
        $('input[name=attributes_data]', this).change(function () {
            if ($(this).val().indexOf('attrName') != -1) {
                $el.addClass('enable');
            }
            else {
                $el.removeClass('enable');
            }
        });
        $(".js-edit-attributes", this).click(function (event) {
            event.stopPropagation();
            AWEContent.Panels.customAttributesPanel.changeAttributes($el);
        });
    }

    /**
     * Plugin to init drag upload for element
     * @param options
     */
    $.fn.aweDragUpload = function (options) {
        var $el = this,
            uploader = this.get(0),
            defaultOpts = {
                uploadURL: AWEContent.Path.fileUploadURL,
                multiUpload: true,
                allowTypes: [],
                extendData: {},
                beforeUploadCallback: function() {},
                dragOverCallback: function (event, $el) {},
                dragLeaveCallback: function (event, $el) {},
                dropCallback: function (event, $el) {},
                uploadSuccessCallback: function (response) {},
                uploadFinishedCallback: function() {},
                uploadProgressCallback: function() {}
            },
            opts = $.extend({}, defaultOpts, options);

        // Check browser support get drag file
        if ('draggable' in document.createElement('span')) {
            uploader.ondragover = function (event) {
                event.preventDefault();

                // add awe-drag-over to notify for user can drop file
                $(this).addClass("awe-drag-over");

                // call drag over option callback
                opts.dragOverCallback(event, $el);
            };
            uploader.ondragleave = function (event) {
                event.preventDefault();

                // remove class notification element allowed drag file
                $(this).removeClass('awe-drag-over');

                // implements drag leave option callback
                opts.dragLeaveCallback(event, $el);
            };
            uploader.ondrop = function (event) {
                event.preventDefault();

                // remove class notification element allowed drag file
                $(this).removeClass("awe-drag-over");

                // implements callback when drop file
                opts.dropCallback(event, $el);

                // implements upload file to server
                if (event.dataTransfer.files.length) {
                    if (opts.multiUpload) {
                        $.map(event.dataTransfer.files, function(file) {
                            if (AWEContent.mediaValidateFileType(file.type, opts.allowTypes)) {
                                AWEContent.ajaxUpload(file, opts.extendData, opts);
                            }
                        });
                    }
                    else {
                        if (AWEContent.mediaValidateFileType(event.dataTransfer.files[0].type, opts.allowTypes))
                            AWEContent.ajaxUpload(event.dataTransfer.files[0], opts.extendData, opts);
                    }
                }
            }
        }
    }

    /**
     * Plugin init for upload element panel
     * @param options
     */
    $.fn.aweUploadElementInit = function (options) {
        // Callback to process before upload file
        function processBeforeUpload(file, id) {
            var $uploading = $(
                    '<div class="awe-item-upload">\
                        <div class="awe-upload-preview"></div>\
                        <div class="awe-upload-status">\
                            <i class="ic ac-icon-done"></i>\
                        </div>\
                        <div class="awe-info-progress">\
                            <span class="awe-upload-title"></span>\
                            <progress class="awe-upload-progress" min="0" max="100" value="0"></progress>\
                        </div>\
                        <input type="hidden" name="file_data" value="">\
                    </div>'
                ).attr('id', id),
                reader = new FileReader();


            $('.awe-upload-title', $uploading).text(file.name);
            $('.awe-info-upload', $item).append($uploading);
            reader.onload = function(event) {
                $('.awe-upload-preview', $uploading).append($('<img />').attr('src', event.target.result));
            }
            reader.readAsDataURL(file);
        }

        // Callback process when upload finished
        function processUploadFinished(event, file, id) {
            $('progress', $('#'+id, $item)).val(100);
        }

        // Callback process when upload is progress
        function processFileUploadProgress(event, file, id) {
            if (event.lengthComputable) {
                var $uploading = $('#'+id, $item),
                    completed = (event.loaded/event.total)*100 | 0;

                $("progress", $uploading).val(completed);
            }
        }

        // Callback process when file upload successful
        function processFileUploadSuccess(response, id) {
            var $uploading = $('#'+id, $item);
                if (response.status == 1) {
                    var file = response.file;

                // Process file uploaded info
                if (file) {
                    // Change file uploaded info to uploading item info
                    $('.awe-upload-preview img', $uploading).attr('src', file.file_url);
                    $(".awe-upload-status", $uploading).addClass("finish");
                    $("input[name=file_data]", $uploading).val(JSON.stringify(file));
                    $('.awe-info-upload', $item).trigger('change');
                    $uploading.trigger('click');
                }
            }
            else {
                $('.awe-upload-status i', $uploading).removeClass('ac-icon-done').addClass('ac-icon-clear').css('color', '#FF0000');
                $uploading.append('<div class="awe-error-msg">File is not uploaded unsuccessfully.</div>');
            }
        }

        var $item = this,
            opts = $.extend({}, options, {
                uploadURL: AWEContent.Path.fileUploadURL,
                multiUpload: $item.data("multi-upload"),
                beforeUploadCallback: processBeforeUpload,
                uploadFinishedCallback: processUploadFinished,
                uploadProgressCallback: processFileUploadProgress,
                uploadSuccessCallback: processFileUploadSuccess
            });

        $('.upload-photo', $item).aweDragUpload(opts);

        $(".upload-photo", $item).click(function (event) {
            event.preventDefault();
            $("input[name=awe_media_upload]", $(this).parents(".library")).trigger("click");
        });

        $("input[name=awe_media_upload]", $item).change(function () {
            var allowTypes = options.acceptTypes,
                multiUpload = $item.data("multi-upload");

            for (var i = 0; i < this.files.length; i++) {
                if (AWEContent.mediaValidateFileType(this.files[i].type, allowTypes)) {
                    AWEContent.ajaxUpload(this.files[i], {}, opts);
                }
                if (!multiUpload)
                    break;
            }
        });
    }

    $.fn.aweLibraryInit = function (multiSelect) {
        var $library = this,
            libraryURL = $library.data('url'),
            libraryType = $library.hasClass('js-my-file') ? 'my-file': 'library';

        // callback to load image data from server
        function loadImage() {
            var numberImages = $('.books-item .book-lib', $library).length;

            // add class loading to library
            $library.addClass('awe-lib-loading');

            $.post(libraryURL, {action: "get_upload_info", file_start: numberImages, type: libraryType}, function (response) {
                if (response) {
                    if ($.type(response) == 'string')
                        response = JSON.parse(response.trim());

                    // generate list library files
                    $.each(response.files, function() {
                        var file = this,
                            $item = $(
                                '<div class="book-lib">' +
                                '<i class="ic ac-icon-done"></i>' +
                                '<img src="" alt="book">' +
                                '<input type="hidden" name="file_data">' +
                                '</div>'
                            );

                        $("img", $item).attr("src", file.libraryThumbnail);
                        $("input", $item).val(JSON.stringify(file));
                        $(".books-item", $library).append($item);
                    });

                    // remove loading class
                    $library.removeClass('awe-lib-loading').data('allow-load-more', response.allowed_load_more);

                    // update scroll-bar
                    $('.scroll-bar', $library).perfectScrollbar('update');
                }
            });
        }

        if (!$library.data('initialized')) {
            // load data from server
            loadImage();

            // load library infinitive
            $('.scroll-bar', $library).scroll(function() {
                if ($library.data('allow-load-more') && !$library.hasClass('awe-lib-loading')) {
                    var $yScrollRail = $('.ps-scrollbar-y-rail', $(this)),
                        yRailHeight = $yScrollRail.height(),
                        $yScrollBar = $('.ps-scrollbar-y', $yScrollRail),
                        scrollBarTop = parseInt($yScrollBar.css('top')),
                        scrollBarHeight = $yScrollBar.height();

                    if (yRailHeight - scrollBarHeight - scrollBarTop < 10)
                        loadImage();
                }
            });

            // set flag to define library is initialized
            $library.data('initialized', 1);
        }
    };

    /**
     * Plugin for aweSelect element
     */
    $.fn.aweSelect = function(options, extra) {
        var $el = this;

        if ($.type(options) == 'string') {
            if ($el.data('select-initialized')) {
                var params = Array.prototype.slice.call(arguments, 1);

                switch (options) {
                    case 'value':
                        if (params.length) {
                            var setVal = params[0],
                                $op = $("li[data-value='"+ setVal +"']", $el);

                            if ($op.length != 1) {
                                $op = $('li:first', $el);
                                setVal = $op.attr('data-value');
                            }

                            $('.crr-item span.dis-change', $el).text($op.html());
                            $('.crr-item input[name=selected_value]', $el).val(setVal);
                            $el.trigger('change', {original: null, value: setVal});
                        }
                        else {
                            // return current value of select element
                            return $('.crr-item input[name=selected_value]', $el).val();
                        }
                        break;
                }

                return $el;
            }
        }

        $el.click(function(event) {
            event.preventDefault();
            $('.content-drop', $el).stop(true).slideToggle(200);
        });
        $('ul.content-drop', $el).delegate('> li', 'click', function(event) {
            event.preventDefault();

            var $value = $('input[name=selected_value]', $el),
                currentValue = $value.val(),
                newValue = $(this).attr('data-value');

            $value.val(newValue);
            $('span.dis-change', $el).html($(this).html());
            $el.trigger('change', {original: currentValue, value: newValue});
        });
        $(document).click(function(event) {
            if (!$(event.target).closest($el).length) {
                $('.content-drop', $el).stop(true).slideUp(200);
            }
        });

        // set flag to define element is
        $el.data('select-initialized', 1);

        return $el;
    }

    /**
     * Plugin for font settings elements
     * @returns {$.fn}
     */
    $.fn.aweFont = function (options, extra) {
        var $el = this,
            $fontFamily = $('.awe-font-family', this),
            $fontStyle = $('.awe-font-style', this),
            $textAlign = $('.awe-text-align', this),
            $fontSize = $('.awe-font-size', this),
            $lineHeight = $('.awe-line-spacing', this),
            $letterSpacing = $('.awe-letter-spacing', this);

        function processFontStyle(fontStyle) {
            var fontWeight = parseInt(fontStyle),
                cssStyle = {'font-weight': fontWeight, 'font-style': ''},
                styleName;

            switch (fontWeight) {
                case 100:
                    styleName = 'Thin';
                    break;

                case 200:
                    styleName = 'Extra-Light';
                    break;

                case 300:
                    styleName = 'Light';
                    break;

                case 400:
                    styleName = 'Normal';
                    break;

                case 500:
                    styleName = 'Medium';
                    break;

                case 600:
                    styleName = 'Semi-Bold';
                    break;

                case 700:
                    styleName = 'Bold';
                    break;

                case 800:
                    styleName = 'Extra-Bold';
                    break;

                case 900:
                    styleName = 'Ultra-Bold';
                    break;

                case -1:
                    styleName = 'Default';
                    cssStyle['font-weight'] = '';
                    break;
            }

            if (fontStyle.indexOf('italic') != -1) {
                styleName += ' Italic';
                cssStyle['font-style'] = 'italic';
            }

            return {name: styleName, style: cssStyle}
        }

        // callback to set element value
        function setValue(elementName, value) {
            switch (elementName) {
                case 'fontFamily':
                    // set font family element value
                    $('span.type-font', $fontFamily).text(value);
                    $fontFamily.data('font-family', value);
                    break;

                case 'fontStyle':
                    $fontStyle.aweSelect('value', value);
                    break;
                
                case 'textAlign':
                    $textAlign.aweSelect('value', value);
                    break;

                case 'fontSize':
                    $fontSize.aweSlider('value', value);
                    break;

                case 'lineHeight':
                    $lineHeight.aweSlider('value', value);
                    break;

                case 'letterSpacing':
                    $letterSpacing.aweSlider('value', value);
                    break;
            }
        }

        // process method
        if ($.type(options) == 'string') {
            if ($el.data('initialized')) {
                var method = options,
                    parameters = Array.prototype.slice.call(arguments, 1);

                switch (method) {
                    case 'options':
                        if ($.type(parameters[0]) == 'object') {
                            // set values for elements
                            $.each(parameters[0], function(attr, value) {
                                setValue(attr, value);
                            });
                        }
                        break;

                    default:
                        throw Error('aweFont: no such method "' + options +'"');
                        break;
                }
            }
            else
                throw Error('Error: cannot call methods on aweFont prior to initialization')

            return $el;
        }

        // handle click to font family element
        $fontFamily.click(function (event) {
            event.preventDefault();
            AWEContent.Panels.fontPanel.changeFont($fontFamily);
        }).change(function (event, params) {
            if (params) {
                if (!params.previewFont) {
                    setValue('fontFamily', params.name);

                    // get list style for new font
                    $('ul.content-drop > li:not(:first)', $fontStyle).remove();
                    var styles = (params.fontStyles && $.type(params.fontStyles) === 'string') ? params.fontStyles.split(',') : [];

                    $.each(styles, function(id, style) {
                        style = processFontStyle(style);
                        $('ul.content-drop', $fontStyle).append("<li data-value='" + JSON.stringify(style.style) +"'>" + style.name + '</li>');
                    });
                    $fontStyle.aweSelect('value', '{"font-weight":"","font-style":""}').trigger('change', {original: '', value: '{"font-weight":"","font-style":""}'});
                }

                // get font name
                fontName = params.name;
            }

            // create event change fontFamily
            $el.trigger('fontFamilyChange', fontName);
        });

        // init for font weight
        $fontStyle.aweSelect().change(function(event, values) {
            $el.trigger('fontStyleChange', values);
        });

        // init for font align element
        $textAlign.aweSelect().bind('change', function(event, values) {
            $el.trigger('textAlignChange', values)
        });

        // init for font-size, font-line-spacing, font-letter-spacing
        $fontSize.aweSlider({
            type: 'slider',
            min: -1,
            max: 100,
            step: 1,
            allowType: true,
            allowLowerMin:false,
            default: -1
        }).change(function(event, values) {
            if (values.value == -1)
                $('.frame-display .display-font', $fontSize).text('DF');
            $el.trigger('fontSizeChange', values);
        });
        $letterSpacing.aweSlider({
            type: 'slider',
            min: -1,
            max: 20,
            step: 1,
            allowLowerMin: false,
            allowType: true,
            default: -1
        }).change(function(event, values) {
            if (values.value == -1)
                $('.frame-display .display-font', $letterSpacing).text('DF');
            $el.trigger('letterSpacingChange', values);
        });
        $lineHeight.aweSlider({
            type: 'slider',
            min: -1,
            max: 100,
            step: 1,
            allowType: true,
            allowLowerMin: false,
            default: -1
        }).change(function(event, values) {
            if (values.value == -1)
                $('.frame-display .display-font', $lineHeight).text('DF');
            $el.trigger('lineHeightChange', values);
        });

        // set initialized flag
        $el.data('initialized', 1);

        return $el;
    }

    $.fn.aweMediaElementInit = function () {
        var $context = this;

        $context.click(function () {
            AWEContent.Panels.mediaPanel.changeMediaFile($context, false);
        });
        $("span.delete-bg-img", this).click(function (event) {
            event.stopPropagation();
            $(".img-bg", $context).css("background-image", "");
            $("input[name=selected_media]", $context).val("").trigger("change");
        });

        $("input[name=selected_media]", this).change(function () {
            if ($(this).val())
                $("span.delete-bg-img", $context).show();
            else
                $("span.delete-bg-img", $context).hide();
        });
    }

    $.fn.initBoxModel = function (settings) {
        var $el = this;

        function getBorderStyle(border) {
            var borderStyle = border.split(" ");

            if (!borderStyle[2])
                borderStyle[2] = "";
            borderStyle[0] = borderStyle[0].replace("px", "");

            return borderStyle;
        }

        function initBorderTab() {
            var borderTop = getBorderStyle(settings.borderTop),
                borderRight = getBorderStyle(settings.borderRight),
                borderLeft = getBorderStyle(settings.borderLeft),
                borderBottom = getBorderStyle(settings.borderBottom);

            $(".custom-border-top .border-unit-spectrum", $el).spectrum("set", borderTop[2]);
            $(".custom-border-top input[name=changing-color]", $el).val(borderTop[2]);
            $(".custom-border-top span.display-font", $el).text(borderTop[0]);
            $(".custom-border-top span.type-border", $el).text(borderTop[1]);

            $(".custom-border-right .border-unit-spectrum", $el).spectrum("set", borderRight[2]);
            $(".custom-border-right input[name=changing-color]", $el).val(borderTop[2]);
            $(".custom-border-right span.display-font", $el).text(borderRight[0]);
            $(".custom-border-right span.type-border", $el).text(borderRight[1]);

            $(".custom-border-bottom .border-unit-spectrum", $el).spectrum("set", borderBottom[2]);
            $(".custom-border-bottom input[name=changing-color]", $el).val(borderTop[2]);
            $(".custom-border-bottom span.display-font", $el).text(borderBottom[0]);
            $(".custom-border-bottom span.type-border", $el).text(borderBottom[1]);

            $(".custom-border-left .border-unit-spectrum", $el).spectrum("set", borderLeft[2]);
            $(".custom-border-left input[name=changing-color]", $el).val(borderTop[2]);
            $(".custom-border-left span.display-font", $el).text(borderLeft[0]);
            $(".custom-border-left span.type-border", $el).text(borderLeft[1]);

            $(".awe-border input[name=toggle_value]", $el).val(settings.enabledCustomBorder).trigger("change", true);
            if (settings.enabledConstraintBorder)
                $(".awe-border .trigger-uniform", $el).addClass("enabled").trigger("change", true);
            else
                $(".awe-border .trigger-uniform", $el).removeClass("enabled").trigger("change", true);
        }

        function initBorderRadiusTab() {
            $(".border-radius-tl span.display-font", $el).text(settings.borderRadiusTopLeft);
            $(".border-radius-tl .slider-val", $el).slider("value", settings.borderRadiusTopLeft);
            $(".border-radius-tr span.display-font", $el).text(settings.borderRadiusTopRight);
            $(".border-radius-tr .slider-val", $el).slider('value', settings.borderRadiusTopRight);
            $(".border-radius-bl span.display-font", $el).text(settings.borderRadiusBottomLeft);
            $(".border-radius-bl .slider-val", $el).slider('value', settings.borderRadiusBottomLeft);
            $(".border-radius-br span.display-font", $el).text(settings.borderRadiusBottomRight);
            $(".border-radius-br .slider-val", $el).slider("value", settings.borderRadiusBottomRight);
            $(".awe-border-radius input[name=toggle_value]", $el).val(settings.enabledCustomBorderRadius).trigger("change", true);
            if (settings.enabledConstraintBorderRadius)
                $(".awe-border-radius .trigger-uniform", $el).addClass("enabled").trigger("change", true);
            else
                $(".awe-border-radius .trigger-uniform", $el).removeClass("enabled").trigger("change", true);
        }

        function initBoxModelTab(type) {
            var prefix = type;
            $(".custom-" + type + "-left span.display-font", $el).text(settings[prefix + "Left"]);
            $(".custom-" + type + "-left .slider-val", $el).slider("value", settings[prefix + "Left"]);
            $(".custom-" + type + "-right span.display-font", $el).text(settings[prefix + "Right"]);
            $(".custom-" + type + "-right .slider-val", $el).slider("value", settings[prefix + "Right"]);
            $(".custom-" + type + "-top span.display-font", $el).text(settings[prefix + "Top"]);
            $(".custom-" + type + "-top .slider-val", $el).slider("value", settings[prefix + "Top"]);
            $(".custom-" + type + "-bottom span.display-font", $el).text(settings[prefix + "Bottom"]);
            $(".custom-" + type + "-bottom .slider-val", $el).slider("value", settings[prefix + "Bottom"]);


            $(".awe-" + type + " input[name=toggle_value]", $el).val(settings["enabledCustom" + prefix.charAt(0).toUpperCase() + prefix.slice(1)]).trigger("change", true);
            if (settings["enabledConstraint" + prefix.charAt(0).toUpperCase() + prefix.slice(1)])
                $(".awe-" + type + " .trigger-uniform", $el).addClass("enabled").trigger("change", true);
            else
                $(".awe-" + type + " .trigger-uniform", $el).removeClass("enabled").trigger("change", true);
        }

        // Process custom border radius
        initBorderTab();
        initBorderRadiusTab();
        initBoxModelTab("padding");
        initBoxModelTab("margin");
    }

    $.fn.initBoxModelPanel = function (panelView, attrName) {
        function getBoxModelSettingsAttr(panelView, attrName) {
            if (panelView.editingModel instanceof AWEContent.Models.Item)
                return panelView.editingModel.get(attrName);
            else
                return panelView.editingModel.get("settings").get(attrName);
        }

        function getBorderValue($borderBox, isCancel) {
            var color = $("input[name=changing-color]", $borderBox).val(),
                width = $("span.display-font", $borderBox).text() + $("span.font-unit", $borderBox).text(),
                style = $("span.type-border", $borderBox).text();
            if (isCancel)
                color = $("input.border-unit-spectrum", $borderBox).val();
            if (style != "none" && parseInt($("span.display-font", $borderBox).text()) > 0)
                return width + " " + style + " " + color;

            return "";
        }

        // Init for border setting elements
        $(".awe-border input[name=toggle_value]", this).change(function (event, isInitPanel) {
            if (isInitPanel) return;

            var boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);
            boxModelSettings.set("enabledCustomBorder", parseInt($(this).val()));
        });
        $(".awe-border .trigger-uniform", this).change(function (event, isInitPanel) {
            if (isInitPanel) return;

            var boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);
            if ($(this).hasClass("enabled"))
                boxModelSettings.set("enabledConstraintBorder", 1);
            else
                boxModelSettings.set("enabledConstraintBorder", 0);
        });
        $(".awe-border .md-box", this).change(function (event, isCancel) {
            var borderStyle = getBorderValue($(this), isCancel),
                boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);
            if ($(this).hasClass("custom-border-top"))
                boxModelSettings.set("borderTop", borderStyle);
            else if ($(this).hasClass("custom-border-right"))
                boxModelSettings.set("borderRight", borderStyle);
            else if ($(this).hasClass("custom-border-bottom"))
                boxModelSettings.set("borderBottom", borderStyle);
            else
                boxModelSettings.set("borderLeft", borderStyle);
        });

        // Init for border radius setting elements
        $(".awe-border-radius input[name=toggle_value]", this).change(function (event, isInitPanel) {
            if (isInitPanel) return;
            var boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);
            boxModelSettings.set("enabledCustomBorderRadius", parseInt($(this).val()));
        });
        $(".awe-border-radius .trigger-uniform", this).change(function (event, isInitPanel) {
            if (isInitPanel) return;

            var boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);
            if ($(this).hasClass("enabled"))
                boxModelSettings.set("enabledConstraintBorderRadius", 1);
            else
                boxModelSettings.set("enabledConstraintBorderRadius", 0);
        });
        $(".awe-border-radius .md-box", this).change(function () {
            var borderRadius = $("span.display-font", $(this)).text(),
                unit = $("span.font-unit", $(this)).text(),
                boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);

            if ($(this).hasClass("border-radius-tl"))
                boxModelSettings.set("borderRadiusTopLeft", borderRadius, {unit: unit});
            else if ($(this).hasClass("border-radius-tr"))
                boxModelSettings.set("borderRadiusTopRight", borderRadius, {unit: unit});
            else if ($(this).hasClass("border-radius-bl"))
                boxModelSettings.set("borderRadiusBottomLeft", borderRadius, {unit: unit});
            else
                boxModelSettings.set("borderRadiusBottomRight", borderRadius, {unit: unit});
        });

        // Init for padding setting elements
        $(".awe-padding input[name=toggle_value]", this).change(function (event, isInitPanel) {
            if (isInitPanel) return;
            var boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);
            boxModelSettings.set("enabledCustomPadding", parseInt($(this).val()));
        });
        $(".awe-padding .trigger-uniform", this).change(function (event, isInitPanel) {
            if (isInitPanel) return;

            var boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);
            if ($(this).hasClass("enabled"))
                boxModelSettings.set("enabledConstraintPadding", 1);
            else
                boxModelSettings.set("enabledConstraintPadding", 0);
        });
        $(".awe-padding .md-box", this).change(function () {
            var padding = $("span.display-font", $(this)).text(),
                unit = $("span.font-unit", $(this)).text(),
                boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);

            if ($(this).hasClass("custom-padding-top"))
                boxModelSettings.set("paddingTop", padding, {unit: unit});
            else if ($(this).hasClass("custom-padding-right"))
                boxModelSettings.set("paddingRight", padding, {unit: unit});
            else if ($(this).hasClass("custom-padding-bottom"))
                boxModelSettings.set("paddingBottom", padding, {unit: unit});
            else
                boxModelSettings.set("paddingLeft", padding, {unit: unit});
        });

        // Init for margin setting elements
        $(".awe-margin input[name=toggle_value]", this).change(function (event, isInitPanel) {
            if (isInitPanel) return;

            var boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);
            boxModelSettings.set("enabledCustomMargin", parseInt($(this).val()));
        });
        $(".awe-margin .trigger-uniform", this).change(function (event, isInitPanel) {
            if (isInitPanel) return;

            var boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);
            if ($(this).hasClass("enabled"))
                boxModelSettings.set("enabledConstraintMargin", 1);
            else
                boxModelSettings.set("enabledConstraintMargin", 0);
        });
        $(".awe-margin .md-box", this).change(function () {
            var margin = $("span.display-font", $(this)).text(),
                unit = $("span.font-unit", $(this)).text(),
                boxModelSettings = getBoxModelSettingsAttr(panelView, attrName);

            if ($(this).hasClass("custom-margin-top"))
                boxModelSettings.set("marginTop", margin, {unit: unit});
            else if ($(this).hasClass("custom-margin-right"))
                boxModelSettings.set("marginRight", margin, {unit: unit});
            else if ($(this).hasClass("custom-margin-bottom"))
                boxModelSettings.set("marginBottom", margin, {unit: unit});
            else
                boxModelSettings.set("marginLeft", margin, {unit: unit});
        });
    }

    $.fn.renderItemDefaultBoxModel = function (settings, $overlay) {
        function processBoxRadius($el) {
            var unit = settings.borderRadiusUnit,
                css = {
                    'border-top-left-radius': settings.borderRadiusTopLeft + unit,
                    'border-top-right-radius': settings.borderRadiusTopRight + unit,
                    'border-bottom-right-radius': settings.borderRadiusBottomRight + unit,
                    'border-bottom-left-radius': settings.borderRadiusBottomLeft + unit
                };
            $el.css(css);
        }

        function processBoxUnit(type, $el) {
            var prefix = type,
                css = {},
                unit = '';
            if (settings[type + 'Unit'])
                unit = settings[type + 'Unit'];
            css[prefix + '-left'] = settings[prefix + 'Left'] + unit;
            css[prefix + '-right'] = settings[prefix + 'Right'] + unit;
            css[prefix + '-top'] = settings[prefix + 'Top'] + unit;
            css[prefix + '-bottom'] = settings[prefix + 'Bottom'] + unit;
            $el.css(css);

        }

        if (settings.enabledCustomBorder)
            processBoxUnit('border', $(this));
        if (settings.enabledCustomBorderRadius) {
            processBoxRadius($(this));
            if ($overlay)
                processBoxRadius($overlay);
        }
        if (settings.enabledCustomPadding) {
            processBoxUnit('padding', $(this));
        }
        if (settings.enabledCustomMargin)
            processBoxUnit('margin', $(this));

    };

    $.fn.renderChangeSettingBoxModel = function (key, value, model, $overlay) {
        function borderCss($el, value) {
            if (value) {
                var css = {
                    'borderTop': model.get('borderTop'),
                    'borderLeft': model.get('borderLeft'),
                    'borderRight': model.get('borderRight'),
                    'borderBottom': model.get('borderBottom')
                };
                return $el.css(css);
            }
            else {
                return $el.css('border', '');
            }
        }

        function borderRadiusCss($el, model, $overlay) {
            if (model.get('enabledCustomBorderRadius')) {
                var unit = model.get('borderRadiusUnit'),
                    css = {
                        'borderTopLeftRadius': model.get('borderRadiusTopLeft') + unit,
                        'borderTopRightRadius': model.get('borderRadiusTopRight') + unit,
                        'borderBottomLeftRadius': model.get('borderRadiusBottomLeft') + unit,
                        'borderBottomRightRadius': model.get('borderRadiusBottomRight') + unit
                    };
                $el.css(css);
                if ($overlay)
                    $overlay.css(css);
            }
            else {
                $el.css('border-radius', '');
                if ($overlay)
                    $overlay.css('border-radius', '');
            }
        }

        function boxUnitCss($el, type, value) {
            var unit = model.get(type + 'Unit'),
                css = {};
            css[type + '-top'] = model.get(type + 'Top') + unit;
            css[type + '-right'] = model.get(type + 'Right') + unit;
            css[type + '-left'] = model.get(type + 'Left') + unit;
            css[type + '-bottom'] = model.get(type + 'Bottom') + unit;
            if (value)
                return $el.css(css);
            else
                return $el.css(type, '');
        }

        var self = this,
            flagContinue = 0;
        switch (key) {
            case 'enabledCustomBorder' :
                borderCss($(this), value);
                break;
            case 'borderTop':
            case 'borderRight':
            case 'borderLeft':
            case 'borderBottom':
                $(this).css(key, value);
                break;
            case 'paddingTop':
            case 'paddingRight':
            case 'paddingLeft':
            case 'paddingBottom':
                $(this).css(key, value + model.get('paddingUnit'));
                break;
            case 'marginTop':
            case 'marginRight':
            case 'marginLeft':
            case 'marginBottom':
                $(this).css(key, value + model.get('marginUnit'));
                break;
            case 'borderRadiusTopLeft':
            case 'borderRadiusTopRight':
            case 'borderRadiusBottomLeft':
            case 'borderRadiusBottomRight':
            case 'enabledCustomBorderRadius':
                borderRadiusCss($(this), model, $overlay);
                break;
            case 'enabledCustomPadding':
                boxUnitCss($(this), 'padding', value);
                break;
            case 'enabledCustomMargin':
                boxUnitCss($(this), 'margin', value);
                break;
            default :
                flagContinue = 1;
        }
        if (!flagContinue) {
            this.closest('.awe-section').trigger('resize');
            return false;
        }
    };

    /*=================================================== Attributes =====================================================*/
    $.fn.initAttributesPanel = function (panelView) {
        $('input[name=enabled_custom_attributes]', this).change(function (event, isPanel) {
            if (!isPanel) {
                panelView.editingModel.set('customEnableAttributes', parseInt($(this).val()));
            }
        });

        $('input[name=attributes_data]', this).change(function (event, attr) {
            if (attr) {
                var dataAttr = panelView.editingModel.get('customDataAttributes'),
                    dataArr = [], new_action;
                if ($.parseJSON(dataAttr).length) {
                    dataArr = $.parseJSON(dataAttr);
                    switch (attr.action) {
                        case 'addAttr' :
                            dataArr.push({
                                attrName: attr.data.attrName,
                                attrValue: attr.data.attrValue
                            });
                            break;
                        case 'updateAttr' :
                            $.each(dataArr, function (index, value) {
                                if (value.attrName == attr.data.attrName) {
                                    value.attrValue = attr.data.attrValue;
                                }
                            });
                            break;
                        case 'rmAttr' :
                            $.each($.parseJSON(dataAttr), function (index, value) {
                                if (value.attrName == attr.data.attrName) {
                                    dataArr.splice(index, 1);
                                }
                            });
                            break;
                    }
                }
                else {
                    dataArr.push({
                        attrName: attr.data.attrName,
                        attrValue: attr.data.attrValue
                    });
                }
                new_action = {
                    newAction: attr.action,
                    newAttrName: attr.data.attrName,
                    newAttrValue: attr.data.attrValue
                };
                panelView.editingModel.set('customActionAttributes', new_action);
                panelView.editingModel.set('customDataAttributes', JSON.stringify(dataArr));
            }
        });
    };

    $.fn.initAttributes = function (enableAttributes, data) {
        $('input[name=enabled_custom_attributes]', this).val(enableAttributes).trigger('change', {isPanel: true});
        $('input[name=attributes_data]', this).val(data).trigger('change');
    };

    $.fn.renderItemDefaultAttributes = function (enableAttr, data) {
        var self = this;
        if (enableAttr && data != '[]') {
            $.each($.parseJSON(data), function (index, value) {
                var attrName = 'data-' + value.attrName;
                var attrValue = value.attrValue;
                self.attr(attrName, attrValue);
            });
        }
    };

    $.fn.renderChangeSettingsAttributes = function (key, value, data) {
        var self = this;
        if (key == 'customEnableAttributes') {
            var data_json = $.parseJSON(data);
            $.each(data_json, function (i, attr) {
                value ? self.attr('data-' + attr.attrName, attr.attrValue) : self.removeAttr('data-' + attr.attrName);
            });
        }
        if (key == 'customActionAttributes') {
            value.newAction == 'rmAttr' ? self.removeAttr('data-' + value.newAttrName) : self.attr('data-' + value.newAttrName, value.newAttrValue);
        }
    };

    /*==================================================== Animations ====================================================*/
    $.fn.aweAnimation = function (options, extra) {
        var AweAnimation = function ($el, options) {
            var defaultOpts = {
                enabled: 0,
                animations: '{"type" : "none"}',
                previewEl: null
            };

            this.options = $.extend(defaultOpts, options);
            this.$el = $el;
            this.initialize();
        }

        AweAnimation.prototype = {
            constructor: AweAnimation,
            initialize: function () {
                var _self = this;

                this.$el.click(function () {
                    $('> .togg-status', _self.$el).toggleClass("active");
                    if ($('> .togg-status', _self.$el).hasClass("active")) {
                        _self.options.enabled = 1;
                        $("> .togg-status input[name=enabled_custom_animation]", _self.$el).val(1).trigger('change');
                        $('> .togg-status', _self.$el).next().show().trigger("click");
                    }
                    else {
                        _self.options.enabled = 0;
                        $('> .togg-status', _self.$el).next().hide();
                        $("input[name=enabled_custom_animation]", $('> .togg-status', _self.$el)).val(0).trigger('change');
                    }
                });
                $("input[name=enabled_custom_animation]", _self.$el).change(function (event) {
                    event.stopPropagation();
                    var value = parseInt($(this).val());

                    if (value) {
                        $(this).parent().addClass("active");
                        $(this).parent().next().show();
                    }
                    else {
                        $(this).parent().removeClass("active");
                        $(this).parent().next().hide();
                    }

                    _self.$el.trigger('change', _self.options)
                });
                $(".js-edit-animations", this.$el).click(function (event) {
                    event.stopPropagation();
                    AWEContent.Panels.customAnimationsPanel.editAnimation(_self.$el);
                });
            },
            set: function (animationData) {
                this.options = $.extend(this.options, animationData);
                $("input[name=enabled_custom_animation]", this.$el).val(this.options.enabled).trigger('change');
            },
            get: function () {
                return this.options;
            }
        }

        var output = false,
            params = Array.prototype.slice.call(arguments, 1),
            optsType = $.type(options);

        $.each(this, function () {
            var $el = $(this),
                aweAnimation = $el.data('awe-animation');

            if (optsType === 'string') {
                if (aweAnimation) {
                    if (options === 'value') {
                        if (params[0] !== undefined) {
                            switch ($.type(params[0])) {
                                case 'object':
                                    aweAnimation.set(params[0]);
                                    break;

                                case 'string':
                                    var opt = {};
                                    opt[params[0]] = params[1];
                                    aweAnimation.set(opt);
                                    break

                                default:
                                    throw Error('aweAnimation::value did not support this type parameter.');
                            }
                        }
                        else {
                            if (!output) output = [];
                            output.push(aweAnimation.get());
                        }
                    }
                    else
                        throw Error('aweAnimation: no method such ' + options + ' exist.');
                }
                else
                    throw Error('Error: cannot call methods on aweBoxModel prior to initialization');
            }
            else if (options === undefined || optsType === 'object') {
                if (aweAnimation)
                    aweAnimation.set(options);
                else {
                    aweAnimation = new AweAnimation($el, options);
                    $el.data('awe-animation', aweAnimation);
                }
            }
        });

        if (output) {
            if (output.length === 1)
                return output[0];
            return output;
        }

        return this;
    }
    $.fn.processAnimations = function (animation, prevAnimation) {
        var $el = this;

        if (typeof animation === 'string')
            animation = JSON.parse(animation);
        if (typeof prevAnimation === 'string')
            prevAnimation = JSON.parse(prevAnimation);

        // reset delay animation
        $el.css({
            'animation-duration': '',
            'animation-delay': '',
        });

        // clear animation timeout
        if ($el.data('animation-timeout'))
            clearTimeout($el.data('animation-timeout'));

        // remove prev animation
        if (prevAnimation && prevAnimation.type && prevAnimation.type != 'none') {
            $el.removeClass('animated ' + prevAnimation.type);
        }

        // play new animation
        setTimeout(function() {
            if (animation && animation.type && animation.type != 'none') {
                $el.css({
                    'animation-duration': animation.duration + 'ms',
                    'animation-delay': animation.delay + 'ms',
                });

                $el.addClass(animation.type).addClass('animated');

                var timeout = setTimeout(function () {
                    $el.removeData('animation-timeout');
                    $el.removeClass('animated ' + animation.type);
                    $el.css({
                        'animation-duration': '',
                        'animation-delay': '',
                    });
                }, animation.duration + animation.delay);

                $el.data('animation-timeout', timeout);
            }
        }, 50)
    };

    /*============================================= Regex ID Youtube & Vimeo =============================================*/
    $.processVideo = function (url) {
        function vimeoID(url) {
            var vimeo_Reg = /https?:\/\/(?:www\.)?vimeo.com\/(?:channels\/(?:\w+\/)?|groups\/([^\/]*)\/videos\/|album\/(\d+)\/video\/|)(\d+)(?:$|\/|\?)/;
            var match = url.match(vimeo_Reg);
            if (match) {
                return match[3];
            } else {
                return "";
            }
        }

        function youtubeID(url) {
            var regExp = /^.*((youtu.be\/)|(v\/)|(\/u\/\w\/)|(embed\/)|(watch\?))\??v?=?([^#\&\?]*).*/,
                match = url.match(regExp);
            return (match[7] != undefined) ? match[7] : '';
        }

        if (url.indexOf('youtu') != -1) {
            var idYt = youtubeID(url);
            return {
                id: idYt,
                attrVideo: '//www.youtube.com/embed/' + idYt + '?autoplay=0&loop=1&controls=1&showinfo=0&volume=1&enablejsapi=1',
                typeVideo: 'youtube'
            };
        }
        if (url.indexOf('vimeo') != -1) {
            var vmID = vimeoID(url);
            return {
                id: vmID,
                attrVideo: '//player.vimeo.com/video/' + vmID + '?autoplay=0&loop=1&fullscreen=1',
                typeVideo: 'vimeo'
            };
        }
        return {
            id: '',
            attrVideo: '//www.youtube.com/embed/',
            typeVideo: ''
        };
    };

    /*==================================================== Google Font ===================================================*/
    $.fn.processGoogleFont = function (fontWeight, dataWeight) {
        var self = this,
            $fontWegiht = self.parent().next(),
            font = self.attr('data-font');
        if (dataWeight == 'none') {
            $('input', $fontWegiht).val('').trigger('change');
        }
        else {
            var checkNormal = 0, temp = '', isFontWeight = 0;
            $('.content-drop li', $fontWegiht).hide();
            $.each(dataWeight.split(','), function (index, value) {
                switch (value.substr(0, 3)) {
                    case '100' :
                        temp = 'thin';
                        break;
                    case '200' :
                        temp = 'extra-light';
                        break;
                    case '300' :
                        temp = 'light';
                        break;
                    case '400' :
                        temp = 'normal';
                        checkNormal = 1;
                        break;
                    case '500':
                        temp = 'semi-bold';
                        break;
                    case '600' :
                        temp = 'semi-bold';
                        break;
                    case '700' :
                        temp = 'bold';
                        break;
                    case '800' :
                        temp = 'extra-bold';
                        break;
                    case '900' :
                        temp = 'ultra-bold';
                        break;
                    case 'default':
                        temp = 'Default'
                        break;
                }
                if (fontWeight == temp) {
                    isFontWeight = 1;
                }
                $('.content-drop li[data-value=' + temp + ']', $fontWegiht).show();
            });
            temp = checkNormal ? 'normal' : temp;
            $('.dis-change', $fontWegiht).text(function () {
                $('input', $fontWegiht).val(temp).trigger('change');
                return $(this).parent().next().find('li[data-value=' + temp + ']').text();
            });
        }
    };

    $.fn.aweButtonElementInit = function () {
        var self = this;
        $('.image-content, .control-image', self).click(function () {
            AWEContent.Panels.mediaPanel.changeMediaFile(self, false);
        });
    };
    $.fn.aweGalleryElementInit = function () {
        var self = this,
            indexBefore, indexAfter;
        $('.library', self).click ( function(){
            $('.select-image', self).trigger('click');
        });
        $('.select-image', self).click(function () {
            AWEContent.Panels.mediaPanel.changeMediaFile($(this), true);
        });
        self.delegate('.book-lib', 'click', function (event) {
            event.stopPropagation();
            console.log('dasdasdasdas')
            AWEContent.Panels.mediaPanel.changeMediaFile($(this), false);
        });
    };

    /*=============================================Event Drag Image For Slide =============================================*/
    $.fn.dragImageUpload = function (multiUpload) {
        function sendXMLHttpRequest(files, options) {
            if (!files.length)
                return false;

            var allowTypes = options.acceptTypes,
                file = files.pop();
            if (AWEContent.mediaValidateFileType(file.type, allowTypes)) {
                var formData = new FormData(),
                    request = new XMLHttpRequest();

                formData.append("awe_media_upload", file);
                request.open("POST", options.url);
                request.onreadystatechange = function () {

                    if (this.readyState === 4) {
                        if (this.status === 200) {
                            var $item = $('<div class="book-lib"><i class="ic ac-icon-done"></i><img src="" alt="book"><input type="hidden" name="file_data"></div>'),
                                $aweUpload = $('#awe-media-panel-awe-media-upload'),
                                $bookItems = $('.books-item', $aweUpload),
                                data = '';
                            try {
                                data = $.parseJSON(this.responseText.trim());
                            }
                            catch (e) {
                            }
                            if (typeof data == 'object') {
                                $('img', $item).attr('src', data.file_url);
                                $('input', $item).val(JSON.stringify(data));
                                var index = -1;
                                $.each($('img', $bookItems), function () {
                                    var tempSrc = $(this).attr('src');
                                    if (tempSrc == data.file_url)
                                        index = $(this).closest('.book-lib').index();

                                });
                                if (index == -1)
                                    $bookItems.prepend($item);
                                else {
                                    $bookItems.prepend($('.book-lib', $bookItems).eq(index));
                                }
                                self.trigger('change', {responseImage: data})
                            }
                        }
                        else
                            console.log("Upload files failed!");
                        sendXMLHttpRequest(files, options)
                    }
                };
                request.send(formData);
            }
        }

        var self = this,
            options = $.optionUpload;
        if ("draggable" in document.createElement("span")) {
            var $el = this,
                uploader = this[0];

            uploader.ondragover = function (event) {
                $(this).addClass("dragg-over");
                event.preventDefault();
            };
            uploader.ondragleave = function (event) {
                $(this).removeClass("dragg-over");
                event.preventDefault();
            };
            uploader.ondrop = function (event) {
                event.preventDefault();
//                var allowTypes = options.acceptTypes,
//                    files = event.dataTransfer.files;
                $(this).removeClass("dragg-over");

                var array = $.map(event.dataTransfer.files, function (value, index) {
                    return [value];
                });
                sendXMLHttpRequest(array, options);
            }
        }

    };

    $.fn.aweUploadImageInit = function () {
        var self = this;
        self.dragImageUpload(false);
        self.change(function (event, data) {
            if (data && data.responseImage)
                $('input[name=selected_media]', self).val(JSON.stringify(data)).trigger('change', {action: 'drag', data: data});
        });
        $('.controls-upload', self).click(function (event) {
            event.preventDefault();
            AWEContent.Panels.mediaPanel.changeMediaFile(self, false);
        });
        $('.image-content', self).change(function () {
            if ($(this).attr('src') != '')
                $(this).next().addClass('active');
            else
                $(this).next().removeClass('active');
        });
        $('.remove-image', self).click(function () {
            $(this).removeClass('active');
            $(this).prev().attr('src', '');
            $(this).parent().next().val('').trigger('change', {action: 'remove'});
        });

    }
    $.fn.aweSlideImageInit = function () {
        var self = this;
        $('.slide-image-controls .nav-prev', self).click(function () {
            var $customImage = $(this).parent().next(),
                indexActive = parseInt($customImage.val()),
                newActive;
            if (indexActive == 0) {
                newActive = 3;
            }
            else {
                newActive = indexActive - 1;
            }
            $customImage.val(newActive).trigger('change');
        });
        $('.slide-image-controls .nav-next', self).click(function () {
            var $customImage = $(this).parent().next(),
                indexActive = parseInt($customImage.val()),
                newActive;
            if (indexActive == 3) {
                newActive = 0;
            }
            else {
                newActive = indexActive + 1;
            }
            $customImage.val(newActive).trigger('change');
        });
    }

    $.fn.defaultResponsive = function (settings) {
        if (!settings.lgResponsive) {
            this.addClass('lg-hidden');
        }
        if (!settings.xsResponsive) {
            this.addClass('xs-hidden');
        }
        if (!settings.smResponsive) {
            this.addClass('sm-hidden');
        }
        if (!settings.mediumResponsive) {
            this.addClass('md-hidden');
        }
    }

    $.fn.changeResponsive = function (screen, value) {
        var self = this,
            flagContinue = 0;
        switch (screen) {
            case 'lgResponsive' :
                value ? self.removeClass('lg-hidden') : self.addClass('lg-hidden');
                break;
            case 'mediumResponsive' :
                value ? self.removeClass('md-hidden') : self.addClass('md-hidden');
                break;
            case 'smResponsive' :
                value ? self.removeClass('sm-hidden') : self.addClass('sm-hidden');
                break;
            case 'xsResponsive' :
                value ? self.removeClass('xs-hidden') : self.addClass('xs-hidden');
                break;
            default :
                flagContinue = 1;
        }
        if (!flagContinue)
            return false;

    }

    $.renderFontWeight = function (nameWeight) {
        var name = '';
        switch (nameWeight) {
            case 'thin' :
                name = '100';
                break;
            case 'extra-light' :
                name = '200';
                break;
            case 'light' :
                name = '300';
                break;
            case 'normal' :
                name = '400';
                break;
            case 'medium' :
                name = '500';
                break;
            case 'semi-bold' :
                name = '600';
                break;
            case 'bold' :
                name = '700';
                break;
            case 'extra-bold' :
                name = '800';
                break;
            case 'ultra-bold' :
                name = '900';
                break;
            default:
                name = '';
                break;
        }
        return name;
    }

    /**
     * Define function to parse JSON data
     */
    $.jsonParse = function(data) {
        var json;

        // check parameter value type
        if ($.type(data) != 'string') {}
            throw new Error('Parameter is not a string. You must past json string to parse it.');

        try {
            json = JSON.parse(data.trim())
        }
        catch (e) {
            json = null
        }

        return json;
    }
    $.imageLoaded = function(options, callback) {
        var seconds = 0,
            maxSeconds = 10,
            complete = false,
            done = false;

        if (options.maxSeconds) {
            maxSeconds = options.maxSeconds;
        }

        function tryImage() {
            if (done) { return; }
            if (seconds >= maxSeconds) {
                callback({ err: 'timeout' });
                done = true;
                return;
            }
            if (complete && img.complete) {
                if (img.width && img.height) {
                    callback({ img: img });
                    done = true;
                    return;
                }
                callback({ err: '404' });
                done = true;
                return;
            } else if (img.complete) {
                complete = true;
            }
            seconds++;
            callback.tryImage = setTimeout(tryImage, 1000);
        }
        var img = new Image();
        img.onload = tryImage();
        img.src = options.src;
        tryImage();
    }

    /**
     * create plugin to get image URL
     */
    $.fn.aweImageURL = function(options) {
        var $el = this,
            default_options = {
                fid: [],
                styles: [],
                success: function(el, fid, style, files) {}
            },
            styles = 'none',
            strFid = '';

        options = $.extend(default_options, options);

        if (options.styles.length)
            styles = options.styles.join(',');

        if (options.fid.length)
            strFid = options.fid.join(',');

        if (strFid != '-1') {
            // create request to server to get image URL
            $.post(AWEContent.Path.imageStyleURL, {fids: strFid, styles: styles}, function(response) {
                options.success($el, options.fid, options.styles, response);
            });
        }
        else 
            options.success($el, options.fid, options.styles, {});
    }

    $.parseJSON = function (data) {
        var jsonObj;
        if ($.type(data) === 'string') {
            try {
                jsonObj = JSON.parse(data);
            }
            catch (error) {
                jsonObj = null;
            }
        }
        else if ($.type(data) === 'object')
            jsonObj = data;


        return jsonObj;
    }
})(jQuery);

