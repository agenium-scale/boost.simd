function trimAll(t, search, replacement) {
    var chunks = t.split(search);
    var last = chunks.pop();
    chunks = chunks.filter(function (s) { return s != ""; });
    chunks.push(last);
    return chunks.join(replacement);
}

function doxygen_version() {
    var version = null;
    $.each($('address.footer').text().split('\n'), function (_, l) {
        l = l.trim();
        if (l == '') return;
        if (l.indexOf('Generated') != -1) return;
        if (version == null) {
            version = l;
        } else {
            // At this point, we have found more candidates than expected, just output a warning
            console.log('warn: Found multiple candidates for Doxygen version');
        }
    });
    var v = version.split('.');
    return [parseInt(v[0]), parseInt(v[1]), parseInt(v[2])];
}

function doxygen_version_upper(maj, min, rev) {
    var v = doxygen_version();
    return v[0] >= maj && v[1] >= min && v[2] >= rev;
}

// FIXME: For some reasons, I have to wait for smartmenus to apply its stuffs before actually
// stylising the #main-menu (I assume this is that..)
// This bug was introduced with doxygen 1.8.12, I hope this is not breaking previous versions.
function doxygen_fixup(f) {
    if (doxygen_version_upper(1, 8, 12)) {
        // Wait for smartmenus from here:
        var id;
        id = setInterval(function() {
            if ($('#main-menu').attr('data-smartmenus-id') !== null) {
                f();
                clearInterval(id);
            }
        }, 1);
    } else {
        f();
    }
}

function ns_style() {
    $("div.headertitle").addClass("page-header");
    $("div.title").addClass("h1");
    $("ul.tablist").addClass("nav nav-pills nav-justified unordered_list");
    $("li.current").addClass("active");
    $("#nav-path > ul").addClass("breadcrumb");
    $(".memitem").addClass("panel panel-default");
    $(".memproto").addClass("panel-heading");
    $(".memdoc").addClass("panel-body");
    $("span.mlabel").addClass("label label-info");
    $('table.doxtable').removeClass('doxtable').addClass('table table-striped table-bordered').each(function() {
        $(this).prepend('<thead></thead>');
        $(this).find('tbody > tr:first').prependTo($(this).find('thead'));
    });
    $(".memitem").removeClass('memitem');
    $(".memdoc").removeClass('memdoc');
    $("span.mlabel").removeClass('mlabel');
    $("table.memberdecls").removeClass('memberdecls');
    $("[class^=memitem]").removeClass('memitem');
    $("span.mlabels").removeClass('mlabels');
    $("table.mlabels").removeClass('mlabels');
    $("td.mlabels-right").removeClass('mlabels-right');
    $(".memproto").removeClass('memproto');
    $(".navpath").removeClass('navpath');
    $("a.el").removeClass('el');
    if (doxygen_version_upper(1, 8, 12)) {
        $("#main-menu").addClass('nav nav-pills nav-justified');
        $("#main-menu").css('visibility', 'initial');
    }
    $('.memtitle').css('display', 'none');
    $.each($('.memname'), function (_, tr) {
        var t = $(tr).text();
        t = trimAll(t, '\n', ' ');
        t = trimAll(t, '\t', ' ');
        // Yes.. trimAll basically splits, then filters empty strng, then join, this removes all
        // additional spaces inside the text.
        t = trimAll(t, ' ', ' ');
        t = trimAll(t, ' ( ', '(');
        t = trimAll(t, ' , ', ', ');
        t = trimAll(t, ' )', ')');
        t = trimAll(t, ' &', '&');
        var h = '';
        h += '<div class="ns-fun-decl">'
        h += t;
        h += '</div>'
        var $tr = $(tr);
        $tr.html(h);
        $tr.html($tr.html().replace(/&nbsp;/g, ""));
    })
}

function ns_fixup_content() {
    var h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
    //
    $('.contents').each(function (_, c) {
        console.log(c);
        c = $(c);
        h *= 0.8;
        if (c.height() < h) {
            c.height('' + h + 'px');
        }
    });
}

