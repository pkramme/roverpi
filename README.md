# RoverPi Project
The API Declaration can be found in the source files.
In order to get this software working, you have to install the BCM2835 library. It can be obtained from  
http://www.airspayce.com/mikem/bcm2835/index.html  
This software is distributed under the MIT-License which can be found in LICENSE or at  
https://opensource.org/license/MIT  
This software uses semantic versioning, the specification can be optained from  
semver.org

## Project Introduction
RoverPi started out as an idea for a necessary school project for electric engineering and became quickly the largest project we've done so far. The idea was to build a remote controlled rover based on the Raspberry Pi 3b, which could drive around and should feature a webcam to capture the surrounding environment and stream it to the users device. What began as a simple looking project started out to became big. I am the to this point only software engineer on this project, while my friend Robert handle the electrics. 

## Software Walkthrough
Most Raspberry Pi software that has to acess GPIOs is written in Python, but i choosed C++ for the first version of the now named RoverPi project software, due to previous experience in C++, and i choosed WiringPi as the first library. I was not experienced in handling more than two source files and made many mistakes, which lead to the development of version 2, which primary language is C and for the library the more low-level bcm2835 library, which, for the sake of GPL License, couldn't be included in the source files.

## Who's this software for?
This software is for people who want to build their own RoverPi, that means a rover based on a pi, who don't have the skills or the time to work out a solution from scratch. I write an API for people who want to use my librarys to extend this library or to use it for their own projects. This project also works as a learning ground for me and the team.
