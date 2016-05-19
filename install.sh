#!bin/bash
printf "ROVERPI INSTALL SCRIPT starting"
printf "Installing nessesary dependecies...\n"
apt-get update
apt-get install ncurses-dev
apt-get install git
apt-get install clang
printf "... done.\n"

printf "Copying update_roverpi.sh to home folder\n"
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
cd roverpi/source
./compiler.sh
printf "... done.\n"
printf "run\n\nsudo cp roverpi /usr/bin/\n\nto use 'sudo roverpi' to start roverpi.\n"