function ns_search_box(display) {
    function remove_current_search_box() {
        $('#MSearchBox').parent().remove();
        $('#MSearchBoxSelectWindow').remove();
        $('#MSearchBoxResultsWindow').remove();
    }
    // In any case we want to remove the current one
    remove_current_search_box();
    if (!display) return;
    //
    var nav_container, nav;
    if (doxygen_version_upper(1, 8, 12)) {
        $('#main-nav').find('li #MSearchBox').parent().empty();
    } else {
        nav_container = $('<div class="row"></div>');
        $('#navrow1').parent().prepend(nav_container);
        nav = $('<div class="col-md-12"></div>');
        for (i = 0; i < 8; i++) {
            var navrow = $('#navrow' + i + ' > ul.tablist').detach();
            nav.append(navrow);
            $('#navrow' + i).remove();
        }
    }
    //
    var sb_html = '';
    sb_html += '<li style="text-align: center; vertical-align: middle; padding-left: 25px; min-width: 200px; margin-left: 10px;">';
    sb_html += '  <div style="display: inline-block">';
    sb_html += '  <div id="search-box" class="input-group">';
    sb_html += '    <div class="input-group-btn">';
    sb_html += '      <button type="button" class="btn" data-toggle="dropdown">';
    sb_html += '        <span class="glyphicon glyphicon-search"></span> <span class="caret"></span>';
    sb_html += '      </button>';
    sb_html += '      <ul class="dropdown-menu">';
    sb_html += '      </ul>';
    sb_html += '    </div>';
    sb_html += '    <button id="search-close" type="button" class="close" aria-label="Close"><span aria-hidden="true">&times;</span></button>';
    sb_html += '    <input id="search-field" class="form-control" accesskey="S" onkeydown="searchBox.OnSearchFieldChange(event);" placeholder="Search ..." type="text">';
    sb_html += '  </div>';
    sb_html += '  </div>';
    sb_html += '</li>';
    //
    if (doxygen_version_upper(1, 8, 12)) {
        $('#main-menu').append(sb_html);
    } else {
        // TODO: Should we do something else if .tablist is not found?
        nav.find('.tablist:first').append(sb_html);
        $(nav_container).append(nav);
    }
    //
    $('#MSearchSelectWindow .SelectionMark').remove();
    var search_selectors = $('#MSearchSelectWindow .SelectItem');
    for (var i = 0; i < search_selectors.length; i++) {
        var element_a = $('<a href="#"></a>').text($(search_selectors[i]).text());
        element_a.click(function() {
            $('#search-box .dropdown-menu li').removeClass('active');
            $(this).parent().addClass('active');
            searchBox.OnSelectItem($('#search-box li a').index(this));
            searchBox.Search();
            return false;
        });
        var element = $('<li></li>').append(element_a);
        $('#search-box .dropdown-menu').append(element);
    }
    $('#MSearchSelectWindow').remove();
    //
    $('#search-box .close').click(function() {
        searchBox.CloseResultsWindow();
    });
    $('body').append('<div id="MSearchClose"></div>');
    $('body').append('<div id="MSearchBox"></div>');
    $('body').append('<div id="MSearchSelectWindow"></div>');
    searchBox.searchLabel = '';
    searchBox.DOMSearchField = function() {
        return document.getElementById("search-field");
    }
    var results_iframe = $('#MSearchResults').detach();
    $('#MSearchResultsWindow')
        .attr('id', 'search-results-window')
        .addClass('panel panel-default')
        .append(
            '<div class="panel-heading">\
                <h3 class="panel-title">Search Results</h3>\
                </div>\
                <div class="panel-body"></div>'
        );
    $('#search-results-window .panel-body').append(results_iframe);
    searchBox.DOMPopupSearchResultsWindow = function() {
        return document.getElementById("search-results-window");
    }
    $('#search-box .close').click(function() {
        searchBox.CloseResultsWindow();
    })
    searchBox.CloseResultsWindow();
}

function ns_nav() {
    var page = window.location.pathname.split('/').slice(-1).pop();
    var elts;
    if (doxygen_version_upper(1, 8, 12)) {
        elts = $('#main-menu a');
    } else {
        elts = $('.nav a');
    }
    for (var i = 0; i < elts.length; ++i) {
        var e = $(elts[i]);
        if (page === e.attr('href')) {
            e.parent().addClass('current active');
        }
    }
    if (page.indexOf('group') != -1 || page.indexOf('class') != -1 || page.indexOf('namespace') != -1) {
        for (var i = 0; i < elts.length; ++i) {
            var e = $(elts[i]);
            if (e.attr('href').indexOf('modules') != -1) {
                e.parent().addClass('current active')
            }
        }
    }
    if (page.indexOf('tutorial') != -1) {
        for (var i = 0; i < elts.length; ++i) {
            var e = $(elts[i]);
            if (e.attr('href').indexOf('tutorial') != -1) {
                e.parent().addClass('current active')
            }
        }
    }
}
