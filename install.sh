#!bin/bash
apt-get update
apt-get install ncurses-dev
apt-get install git
apt-get install clang

cp update_roverpi.sh /home/pi/

cd
git clone git://git.drogon.net/wiringPi

cd roverpi/source
./compiler.sh

cp roverpi /usr/bin/
