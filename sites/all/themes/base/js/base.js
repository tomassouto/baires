Drupal.behaviors.base = {
    attach: function (context, settings) {
        jQuery(document).ready(function(){

            jQuery('a.blank').click(function(){
                window.open(this.href);
                return false;
            });

        });
    }
};

// ON PAGE LOAD
setTimeout(function(){
    resizeFacebookComments();
}, 1000);

// ON PAGE RESIZE
jQuery(window).on('resize', function(){
    resizeFacebookComments();
});

function resizeFacebookComments(){
    if (jQuery('.fb-comments iframe').size() > 0) {
        var src   = jQuery('.fb-comments iframe').attr('src').split('width='),
        width = jQuery('.fb-comments').width();
        jQuery('.fb-comments iframe').attr('src', src[0] + 'width=' + width);
    }
}