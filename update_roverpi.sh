#!/bin/bash
rm -rf roverpi
rm /usr/bin/roverpi
git clone git@192.168.247.12:vortexlab/roverpi.git
cd roverpi/source
./compiler.sh
cp roverpi /usr/bin/
