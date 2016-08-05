(function ($) {
    Drupal.behaviors.md_hillter = {
        attach: function () {
        }
    };
    $(window).load(function () {

/////////////////////////////////////////////// JQUERY UI TABS ////////////////////////////////////////////////////////
        var tabCookieName = "maintabs";
        var subTab1CookieName = "subtabs1";
        var subTab2CookieName = "subtabs2";
        $(function () {
            // Save cookie for each tab group, each tab group need unique cookie name
            $("#md-framewp-body").tabs({
                active: ($.cookie(tabCookieName) || 0),
                activate: function (event, ui) {
                    var newIndex = ui.newTab.parent().children().index(ui.newTab);
                    $.cookie(tabCookieName, newIndex, {expires: 1});
                }
            });
            $("#md-general, #md-design, #md-display, #md-text-typography,#md-code,#md-config").tabs({
                active: ($.cookie(subTab1CookieName) || 0),
                activate: function (event, ui) {
                    var newIndex = ui.newTab.parent().children().index(ui.newTab);
                    $.cookie(subTab1CookieName, newIndex, {expires: 1});
                }
            });
            $(".md-subtabs").tabs({
                active: ($.cookie(subTab2CookieName) || 0),
                activate: function (event, ui) {
                    var newIndex = ui.newTab.parent().children().index(ui.newTab);
                    $.cookie(subTab2CookieName, newIndex, {expires: 1});
                }
            })
        });

        //ADD CLASS TO ALL BUTTON
        $("input[type='submit'],a.button").addClass("md-button");
        /*========== Script ON-OFF , ENABLE - DISABLEr ==========*/
        $(".click-disable").delegate("click", function () {
            $(this).parent().addClass("selected");
        });
        $(".click-enable").delegate("click", function () {
            $(this).parent().removeClass("selected");
        });

        //JQUERY UI SlIDER RANGE
        $(".slider-range").each(function () {
            var $self = $(this),
                id = $(this).attr('id'),
                max = $(this).attr('data-max'),
                min = $(this).attr('data-min'),
                value = $(this).attr('data-value'),
                divine = $(this).attr("data-divine");
            // Append an element to make it slider range
            $(this).parent().append("<div id='" + id + "-slider'></div>");
            // Call jquery slider ui
            $("#" + id + "-slider").slider({
                range: "min",
                value: value * divine,
                min: min,
                max: max,
                slide: function (event, ui) {
                    $self.val((ui.value) / divine);
                }
            });
            // Put value of slider range into input
            $self.val(($("#" + id + "-slider").slider("value")) / divine);
        });
        //CHOOSE AND PREVIEW FONTS
        $(".choosefont").choosefont();

        /*========== Slides Accordion ==========*/

        $(".md-accordion-wrapper").accordion({
            collapsible: true,
            active: false,
            heightStyle: "content"
        });

        /*========== Drag and Drop ==========*/
        $("#md-block-enabled, #md-block-disabled, #md-block-backup").sortable({
            placeholder: "placeholder",
            revert: true
        });
        $("#md-block-enabled, #md-block-disabled, #md-block-backup").disableSelection();
        //Color Picker
        if ($.fn.spectrum) {
            $(".form-colorpicker").spectrum({
                showAlpha: true,
                showInput: true,
                allowEmpty: true,
                showInitial: true,
                preferredFormat: "hex3"
            });
        }

///////////////////////////////////////////// Add Class To Default Submit //////////////////////////////////////////////
        $("#md-framewp-footer .form-actions #edit-submit").addClass("btn btn-save");

    })
})(jQuery);
////////////////////////////////////////////////////// Add more content ////////////////////////////////////////////////
(function ($) {
    jQuery(document).ready(function () {
        var themeDir = Drupal.settings.themeDir;
        $(".md-media-wrapper").each(function () {
            checkMedia($(this));
        });
        /* Media popup click event */
        $(".md-media-wrapper").delegate(".media-select-button", 'click', function (event) {
            event.preventDefault();
            var mediaWrapper = $(this).parents(".md-media-wrapper");
            Drupal.media.popups.mediaBrowser(function (files) {
                var file = files[0],
                    inputVal = {
                        "fid": file.fid,
                        "url": file.url,
                        "name": file.filename
                    };
                $("div.preview", mediaWrapper).html('<img alt=" ' + file.filename + ' " class="img-preview" src="' + file.url + '" /><p class="img-name"> ' + file.filename + '</p>');
                $("input.media-hidden-value", mediaWrapper).val(JSON.stringify(inputVal));
                if (file.filename != null) {
                    $(".media-remove-button", mediaWrapper).show();
                }
            });
            return false;
        });
        /* Remove media selected */
        $(".md-media-wrapper").delegate(".media-remove-button", 'click', function (event) {
            event.preventDefault();
            var mediaWrapper = $(this).parents(".md-media-wrapper");
            mediaWrapper.find(".img-preview").attr("src", themeDir + '/img/theme-settings/no_image.png');
            mediaWrapper.find(".media-remove-button").hide();
            mediaWrapper.find(".img-name").empty();
            mediaWrapper.find("input.media-hidden-value").val('');
            return false;
        });


        $('.fake-select').fakeSelect();

        // Hide Input File Upload
        $('.md-form-file-upload').hide();

        // Select file button click event
        $('.md-file-wrapper').delegate('.md-select-file-button', 'click', function () {
            var self = $(this),
                parent = $(this).parents(".md-file-wrapper"),
                inputfile = parent.find('input[type="file"]');
            inputfile.trigger('click');
            return false;
        });

        $(".md-file-wrapper").each(function () {
            checkFile($(this));
        });
        // Input file change event
        $('.md-file-wrapper').delegate('input[type="file"]', 'change', function () {
            var nameFile = $(this).val().replace(/\\/g, '/').replace(/.*\//, ''),
                parent = $(this).parents(".md-file-wrapper");
            parent.find('.file-hidden-value').val(nameFile);
            parent.find('.img-name').html(nameFile);
            readURL(this, parent);
            parent.find(".md-remove-file-button").show();
            return false;
        });
        /* Remove media selected */
        $('.md-file-wrapper').delegate(".md-remove-file-button", 'click', function (event) {
            event.preventDefault();
            var mediaWrapper = $(this).parents(".md-file-wrapper");
            mediaWrapper.find(".img-preview").attr("src", themeDir + '/img/theme-settings/no_image.png');
            mediaWrapper.find(".md-remove-file-button").hide();
            mediaWrapper.find(".img-name").empty();
            mediaWrapper.find("input.file-hidden-value").val('');
            return false;
        });
    });

    // We need to check file image exist to display remove button
    function checkFile(instance) {
        var hiddenVal = instance.find("input.file-hidden-value");
        if ($(hiddenVal).val() != 0 && $(hiddenVal).val() != "" && $(hiddenVal).val() != null) {
            instance.find(".md-remove-file-button").show()
        }
    }

    // We need to check media image exist to display remove button
    function checkMedia(instance) {
        var existImg = false,
            hiddenVal = instance.find("input.media-hidden-value");
        if ($(hiddenVal).val() != 0) {
            instance.find(".media-remove-button").show()
        }
    }


    //Fake select
    $.fn.fakeSelect = function () {
        return this.each(function () {
            var $self = $(this),
                id = $self.attr("id"),
                numberItems = $("#" + id + ' option').length,
                $previewWrap = $self.parents(".fake-select-wrapper").find(".fake-select-preview"),
                selected = $("#" + id).val();


            //Prepare preview html
            $htmlPreview = '';
            for ($i = 0; $i <= numberItems; $i++) {
                $tmpval = $("#" + id + " option:eq(" + $i + ")").val();
                if ($tmpval) {
                    $htmlPreview += '<div id="fsItem-' + $tmpval + '" class="fsItem"></div>';
                }
            }
            // Append to fake div
            $previewWrap.html($htmlPreview);

            // Check current selected option and set fake selected
            $("#fsItem-" + selected).addClass("selected");

            // Event clicking fake select item
            $previewWrap.find(".fsItem").each(function () {
                $(this).click(function () {
                    $previewWrap.find(".selected").removeClass('selected');

                    $(this).addClass('selected');

                    $("#" + id + " option[selected]").removeAttr("selected");

                    tmpindex = $(this).attr('id').replace("fsItem-", "")
                    $("#" + id + " option[value=" + tmpindex + "]").attr("selected", "selected");

                });
            });
            // Hide the real select
            $self.hide();
        });
    }
    //Fake Upload file
    $.fn.fakeFileUpload = function () {
        return this.each(function () {
            var $self = $(this);
        })
    }

    function filestyle(file, filewrap, path, inputtext) {
        inputtext = typeof inputtext !== 'undefined' ? inputtext : 0;

        $(path).find('.form-text').after($(file));
        $(filewrap).remove();

        var self = $(file);
        var text = $('<div class="filetext"><span></span>Upload a file</div>');

        self.wrap('<div class="filewrapper btn-upload">').after(text).css({"opacity": "0"}).bind("change", function () {
            if (inputtext == 1) {
                $(path).find('.description').before('<div>File: ' + self.val().replace("C:\\fakepath\\", "") + ' selected</div>');
            } else {
                $(path).find('.form-text').val(self.val().replace("C:\\fakepath\\", ""));
            }
        });
    }

    // Apply image to preview
    function readURL(input, parent) {
        if (input.files && input.files[0]) {
            var reader = new FileReader();
            reader.onload = function (e) {
                parent
                    .find('.img-preview')
                    .attr('src', e.target.result);

            };
            reader.readAsDataURL(input.files[0]);
        }
    }
})(jQuery);
