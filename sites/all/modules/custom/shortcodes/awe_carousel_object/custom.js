var $ = jQuery.noConflict();
$(document).ready(function () {

    "use strict";


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    /* owl-carousels */
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    jQuery("#owl-team").owlCarousel({
        singleItem:	true,
        autoPlay:	true,
        navigation: true,
        navigationText: [
            "<i class='fa fa-angle-left fa-3x'></i>",
            "<i class='fa fa-angle-right fa-3x'></i>"
        ]
    });
});
