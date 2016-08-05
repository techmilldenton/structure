(function ($) {
    "use strict";
    $(document).ready( function () {
        $('.awe-carousel').each( function () {
            $(this).carouselItem();
        });

        $(".ts-item-member:not('.active-hover')").mouseenter(function(){
            $(this).addClass("hover");
        })
        .mouseleave(function(){
            $(this).removeClass("hover");
        });

    });

    $.fn.carouselItem = function () {
        var self = this,
            data = $(self).data(),
            settings = {};
        if (!data.responsive) {
            settings.items = data.items;
            if (settings.items == 1) {
                settings.transitionStyle = data.effect;
            }
        }
        else {
            settings.itemsDesktop = [1199, data.items];
            settings.itemsDesktopSmall = [979, data.itemsDesktopSmall];
            settings.itemsTablet = [768, data.itemsTablet];
            settings.itemsMobile = [479, data.itemsMobile];
        }
        if (data.effect) {
            settings.transitionStyle = data.effect
        }
		if (data.pagination) {
            settings.pagination = data.pagination
        }
        if (data.navigation) {
            settings.navigation = data.navigation;
            settings.navigationText = ["<i class='fa fa-angle-left fa-4x'></i>","<i class='fa fa-angle-right fa-4x'></i>"];
        }
        if (data.auto) {
            settings.autoPlay = data.timeAuto * 1000;
            settings.stopOnHover = data.stopOnHover;
        }
        if (data.mousedrag == false) {
            settings.mouseDrag = data.mousedrag
        }
        if (data.touchdrag == false) {
            settings.touchDrag = data.touchdrag;
        }
        $(this).owlCarousel(settings);
    }

})(jQuery)
