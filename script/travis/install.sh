#!/bin/sh
set -e

DEST_DIR=$HOME
TAR=$HOME/boost-trunk.tar.gz

# Get the tar
wget http://filebin.ca/2J8K4yniVwZ2 -O $TAR

# Extract the tar
tar -xzf $TAR -C $DEST_DIR
