#!/bin/sh
set -e

DEST_DIR=$HOME
TAR=$HOME/boost-trunk.tar.gz

# Get the tar
wget numscale.com/boost-trunk.tar.gz -O $TAR

# Extract the tar
tar -xzf $TAR -C $DEST_DIR

# Get boost.dispatch
DISPATCH_DIR=$DEST_DIR/dispatch
git clone https://github.com/NumScale/boost.dispatch.git $DISPATCH_DIR
