#!/bin/bash
rm -rf roverpi
rm /usr/bin/roverpi
git clone git@github.com:paulkramme/roverpi.git
cd roverpi/source
./compiler.sh
cp roverpi /usr/bin/
