(function($) {
  'use strict';

  /**
   * Slick Slide
   */
  $(function(){
     $('.slide-directors').slick({
    slidesToShow: 3,
    slidesToScroll: 1,
    autoplaySpeed: 2000,
    arrows: false,
    dots: true,
    responsive: [
    {
      breakpoint: 992,
      settings: {
        slidesToShow: 2
      }
    },
    {
      breakpoint: 480,
      settings: {
        slidesToShow: 1
      }
    }
  ]
  });

  $('.slide-directors1').slick({
    slidesToShow: 4,
    slidesToScroll: 1,
    autoplaySpeed: 2000,
    arrows: false,
    dots: true,
    responsive: [
    {
      breakpoint: 992,
      settings: {
        slidesToShow: 3
      }
    },
    {
      breakpoint: 768,
      settings: {
        slidesToShow: 2
      }
    },
    {
      breakpoint: 480,
      settings: {
        slidesToShow: 1
      }
    }
  ]
  });

  $('.tab-all-project-slide').slick({
    prevArrow: '.arrows .all-project-prev',
    nextArrow: '.arrows .all-project-next',
    infinite: true,
    slidesToShow: 4,
    slidesToScroll: 1,
    dots: false,
    responsive: [
    {
      breakpoint: 992,
      settings: {
        slidesToShow: 3
      }
    },
    {
      breakpoint: 768,
      settings: {
        slidesToShow: 2
      }
    },
    {
      breakpoint: 480,
      settings: {
        slidesToShow: 1
      }
    }
  ]
  });

  $('.cliens-slide').slick({
    slidesToShow: 6,
    slidesToScroll: 1,
    autoplaySpeed: 2000,
    dots: false,
    prevArrow: '.arrows .cliens-prev',
    nextArrow: '.arrows .cliens-next',
    responsive: [
    {
      breakpoint: 1200,
      settings: {
        slidesToShow: 5
      }
    },
    {
      breakpoint: 992,
      settings: {
        slidesToShow: 4
      }
    },
    {
      breakpoint: 768,
      settings: {
        slidesToShow: 3
      }
    },
    {
      breakpoint: 480,
      settings: {
        slidesToShow: 1
      }
    },
  ]
  });

  $('.bg-testimonials-slide').slick({
    slidesToShow: 1,
    slidesToScroll: 1,
    autoplaySpeed: 2000,
    arrows: false,
    dots: true,
  });

  $('.slide-base.slide-design').slick({
    slidesToShow: 1,
    slidesToScroll: 1,
    autoplaySpeed: 2000,
    arrows: false,
    dots: true,
    fade: true,
  });

  $('.slide-base.slide-construction').slick({
    slidesToShow: 1,
    slidesToScroll: 1,
    autoplaySpeed: 2000,
    arrows: false,
    dots: true,
    fade: true,
  });


  $('.slide-for').slick({
    slidesToShow: 1,
    slidesToScroll: 1,
    arrows: false,
    fade: true,
    asNavFor: '.slide-nav'
  });
  $('.slide-nav').slick({
    slidesToShow: 5,
    slidesToScroll: 1,
    asNavFor: '.slide-for',
    arrows: false,
    focusOnSelect: true,
    responsive: [

    {
      breakpoint: 768,
      settings: {
        slidesToShow: 3
      }
    }
  ]
  });
  
  $('.slide-for-images').slick({
      slidesToShow: 1,
      slidesToScroll: 1,
      arrows: false,
      asNavFor: '.slide-nav-images'
    });

    $('.slide-nav-images').slick({
      slidesToShow: 3,
      slidesToScroll: 1,
      asNavFor: '.slide-for-images',
      arrows: false,
      focusOnSelect: true,
      responsive: [

      {
        breakpoint: 768,
        settings: {
          slidesToShow: 2
        }
      }
    ]
    });

  $('.special-offers-slide').slick({
    slidesToShow: 4,
    slidesToScroll: 1,
    autoplaySpeed: 2000,
    dots: false,
    prevArrow: '.arrows .special-offers-prev',
    nextArrow: '.arrows .special-offers-next',
    responsive: [

    {
      breakpoint: 992,
      settings: {
        slidesToShow: 3
      }
    },
    {
      breakpoint: 768,
      settings: {
        slidesToShow: 2
      }
    },
    {
      breakpoint: 480,
      settings: {
        slidesToShow: 1
      }
    },
  ]
  });

  $('#latest').slick({
    slidesToShow: 4,
    slidesToScroll: 1,
    autoplaySpeed: 2000,
    dots: false,
    prevArrow: '.arrows .latest-prev',
    nextArrow: '.arrows .latest-next',
    responsive: [

    {
      breakpoint: 992,
      settings: {
        slidesToShow: 3
      }
    },
    {
      breakpoint: 768,
      settings: {
        slidesToShow: 2
      }
    },
    {
      breakpoint: 480,
      settings: {
        slidesToShow: 1
      }
    },
  ]
  });

  $('#featured').slick({
    slidesToShow: 4,
    slidesToScroll: 1,
    autoplaySpeed: 2000,
    dots: false,
    prevArrow: '.arrows .featured-prev',
    nextArrow: '.arrows .featured-next',
    responsive: [

    {
      breakpoint: 768,
      settings: {
        slidesToShow: 3
      }
    },
    {
      breakpoint: 480,
      settings: {
        slidesToShow: 1
      }
    },
  ]
  });
  });

  /**
   * countNum
   */
 /* $(function(){
    $({countNum: $('.box-count-number1 > span').text()}).animate({countNum: 1368}, {
    duration: 5000,
    easing:'linear',
    step: function() {
      $('.box-count-number1 > span').text(Math.floor(this.countNum));
    }
  });

  $({countNum: $('.box-count-number2 > span').text()}).animate({countNum: 999}, {
    duration: 5000,
    easing:'linear',
    step: function() {
      $('.box-count-number2 > span').text(Math.floor(this.countNum));
    }
  });

  $({countNum: $('.box-count-number3 > span').text()}).animate({countNum: 366}, {
    duration: 5000,
    easing:'linear',
    step: function() {
      $('.box-count-number3 > span').text(Math.floor(this.countNum));
    }
  });
  });*/

  /**
   * HoverImg
   */
  $(function(){
    $(' #da-thumbs > .grid-item > .box-image ').each( function() { $(this).hoverdir(); } );
  });

  /**
   * Backtotop
   */
  $(function(){
    jQuery(document).ready(function() {
    var offset = 220;
    var duration = 700;
    $(window).scroll(function() {
        if ($(this).scrollTop() > offset) {
            $('.back-totop').fadeIn(duration);
        } else {
            $('.back-totop').fadeOut(duration);
        }
    });
    $('.back-totop').click(function(e) {
        e.preventDefault();
        $('html, body').animate({scrollTop: 0}, duration);
        return false;
    })
  });

  /**
   * js isotope
   */
  $(document).ready(function() {
	
	$('.box-count-number').each(function () {
		var $this = $(this);
		jQuery({ Counter: 0 }).animate({ Counter: $this.attr('data-stop') }, {
		  duration: 5000,
		  easing: 'linear',
		  step: function (now) {
			$this.children('span').text(Math.ceil(now));
		  }
		});
	});
	
	// mini-cart
	var $mini_cart = $( '.mini-cart' );
	$mini_cart.on( 'click', function ( e ) {
		$( this ).addClass( 'open' );
	} );

	$( document ).on( 'click', function ( e ) {
		if ( $( e.target ).closest( $mini_cart ).length == 0 ) {
			$mini_cart.removeClass( 'open' );
		}
	} );
    
	$('.portfolioContainer').each(function() {
      var el = $(this);
      var portfolioContainer = el,
          filters = $('.portfolioFilter');
      filters.on('click', 'a', function() {
          var selector = $(this).attr('data-filter');
          $('.current', filters).removeClass('current');
          $(this).addClass('current');
          portfolioContainer.isotope({
              filter: selector
          });
          return false;
      });

      $(window).on('resize', function() {

          portfolioContainer.imagesLoaded(function() {
              portfolioContainer.isotope({
                  layoutMode: 'masonry',
                  itemSelector: '.grid-item',
                  transitionDuration: '0.5s',
              });
          });

      }).resize();

      filters.find('.current').trigger('click');
    });
	
	// search in menu
	var $search_btn = $( '.search-box > i' ),
		$search_form = $( 'form.search-form' );

	$search_btn.on( 'click', function () {
		$search_form.toggleClass( 'open' );
	} );

	$( document ).on( 'click', function ( e ) {
		if ( $( e.target ).closest( $search_btn ).length == 0
		     && $( e.target ).closest( 'input.search-field' ).length == 0
		     && $search_form.hasClass( 'open' ) ) {
			$search_form.removeClass( 'open' );
		}
	} );
	
	//menu setup
	var $menu = $( '.navigation' ),
		$menulink = $( '.menu-link' );

	$menulink.click( function () {
		$menulink.toggleClass( 'active' );
		$menu.toggleClass( 'active' );
		return false;
	} )

	$( '.navigation' ).find( '.sub-menu-toggle' ).on( 'click', function ( e ) {
		var subMenu = $( this ).parent().find( 'ul' ).first();
		var thisLi = $( this ).parent();
		if ( subMenu.css( 'display' ) != 'block' ) {
			subMenu.css( 'display', 'block' );
			thisLi.addClass( 'is-open' );
		} else {
			subMenu.css( 'display', 'none' );
			thisLi.removeClass( 'is-open' );
		}
		e.stopPropagation();
	} );
	
	$(window).bind('scroll', function() {
	 	if($(".has-fixed-header").length > 0) {
			var navHeight = $( window ).height() - 70;
			if($( window ).width() > 992) {
				if ($(window).scrollTop() > navHeight) {
				   $('.header-preset-1 .header').addClass('fixed');
				   $('.header-preset-02 .nav').addClass('fixed');
				   $('.header-preset-03 .nav').addClass('fixed');
				   $('.header-preset-04 .header').addClass('fixed');
				   $('.header-preset-05 .header').addClass('fixed');
				   $('.header-preset-06 .header').addClass('fixed');
				}
				else {
				   $('.header-preset-1 .header').removeClass('fixed');
				   $('.header-preset-02 .nav').removeClass('fixed');
				   $('.header-preset-03 .nav').removeClass('fixed');
				   $('.header-preset-04 .header').removeClass('fixed');
				   $('.header-preset-05 .header').removeClass('fixed');
				   $('.header-preset-06 .header').removeClass('fixed');
				}
			} else {
				if ($(window).scrollTop() > 50) {
				   $('.header-wrapper .header').addClass('fixed');
				   $('.header-wrapper .nav').addClass('fixed');
				}
				else {
				   $('.header-wrapper .header').removeClass('fixed');
				   $('.header-wrapper .nav').removeClass('fixed');
				}
			}
		}
	});
  })
  $(window).load(function(){
  });

});
})(jQuery);