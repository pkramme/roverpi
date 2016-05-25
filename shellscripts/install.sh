#!/bin/bash
printf "ROVERPI INSTALL SCRIPT starting\n"
printf "Installing nessesary dependecies...\n"
apt-get update
apt-get install ncurses-dev
apt-get install git
apt-get install clang
apt-get install libboost-all-dev
printf "... done.\n"

printf "Copying update_roverpi.sh to home folder\n"
cd ..
cp update_roverpi.sh /home/pi/

printf "Cloning wiringPi...\n"
cd
git clone git://git.drogon.net/wiringPi
cd wiringPi
printf "... done.\n"
printf "Building wiringPi...\n"
./build
printf "... done.\n"

printf "Building roverpi...\n"
cd
cd /home/pi/roverpi/shellscripts
./compiler.sh
printf "... done.\n"
printf "run\n\nsudo cp roverpi /usr/bin/\n\nto use 'sudo roverpi' to start roverpi.\n"
