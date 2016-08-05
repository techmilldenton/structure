(function($) {
    $( document ).ready(function() {
        $('.node-form').delegate('.social-icon-preview', 'click', function() {
            if ($('.icon-markup.ui-dialog-content').length < 1) {
                $('.social-container .icon-markup').dialog({
                    width: '80%',
                    modal: true,
                    autoOpen: false
                });
            }
            var classValue = $(this).find('i').attr('class') || '',
                $dialog = $('.icon-markup.ui-dialog-content'),
                fieldID = $(this).parents('.social-container').attr('id');

            $dialog.find('i').removeClass('active');
            if(classValue){
                $dialog.find('.'+classValue).addClass('active');
            }
            $dialog.data('id', fieldID);
            $dialog.dialog("open");
        });


        $('.icon-markup').delegate('i' ,'click' ,function(){
            var classValue = $(this).data('value'),
                icon = $(this).data('icon'),
                $dialog = $('.icon-markup.ui-dialog-content'),
                fieldID = $(this).parents('.icon-markup.ui-dialog-content').data('id');
            $('#'+fieldID).find('input.icon-value').val(classValue);
            $('#'+fieldID).find('.social-icon-preview i').attr('class', icon);
            $dialog.dialog("close");
        });

    });


    Drupal.behaviors.md_field_icon = {
        attach: function(context, settings) {
            if ($('.icon-markup.ui-dialog-content').length < 1) {
                $('.social-container .icon-markup').dialog({
                    width: '80%',
                    modal: true,
                    autoOpen: false
                });
            }
            $('.social-container .icon-value', context).hide();
            $('.social-container .icon-markup', context).hide();

            $('.social-container', context).each(function(index, value){
                var icon_class = $(this).find('input.icon-value').val(),
                    icon_class = icon_class.split("|").pop();
                $(this).find('.form-type-select').hide();
                $(this).find('.social-icon-preview').find('i').attr('class',icon_class);
            });
        }
    };
}(jQuery));
