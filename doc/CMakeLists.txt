## -------------------------------------------------------------------------------------------------
##                              Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## -------------------------------------------------------------------------------------------------

## Find Doxygen
## -------------------------------------------------------------------------------------------------
find_package(Doxygen)

## -------------------------------------------------------------------------------------------------
macro(doc_if cond what)
  if (${cond})
    message(STATUS "[${PROJECT_NAME}] ${what}")
    message(STATUS "[${PROJECT_NAME}] Documentation cannot be built!")
    return()
  endif()
endmacro()

## Prerequisite for NumScale's doxygen template
## -------------------------------------------------------------------------------------------------
doc_if(NOT DOXYGEN_FOUND,   "Doxygen not found")
doc_if(NOT PROJECT_NAME,    "PROJECT_NAME is missing")
doc_if(NOT PROJECT_VERSION, "PROJECT_VERSION is missing")

## Main page + Sections
## -------------------------------------------------------------------------------------------------
set(DOXYGEN_MAIN_PAGE_TITLE "Home")
set(DOXYGEN_SECTIONS "
    <tab type='user' url='@ref quickstart' visible='yes' title='Quick Start'/>
    <tab type='user' url='@ref tutorials' visible='yes' title='Tutorials'/>
    <tab type='user' url='@ref faq' visible='yes' title='FAQ'/>
    <tab type='user' url='@ref group-api' visible='yes' title='Reference Documentation'/>
    "
)

## Generate Doxygen config
## -------------------------------------------------------------------------------------------------
configure_file(Doxyfile.in Doxyfile @ONLY)
configure_file(layout.xml.in layout.xml @ONLY)

## Add `doc` target
## -------------------------------------------------------------------------------------------------

include(../cmake/ns/doc/doxygen.cmake)
