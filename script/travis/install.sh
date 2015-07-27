#!/bin/sh
set -e

# If using g++ compiler settings, bring down the newest one
 if [ "$CC" = "gcc" ];
  then
  sudo apt-get install -qq gcc-4.9 g++-4.9 gcc-5 g++-5;
fi

# Get Boost 1.58
wget http://sourceforge.net/projects/boost/files/boost/1.58.0/boost_1_58_0.tar.bz2/download -O /tmp/boost.tar.bz2
tar jxf /tmp/boost.tar.bz2
mv boost_1_58_0/ $HOME/boost-trunk/
cd $HOME/boost-trunk && ./bootstrap.sh

# Get LCOV and fix gcov
if [ "$CC" = "gcc" ];
  then
  wget http://sourceforge.net/projects/ltp/files/Coverage%20Analysis/LCOV-1.11/lcov-1.11.tar.gz/download -O lcov-1.11.tar.gz
  tar xvfz lcov-1.11.tar.gz
  sudo make -C lcov-1.11 install
  rm -rf lcov-1.11.tar.gz lcov-1.11
  sudo cp -v `which gcov-4.8` `which gcov`;
fi
