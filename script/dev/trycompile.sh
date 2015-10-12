#!/bin/bash

if [ $# -lt 1 ]
then
    echo "Usage: `basename $0` [-j<N>] <file>..."
    echo "NT2_SOURCE_ROOT, NT2_BINARY_ROOT and BOOST_ROOT must be defined"
    echo "Compiler can be defined with CXX"
    exit 65
fi

if ! ([ $NT2_SOURCE_ROOT ] && [ $NT2_BINARY_ROOT ] && [ $BOOST_ROOT ])
then
  echo "NT2_SOURCE_ROOT, NT2_BINARY_ROOT and BOOST_ROOT must be defined"
  exit 65
fi

if ! [ $CXX ]
then
  CXX=c++
fi

if echo $1 | grep -E "^-j[0-9]" > /dev/null
then
  args=${@:2}
  jobs=$(echo $1 | sed 's/-j//')
else
  args=$@
  jobs=1
fi

include_dirs=$(find $NT2_SOURCE_ROOT -regex $NT2_SOURCE_ROOT'/modules/.*/include' | grep -E -v $NT2_SOURCE_ROOT'/modules/.*/include/.*/include')
include_dirs="$BOOST_ROOT $include_dirs $NT2_BINARY_ROOT/include"

include_string=''
for i in $include_dirs
do
  include_string="$include_string -I$i"
done

function wait_jobs()
{
  while [ $(ps ax | grep $CXX | grep -v grep | wc -l) -ge $1 ]
  do
    sleep 1
  done
}

for i in $args
do
  command="$CXX -x c++ -Wall -Wfatal-errors -fsyntax-only $CXXFLAGS $include_string $i"
  if [ $VERBOSE ]
  then
    echo $command
  fi
  wait_jobs $jobs
  $command |& grep -v -F Wfatal-errors &
done
wait_jobs 1
