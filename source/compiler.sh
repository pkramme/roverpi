#!/bin/bash
clang++ roverpi.cpp -o roverpi -lncurses -lwiringPi -lpthread -std=c++11
