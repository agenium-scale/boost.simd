#!/bin/bash

if [ $# -lt 1 ]
then
    echo "Usage: `basename $0` [-j<N>] <file>..."
    echo "BOOST_ROOT must be defined"
    echo "Compiler can be defined with CXX"
    echo "Compiler flags can be defined with CXXFLAGS"
    exit 65
fi

if ! ([ $BOOST_ROOT ])
then
  echo "BOOST_ROOT must be defined"
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

include_dirs="$BOOST_ROOT"

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
  command="$CXX -x c++ -std=c++11 -Wall -Wfatal-errors -fsyntax-only $CXXFLAGS $include_string $i"
  if [ $VERBOSE ]
  then
    echo $command
  fi
  wait_jobs $jobs
  $command |& grep -v -F Wfatal-errors &
done
wait_jobs 1
