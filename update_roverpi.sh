#!/bin/bash
printf "ROVERPI UPDATE SCRIPT started\n"

printf "Deleting roverpi project file to provide clean build...\n"
rm -rf roverpi
printf "... done.\n"

printf "Cloning GitHub Repositority..."
git clone git@192.168.247.12:vortexlab/roverpi.git
printf "... done.\n"

printf "Building roverpi...\n"
cd roverpi/source
./compiler.sh
printf "... done.\n"
cd
printf "Run\n\nsudo rm /usr/bin/roverpi && sudo cp roverpi/source/roverpi /usr/bin\n\nto update executable."
