#!/bin/bash
clang++ roverpi.cpp -o roverpi -lncurses -lwiringPi -lpthread -Lusr/lib -lboost_system -lboost_thread
