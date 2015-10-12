#!/bin/sh
set -e

# Get Boost develop
git clone --recursive https://github.com/boostorg/boost.git boost-trunk
cd boost-trunk/
git submodule foreach --recursive "git checkout develop; git pull"
cd libs
git clone https://github.com/jfalcou/boost.dispatch.git dispatch
git checkout develop
cd ..
./bootstrap.sh
./b2 headers
cd ..
mv boost-trunk/ $HOME/boost-trunk/
