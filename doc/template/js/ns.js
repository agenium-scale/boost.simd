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
}

function ns_fixup_content() {
    var h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);

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

    var nav_container = $('<div class="row"></div>');
    $('#navrow1').parent().prepend(nav_container);
    var nav = $('<div class="col-md-12"></div>');
    for (i = 0; i < 8; i++) {
        var navrow = $('#navrow' + i + ' > ul.tablist').detach();
        nav.append(navrow);
        $('#navrow' + i).remove();
    }
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

    // TODO: Should we do something else if .tablist is not found?
    nav.find('.tablist').append(sb_html);
    $(nav_container).append(nav);

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
    var elts = $('.nav a');
    for (var i = 0; i < elts.length; ++i) {
        var e = $(elts[i]);
        var href = e.attr('href');
        if (page === href) {
            e.parent().addClass('current active');
        }
    }
    if (page.indexOf('group') != -1) {
        for (var i = 0; i < elts.length; ++i) {
            var e = $(elts[i]);
            console.log(e.attr('href'));
            if (e.attr('href').indexOf('modules') != -1) {
                e.parent().addClass('current active')
            }
        }
    }
    if (page.indexOf('class') != -1) {
        for (var i = 0; i < elts.length; ++i) {
            var e = $(elts[i]);
            console.log(e.attr('href'));
            if (e.attr('href').indexOf('modules') != -1) {
                e.parent().addClass('current active')
            }
        }
    }
    if (page.indexOf('namespace') != -1) {
        for (var i = 0; i < elts.length; ++i) {
            var e = $(elts[i]);
            console.log(e.attr('href'));
            if (e.attr('href').indexOf('modules') != -1) {
                e.parent().addClass('current active')
            }
        }
    }
    if (page.indexOf('tutorial') != -1) {
        for (var i = 0; i < elts.length; ++i) {
            var e = $(elts[i]);
            console.log(e.attr('href'));
            if (e.attr('href').indexOf('tutorial') != -1) {
                e.parent().addClass('current active')
            }
        }
    }
}
