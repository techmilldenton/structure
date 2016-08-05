(function($) {
    $( document ).ready(function() {

        // Call Dialog, Add Id field to dialog
        $('.node-form').delegate('.icon-preview', 'click', function(){
            if($('.icon-popup.ui-dialog-content').length < 1){
                $('.icon-popup').dialog({
                    width: '80%',
                    modal: true,
                    autoOpen: false
                });
            }
            var classValue = $(this).find('i').attr('class') || '',
                $dialog = $('.icon-popup.ui-dialog-content'),
                fieldID = $(this).parents('.field-icon-container').attr('id');
            $dialog.find('i').removeClass('active');
            if (classValue) {
                $dialog.find('.'+classValue).addClass('active');
            }
            $dialog.data('id', fieldID);
            $dialog.dialog("open");
        });

        $('.icon-popup').delegate('i' ,'click' ,function(){
            var classValue = $(this).data('value'),
                icon = $(this).data('icon'),
                $dialog = $('.icon-popup.ui-dialog-content'),
                fieldID = $(this).parents('.icon-popup.ui-dialog-content').data('id');
            $('#'+fieldID).find('select').val(classValue);
            $('#'+fieldID).find('.icon-preview i').attr('class', icon);
            $dialog.dialog("close");
        });
    });

    Drupal.behaviors.myBehavior = {
        attach: function (context, settings) {
            if($('.icon-popup.ui-dialog-content').length < 1){
                $('.icon-popup').dialog({
                    width: '80%',
                    modal: true,
                    autoOpen: false
                });
            }
            $('.icon-popup', context).hide();
            $('.field-icon-container', context).each(function(index, value){
                var icon_class = $(this).find('select').val(),
                    icon_class = icon_class.split("|").pop();
                $(this).find('.form-type-select').hide();
                $(this).find('.icon-preview').find('i').attr('class',icon_class);
            });
        }
    };
})(jQuery);