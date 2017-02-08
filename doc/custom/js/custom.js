// The JS entry-point

// FIXME: For some reasons, I have to wait for smartmenus to apply its stuffs before actually
// stylising the #main-menu (I assume this is that..)
// This bug was introduced with doxygen 1.8.12, I hope this is not breaking previous versions.
function wait_for_smartmenus(f) {
    var id;
    id = setInterval(function() {
        if ($('#main-menu').attr('data-smartmenus-id') !== null) {
            f();
            clearInterval(id);
        }
    }, 1);
}

$(document).ready(function() {
    wait_for_smartmenus(function() {
        ns_style();
        ns_nav();
        ns_search_box(true);
    });
});
