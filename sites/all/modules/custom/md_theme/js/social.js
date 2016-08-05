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
                listArray = listText.split(","),
                listArray = self.arrayChunk(listArray, 3),
                html = '';
            $.each(listArray, function(index, value) {
                html += '<li class="icon-sort" id="li-'+index+'">'
                        +'<div class="toolbar">'
                        +'<a class="delete-icon" href="#">Delete</a>'
                        +'<a class="clone-icon" href="#">Clone</a>'
                        +'</div>'
                        +'<div class="wrap-icon">'
                        +'<a data-class="'+value[2]+'" data-link="'+value[0]+'" data-value="'+value[1]+'" href="#"><i class="'+value[2]+'"></i></a>'
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
            $(context).delegate('.wrap-icon a', 'click', function(event) {
                event.preventDefault();
            });
            $(context).delegate('.choose-icon a', 'click', function(event) {
                event.preventDefault();
            });
            $(context).delegate('.wrap-icon', 'click', function() {
                var listId = $(this).parents('.icon-sort').attr('id'),
                    iconLink = $(this).find('a').data('link'),
                    iconClass = $(this).find('a').data('class'),
                    iconValue = $(this).find('a').data('value');

                self.listID = listId;
                self.formDialog.attr('data-id', self.listID);
                self.formDialog.find('.choose-icon').data('value', iconValue);
                self.formDialog.find('.choose-icon i').attr('class', iconClass);
                self.formDialog.find('.icon-link').val(iconLink);
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
                        iconLink = self.formDialog.find('.icon-link').val() || '#',
                        html = '<a data-class="'+iconClass+'" data-link="'+iconLink+'" data-value="'+ iconValue +'" href="#"><i class="'+iconClass+'"></i></a>';
                    $('#sortable').find('#' + self.listID).find('.wrap-icon').html(html);
                    self.updateInput();
                }
            });
        }

        this.cloneIcon = function () {
            $select.delegate('.clone-icon', 'click', function(event) {
                event.preventDefault();
                var html = $(this).parents('.icon-sort').html(),
                    html = '<li class="icon-sort">'+ html +'</li>';
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
            $('#sortable').find('.wrap-icon').find('a').each(function (){
                var iconLink = $(this).data('link'),
                    iconValue = $(this).data('value'),
                    iconClass = $(this).data('class'),
                    icon = [iconLink, iconValue, iconClass];
                inputValue.push(icon);
            });
            $('.icon-footer', context).val(inputValue.toString());
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
            var runfooter = new FooterIcon('#edit-footer-settings', context);
            runfooter.init();
        }
    };
})(jQuery);