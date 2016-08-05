(function ($) {
    var FooterIcon;
    FooterIcon = function (select, context) {
        var $select = $(select, context),
            self = this;
        this.formDialog = '';
        this.iconDialog = '';
        this.listID = '';
        this.iconValue = '';
        this.init = function (){
            self.createListIcon();
            self.iconSort();
            self.createDialog();
            self.OpenDialog();
            self.closeDialog();
            self.updateID();
            self.cloneIcon();
            this.deleteIcon();
        };

        this.createListIcon = function () {
            var listText = $.trim($('.icon-footer', context).val()),
                listArray = listText.split("||"),
                listArray = self.arrayChunk(listArray, 4),
                html = '';
            listArray.pop();
            console.log(listText);
            console.log(listArray);
            $.each(listArray, function(index, value) {
                var iClass = self.clearString(value[0], 'last'),
                    iValue = self.clearString(value[1], 'all'),
                    iTitle = self.clearString(value[2], 'all'),
                    iText = self.clearString(value[3], 'all');
                html += '<li class="icon-sort draggable-item" id="li-'+index+'">'
                +'<div class="toolbar">'
                +'<a class="delete-icon" href="#">Delete</a>'
                +'<a class="clone-icon" href="#">Clone</a>'
                +'</div>'
                +'<div class="wrap-icon">'
                +'<div class="ci-icon" data-class="'+iClass+'" data-value="'+iValue+'"><i class="'+iClass+'"></i></div>'
                +'<div class="ci-title" data-title="'+iTitle+'">'+iTitle+'</div>'
                +'<div class="ci-text" data-text="'+iText+'">'+iText+'</div>'
                +'</div>'
                +'</li>';
            })
            $('#sortable', context).html(html);
        }

        this.createDialog = function () {
            $('.form-popup, .icon-popup', context).dialog({
                width: '80%',
                modal: true,
                autoOpen: false
            });
            self.formDialog = $('.form-popup.ui-dialog-content');
            self.iconDialog = $('.icon-popup.ui-dialog-content');
        }
        this.OpenDialog = function () {
            $(context).delegate('.wrap-icon, .create-button', 'click', function() {
                var listId = $(this).parents('.icon-sort').attr('id'),
                    iconTitle = $(this).find('.ci-title').data('title') || 'Title',
                    iconText = $(this).find('.ci-text').data('text') || 'Text',
                    iconClass = $(this).find('.ci-icon').data('class') || 'icon fontello icon-glyph',
                    iconValue = $(this).find('.ci-icon').data('value') || 'fontello|icon-glyph';
                self.listID = listId;
                self.formDialog.attr('data-id', self.listID);
                self.formDialog.find('.choose-icon').attr('value', iconValue);
                self.formDialog.find('.choose-icon i').attr('class', iconClass);
                self.formDialog.find('.icon-title').val(iconTitle);
                self.formDialog.find('.icon-text').val(iconText);
                self.formDialog.dialog("open");
            });
            $(context).delegate('.choose-icon', 'click', function() {
                var classIcon = $(this).find('i').attr('class'),
                    classIcon = classIcon.split(" ").pop();
                self.iconDialog.find('.icon').removeClass('active');
                self.iconDialog.find('.'+classIcon).addClass('active');
                self.iconDialog.dialog("open");
            });
        }

        this.iconSort = function () {
            $('#sortable').sortable({
                stop: function( event, ui ) {
                    self.updateID();
                    self.updateInput();
                }
            });
        }

        this.updateID = function () {
            $('#sortable').find('li').each(function() {
                var index = $(this).index();
                $(this).attr('id', 'li-' + index);
            });
        }

        this.closeDialog = function () {
            $('.icon-popup').delegate('i', 'click', function(){
                var iconClass = $(this).attr('class'),
                    iconValue = $(this).data('value');
                self.formDialog.find('.choose-icon a').html('<i class="' + iconClass +'"></i>');
                self.formDialog.find('.choose-icon').attr('data-value', iconValue);
                self.iconDialog.dialog("close");
            });

            self.formDialog.dialog({
                close: function( event, ui ) {
                    var iconValue = self.formDialog.find('.choose-icon').attr('data-value'),
                        iconClass = self.formDialog.find('i').attr('class'),
                        iconTitle = self.formDialog.find('.icon-title').val() || '#',
                        iconText = self.formDialog.find('.icon-text').val() || '#',
                        html = '<div class="ci-icon" data-class="'+iconClass+'" data-value="'+iconValue+'"><i class="'+iconClass+'"></i></div>'
                               +'<div class="ci-title" data-title="'+iconTitle+'">'+iconTitle+'</div>'
                               +'<div class="ci-text" data-text="'+iconText+'">'+iconText+'</div>';
                    if (self.listID == undefined) {
                        $('#sortable').find('#li-0').find('.wrap-icon').html(html);
                    }
                    $('#sortable').find('#' + self.listID).find('.wrap-icon').html(html);
                    self.updateInput();
                }
            });
        }

        this.cloneIcon = function () {
            $select.delegate('.clone-icon', 'click', function(event) {
                event.preventDefault();
                var html = $(this).parents('.icon-sort').html(),
                    html = '<li class="icon-sort draggable-item">'+ html +'</li>';
                $('#sortable', context).append(html);
                self.updateID();
                self.updateInput();
            });

        }

        this.deleteIcon = function () {
            $select.delegate('.delete-icon', 'click', function(event) {
                event.preventDefault();
                if ($('#sortable', context).find('li').length > 1){
                    $(this).parents('.icon-sort').remove();
                    self.updateID();
                    self.updateInput();
                }
            });
        }


        this.updateInput = function () {
            var inputValue = [];
            $('#sortable').find('.wrap-icon').each(function (){
                var iconTitle = $(this).find('.ci-title').data('title'),
                    iconText = $(this).find('.ci-text').data('text'),
                    iconClass = $(this).find('.ci-icon').data('class'),
                    iconValue = $(this).find('.ci-icon').data('value');

                    icon = [iconClass, '||', iconValue, '||', iconTitle, '||', iconText, '||'];
                inputValue.push(icon);
            });
            $('.icon-footer', context).val(inputValue.toString());
        }

        this.clearString = function(string, type){
            if (type == 'first') {
                string = string.substr(1);
            }
            if (type == 'last' ) {
                string =  string.substring(0, string.length-1);
            }
            if (type == 'all') {
                string = string.substr(1);
                string = string.substring(0, string.length-1);
            }
            return string;
        }
        this.arrayChunk = function (arr, len) {
            var chunks = [],
                i = 0,
                n = arr.length;
            while (i < n){
                chunks.push(arr.slice(i, i += len));
            }
            return chunks;
        }

    };

    Drupal.behaviors.myBehavior = {
        attach: function (context, settings) {
            var runfooter = new FooterIcon('#edit-info-contact', context);
            runfooter.init();
        }
    };
})(jQuery);