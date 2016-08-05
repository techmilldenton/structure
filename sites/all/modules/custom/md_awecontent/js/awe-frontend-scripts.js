(function(a){a(document).ready(function(){a(".awe-flickr").mdFlickr();a.each(a(".awe-gmap"),function(){a(this).mdGMap()});a(".awe-accordion").mdAccordion();a(".awe-video").mdVideo();a(".awe-slideshow").mdSlideShow();a(".awe-gallery").mdGallery();a(".awe-image").mdImage();a("[data-animation]:not(.awemenu-submenu)").mdProcessAnimation();a(".md-parallax").mdParallax();a(".awe-media-control").mdEventPlayer();a(".awe-tabs").mdTabs();a(".awe-section").mdEqualHeight();a(window).resize(function(){setTimeout(function(){a(".frame-embed").mdResizeBgVideo()},100)}).trigger("resize");a(".awesection-fullscreen").awesectionFullscreen()});a.fn.mdGMap=function(q){var o=a(this),h={style1:[{featureType:"landscape",stylers:[{saturation:-100},{lightness:65},{visibility:"on"}]},{featureType:"poi",stylers:[{saturation:-100},{lightness:51},{visibility:"simplified"}]},{featureType:"road.highway",stylers:[{saturation:-100},{visibility:"simplified"}]},{featureType:"road.arterial",stylers:[{saturation:-100},{lightness:30},{visibility:"on"}]},{featureType:"road.local",stylers:[{saturation:-100},{lightness:40},{visibility:"on"}]},{featureType:"transit",stylers:[{saturation:-100},{visibility:"simplified"}]},{featureType:"administrative.province",stylers:[{visibility:"off"}]},{featureType:"water",elementType:"labels",stylers:[{visibility:"on"},{lightness:-25},{saturation:-100}]},{featureType:"water",elementType:"geometry",stylers:[{hue:"#ffff00"},{lightness:-25},{saturation:-97}]}],style2:[{featureType:"water",stylers:[{visibility:"on"},{color:"#acbcc9"}]},{featureType:"landscape",stylers:[{color:"#f2e5d4"}]},{featureType:"road.highway",elementType:"geometry",stylers:[{color:"#c5c6c6"}]},{featureType:"road.arterial",elementType:"geometry",stylers:[{color:"#e4d7c6"}]},{featureType:"road.local",elementType:"geometry",stylers:[{color:"#fbfaf7"}]},{featureType:"poi.park",elementType:"geometry",stylers:[{color:"#c5dac6"}]},{featureType:"administrative",stylers:[{visibility:"on"},{lightness:33}]},{featureType:"road"},{featureType:"poi.park",elementType:"labels",stylers:[{visibility:"on"},{lightness:20}]},{},{featureType:"road",stylers:[{lightness:20}]}],style3:[{featureType:"water",stylers:[{color:"#46bcec"},{visibility:"on"}]},{featureType:"landscape",stylers:[{color:"#f2f2f2"}]},{featureType:"road",stylers:[{saturation:-100},{lightness:45}]},{featureType:"road.highway",stylers:[{visibility:"simplified"}]},{featureType:"road.arterial",elementType:"labels.icon",stylers:[{visibility:"off"}]},{featureType:"administrative",elementType:"labels.text.fill",stylers:[{color:"#444444"}]},{featureType:"transit",stylers:[{visibility:"off"}]},{featureType:"poi",stylers:[{visibility:"off"}]}],style4:[{featureType:"water",elementType:"geometry",stylers:[{color:"#000000"},{lightness:17}]},{featureType:"landscape",elementType:"geometry",stylers:[{color:"#000000"},{lightness:20}]},{featureType:"road.highway",elementType:"geometry.fill",stylers:[{color:"#000000"},{lightness:17}]},{featureType:"road.highway",elementType:"geometry.stroke",stylers:[{color:"#000000"},{lightness:29},{weight:0.2}]},{featureType:"road.arterial",elementType:"geometry",stylers:[{color:"#000000"},{lightness:18}]},{featureType:"road.local",elementType:"geometry",stylers:[{color:"#000000"},{lightness:16}]},{featureType:"poi",elementType:"geometry",stylers:[{color:"#000000"},{lightness:21}]},{elementType:"labels.text.stroke",stylers:[{visibility:"on"},{color:"#000000"},{lightness:16}]},{elementType:"labels.text.fill",stylers:[{saturation:36},{color:"#000000"},{lightness:40}]},{elementType:"labels.icon",stylers:[{visibility:"off"}]},{featureType:"transit",elementType:"geometry",stylers:[{color:"#000000"},{lightness:19}]},{featureType:"administrative",elementType:"geometry.fill",stylers:[{color:"#000000"},{lightness:20}]},{featureType:"administrative",elementType:"geometry.stroke",stylers:[{color:"#000000"},{lightness:17},{weight:1.2}]}]},i=o.data(),n=i.zoom,c=i.style,k=i.latlong,l=parseInt(i.scrollzoom),e=i.info,g=i.marker,m=i.title,j=i.descriptions,b,f,d,p;if(k!=""&&k.indexOf(",")!=-1){k=k.split(",");k=new google.maps.LatLng(k[0],k[1]);f={zoom:n,styles:h[c],center:k,scrollwheel:l?false:true};b=new google.maps.Map(this[0],f);setTimeout(function(){google.maps.event.trigger(b,"resize")},50);if(e){d=new google.maps.Marker({map:b,title:"Click to show info",icon:g,position:k});p=new google.maps.InfoWindow({content:(m||j)?'<h2 style="color: #333;">'+m+'</h2><p style="color: #555;">'+j+"</p>":""});google.maps.event.addListener(d,"click",function(){p.open(b,d);if(d.getAnimation()!=null){d.setAnimation(null)}else{d.setAnimation(google.maps.Animation.BOUNCE)}})}}};a.fn.mdAccordion=function(){a.each(this,function(){var b=a(this);b.accordion({header:">.group >h3",heightStyle:"content",collapsible:true,activate:function(c,d){},create:function(c,d){a(d.header).find(".sign-toggle-accr > i").removeClass("ic ac-icon-add").addClass("ic ac-icon-minus")},beforeActivate:function(g,h){var i=parseInt(b.data("toggle")),d=h.newHeader.length?h.newHeader:h.oldHeader;if(i){var e,c,f;if(h.newHeader[0]){e=h.newHeader;c=e.next(".ui-accordion-content")}else{e=h.oldHeader;c=e.next(".ui-accordion-content")}f=e.attr("aria-selected")=="true";e.toggleClass("ui-corner-all",f).toggleClass("accordion-header-active ui-state-active ui-corner-top",!f).attr("aria-selected",((!f).toString()));e.children(".ui-icon").toggleClass("ui-icon-triangle-1-e",f).toggleClass("ui-icon-triangle-1-s",!f);c.toggleClass("accordion-content-active",!f);if(f){c.slideUp();a(".sign-toggle-accr > i",e).removeClass("ac-icon-minus").addClass("ac-icon-add")}else{a(".sign-toggle-accr > i",e).removeClass("ac-icon-add").addClass("ac-icon-minus");c.slideDown()}return false}else{a(".sign-toggle-accr > i",d.parents(".awe-item:first")).removeClass("ac-icon-minus").addClass("ac-icon-add");a(".sign-toggle-accr > i",h.newHeader).removeClass("ac-icon-add").addClass("ac-icon-minus")}}})})};a.fn.mdVideo=function(){a.each(this,function(){var i=a(this),k=i.data(),b=k.thumb?k.thumb:false,c=k.background?k.background:false,e=k.heightvideo?k.heightvideo:false,h=k.typeplay?k.typeplay:false,d=k.href?k.href:"",g=a('<div class="embed-responsive embed-responsive-16by9"><iframe class="embed-responsive-item"></iframe></div>'),j=a('<div class="thumb-video"><div class="image-content"><img src="" alt=""/></div><div class="play-control"><i class="ic ac-icon-play"></i></div></div>'),f=a('<a class="video-openlightbox"></a>');switch(h){case"autoInline":a("iframe",g).attr("src",d);i.append(g);break;case"inline":a("img",j).attr("src",b);i.append(j);a(".play-control",i).click(function(){a("iframe",g).attr("src",d);i.append(g);setTimeout(function(){j.hide();g.show()},500)});break;case"lightbox":a("img",j).attr("src",b);f.attr("href",d).magnificPopup({disableOn:700,type:"iframe",mainClass:"mfp-fade",removalDelay:160,preloader:false,fixedContentPos:false});i.append(j,f);a(".play-control",i).click(function(){f.trigger("click")});break}})};a.fn.mdSlideShow=function(){a.each(this,function(){var b=a(this),f={singleItem:true,autoPlay:false,stopOnHover:false,pagination:true,paginationNumbers:false,navigation:false,addClassActive:true,transitionStyle:"fade"};var h={},c={},e;e=b.data();c.autoPlay=e.autoplay?true:false;if(e.effect!=undefined){c.transitionStyle=e.effect}(function d(){var i=a(".md-item-image:first",b).data("thumb"),j=a('<img src="" alt="" />').attr("src",i).css({opacity:0,visibility:"hidden"});if(i){j.load(function(){b.data("thumb-width",this.naturalWidth);a(".awe-test-image").remove()})}else{b.data("thumb-width",150)}})();var g=setInterval(function(){var l;if(b.data("thumb-width")!=undefined){clearInterval(g);switch(e.navigation){case"none":c.pagination=false;break;case"button":c.pagination=true;c.paginationNumbers=false;break;case"number":c.pagination=true;c.paginationNumbers=true;break;case"thumbnail":function i(q){var s=l.data("owlCarousel").owl.visibleItems,o=q,r=false;for(var p in s){if(o===s[p]){r=true}}if(r===false){if(o>s[s.length-1]){l.trigger("owl.goTo",o-s.length+2)}else{if(o-1===-1){o=0}l.trigger("owl.goTo",o)}}else{if(o===s[s.length-1]){l.trigger("owl.goTo",s[1])}else{if(o===s[0]){l.trigger("owl.goTo",o-1)}}}}function m(o){var p=this.currentItem;l.find(".owl-item").removeClass("synced").eq(p).addClass("synced");if(l.data("owlCarousel")!==undefined){i(p)}}function k(p){var r=Math.floor(b.width()/b.data("thumb-width")),s,o,q;if(r>a(".md-item-image",b).length){r=a(".md-item-image",b).length}if(r<2){r=2;s="";o=""}else{s=r*b.data("thumb-width");o=(b.width()-s)/2}if(q=a(".owl-carousel",p).data("owlCarousel")){q.destroy()}a(".list-thumb-content",p).width(s).css("margin-left",o);l=a(".owl-carousel",p).owlCarousel({pagination:false,items:r,itemsDesktop:false,itemsDesktopSmall:false,itemsTablet:false,itemsMobile:false,responsiveRefreshRate:100})}c.pagination=false;c.paginationNumbers=false;c.afterAction=m;var n=a('<div class="owl-list-thumb"><div class="list-thumb-content owl-carousel"></div></div>');a.each(a(".md-item-image ",b),function(){var o=a('<div class="image-thumb"><img src="" alt=""/></div>'),p=a("img",this).data("thumb");a("img",o).attr("src",p);a(".list-thumb-content",n).append(o)});k(n);l.delegate(".owl-item","click",function(o){o.preventDefault();a(".image-slide-show",b).trigger("owl.goTo",a(this).data("owlItem"))});var j;a(window).resize(function(){if(j){clearTimeout(j)}j=setTimeout(function(){k(n)},100)});e.positionnav=="top"?b.prepend(n):b.append(n);break}if(e.showcontrols){c.navigation=true}if(c.autoPlay){c.beforeMove=function(){if(l){l.find(".active").css({duration:""})}};c.afterMove=function(){a(".image-slide-show",b).find(".active").css({"animation-duration":e.transspeed+"ms"})};c.autoPlay=e.speed}if(e.stoponhover){c.stopOnHover=true}c=a.extend(f,c);a(".image-slide-show",b).owlCarousel(c)}},100)})};a.fn.mdGallery=function(){a.each(this,function(){var b=a(this);if(!a(".md-item-image",b).hasClass("position-over")){var d=a("li.md-item-image",b),e=b.data("items-thumb"),h=0,g=d.length;a(".awe-image-caption",d).css("height","");do{var c=d.slice(h,e),f=0;h=h+e;c.each(function(){var i=a(".awe-image-caption",this).height();if(i>f){f=i}});a(".awe-image-caption",c).height(f)}while(h<g-1)}b.magnificPopup({delegate:".open-lightbox",type:"image",removalDelay:300,mainClass:"mfp-fade",callbacks:{open:function(r,l){var q=a(".mfp-container"),i=a(".mfp-content",q),n=a('<div class="mdf-list-thumb"><div class="thumb-content"><div class="thumb-control"></div></div></div>'),k=a(".thumb-content",n),j=a(".thumb-control",n),o=a(".mgf-md-popup img",b),m=parseInt(b.data("items-thumb")),p=this.ev.data("enable-thumb");j.append('<i class="ic ac-icon-arrow-left gallery-prev"></i><i class="ic ac-icon-arrow-right gallery-next"></i><input type="hidden" class="gallery-trigger"/>');if(!q.next(".mdf-list-thumb").length&&p==true){a.each(o,function(u,t){var s=a(t).clone();a(".thumb-content",n).append(s)});i.after(n);k.click(function(s){s.stopPropagation()});k.change(function(w,x){if(x!=undefined&&typeof x.index=="number"){var t=x.index;a("img",k).removeClass("img-show");a("img",k).eq(t).addClass("active");for(var v=0;v<m;v++){var s=t+v;a("img",k).eq(s).addClass("img-show")}var u=a("img.img-show",k).length;if(u<m){for(v=0;v<m-u;v++){s=t-1-v;a("img",k).eq(s).addClass("img-show")}}}});a("img",k).click(function(){var s=a(this).index()-1;a(this).addClass("active");a(this).siblings("img").removeClass("active");a.magnificPopup.instance.goTo(s)});a(".gallery-trigger",q).change(function(u,v){u.stopPropagation();if(v!=undefined&&typeof v.index=="number"){var t=v.index,s=a("img",k).eq(t);s.addClass("active");s.siblings("img").removeClass("active");if(!s.hasClass("img-show")){k.trigger("change",{index:t})}}});a(".gallery-next",j).click(function(){if(a(".img-show:last",k).index()==a("img",k).length){a(".gallery-trigger",q).trigger("change",{index:0,isNav:true});a("img.active",k).removeClass("active")}else{var v=a("img.img-show:last",k).index(),y=a("img",k).length;a("img.img-show",k).removeClass("img-show");for(var w=0;w<m;w++){var s=v+w;a("img",k).eq(s).addClass("img-show")}if(a(".img-show",k).length<m){var x=a(".img-show",k).length,t=a(".img-show:first",k).index()-1;for(w=0;w<(m-x);w++){var u=t-w-1;a("img",k).eq(u).addClass("img-show")}}}});a(".gallery-prev",j).click(function(){if(a(".img-show:first",k).index()==1){var v=a("img",k).length-m;a(".gallery-trigger",q).trigger("change",{index:v,isNav:true});a("img.active",k).removeClass("active")}else{var y=a("img.img-show:first",k).index()-2;a("img.img-show",k).removeClass("img-show");for(var w=0;w<m;w++){var t=y-w;if(t>=0||t<=a("img",k)-1){a("img",k).eq(t).addClass("img-show")}}if(a(".img-show",k).length<m){var x=a(".img-show",k).length,s=a(".img-show:last",k).index()-1;for(w=0;w<(m-x);w++){var u=s+w+1;a("img",k).eq(u).addClass("img-show")}}}})}},change:function(i){setTimeout(function(){var l=a(".mfp-container"),j=a(".thumb-content",l),k=a(".mdf-list-thumb",l);if(!b.isOpenThumb){b.isOpenThumb=true;j.trigger("change",{index:i.index})}a(".gallery-trigger",l).trigger("change",{index:i.index})},50)},markupParse:function(k,i,l){var m=a(".awe-image-caption",l.el),j=this.ev.attr("data-enable-caption-on-lightbox");if(j&&j=="true"){i.description=a("<div />").html(m.html()).css("color",m.css("color"))}else{i.description=""}},resize:function(){},close:function(){b.isOpenThumb=false}},gallery:{enabled:true},image:{headerFit:true,captionFit:true,preserveHeaderAndCaptionWidth:false,markup:'<div class="mfp-figure">                            <div class="mfp-img"></div>                            <div class="mfp-description"></div>                            <div class="mfp-counter"></div>                        </div>'}})})};a.fn.mdImage=function(){a.each(this,function(){var b=a(this);b.magnificPopup({delegate:".open-lightbox",type:"image",removalDelay:300,mainClass:"mfp-fade",callbacks:{markupParse:function(d,c,e){var f=a(".awe-image-caption",e.el);if(f.attr("data-on-lightbox")=="true"){c.title=a("<div />").html(f.html()).css("color",f.css("color"))}else{c.title=""}}},image:{headerFit:true,captionFit:true,preserveHeaderAndCaptionWidth:false}})})};a.fn.mdFlickr=function(){a.each(this,function(){var b=a(this);b.magnificPopup({delegate:".openlightbox",type:"image",removalDelay:300,mainClass:"mfp-fade",gallery:{enabled:true,preload:[0,2],navigateByImgClick:true}})})};a.fn.mdProcessAnimation=function(){var d=this,b=a(window).height(),c=0;a(window).scroll(function(){if(c<d.length){a.each(d,function(j,g){var m=g.getBoundingClientRect().top;if(m<b&&!a(g).data("awecontent-anim-played")){var n=a(g),f=n.data("animation"),l,h,i;if(a.type(f)=="string"){try{f=JSON.parse(f);l=f.type}catch(k){return false}}if(l!="none"){h=parseInt(f.duration);i=parseInt(f.delay);n.css({"animation-duration":h+"ms","animation-delay":i+"ms"});n.addClass("animated "+l)}a(g).data("awecontent-anim-played",1);c++}})}}).trigger("scroll");function e(g,h){var f="";switch(g){case"floatin":f="proty-dir-"+h;break;case"flyin":f="proty-dir-distant-"+h;break;case"turnin":f="proty-dir-turn-"+h;break}return f}};a.fn.mdParallax=function(){a.each(this,function(){a(this).parallax()})};a.fn.mdEventPlayer=function(){a.each(this,function(){var h=a(this),e=h.prevAll("iframe"),i=e.attr("id"),g=e.attr("src"),c=a("a",h),b,d,f;if(g.indexOf("//www.youtube.com/embed")!=-1){d="youtube"}else{if(g.indexOf("//player.vimeo.com/video")!=-1){d="vimeo"}}e[0].onload=function(){if(d=="youtube"){b=new YT.Player(i,{});h.click(function(){f=c.hasClass("pause-btn")?true:false;if(f){b.pauseVideo();c.removeClass("pause-btn").addClass("play-btn")}else{b.playVideo();c.removeClass("play--btn").addClass("pause-btn")}})}else{if(d=="vimeo"){b=Froogaloop(e[0]);h.click(function(){f=c.hasClass("pause-btn")?true:false;if(f){b.api("pause");c.removeClass("pause-btn").addClass("play-btn")}else{b.api("play");c.removeClass("play--btn").addClass("pause-btn")}})}}}})};a.fn.mdResizeBgVideo=function(){a.each(this,function(){var k=a(this),m=a("iframe",k),l=k.height(),d=k.width(),i=16/9,c=m.height(),f=m.width(),h,b,g,j=0,e=0;if(d/l>i){b=l*d/f;h=b*i+50;if(h<d){h=d;b=d*9/16}j=-(b-l)/2}else{h=f*l/c;b=h/i;e=-(h-d)/2}m.css({position:"absolute",width:h+"px",height:b+"px",top:j+"px",left:e+"px"})})};a.fn.mdTabs=function(){a.each(this,function(){a(this).tabs()})};a.fn.mdEqualHeight=function(){a.each(this,function(){var b=a(this).data("equalheight");if(b){if(a("> .container > .row > .awe-col",this).length>1){var c=a("> .container > .row > .awe-col",this),d=c.eq(0).height(),e;a.each(c,function(){e=a(this).height();if(e>d){d=e}});a.each(c,function(){a(this).height(d)})}}})};a.fn.awesectionFullscreen=function(){var b=this;c();a(window).resize(function(){c()});function c(){var d=a(window).height();a(b).height(d)}}})(jQuery);