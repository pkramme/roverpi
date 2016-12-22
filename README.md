# RoverPi Project
NOTE: There are a lot of warnings when you compile due to the BCM2835 library. However, the RoverPi source code were tested with every possible warning on and passed without one warning.
The RoverPi source code is written and tested by the Jet Propulsion Laboratory specifications for safe C code and by the MISRA C specifications. 

## Project Introduction
RoverPi started out as an idea for a necessary school project for electric engineering and became quickly the largest project we've done so far. The idea was to build a remote controlled rover based on the Raspberry Pi 3b, which could drive around and should feature a webcam to capture the surrounding environment and stream it to the users device. What began as a simple looking project started out to became big. I am the to this point only software engineer on this project, while my friend Robert handle the electrics. 

## How to get it
You can either download the binary from here  
`https://dl.paukra.com/roverpi/roverpi-v.3.3.1`  
or clone the repository and build it yourself with  
`git clone https://git.paukra.com/paulkramme/roverpi.git`  
(You could also search the tags for your desired version.

## Software Walkthrough
Most Raspberry Pi software that has to acess GPIOs is written in Python, but i choosed C++ for the first version of the now named RoverPi project software, due to previous experience in C++, and i choosed WiringPi as the first library. I was not experienced in handling more than two source files and made many mistakes, which lead to the development of version 2, which primary language is C and for the library the more low-level bcm2835 library.  

## Who's this software for?
This software is for people who want to build their own RoverPi, that means a rover based on a pi, who don't have the skills or the time to work out a solution from scratch. I write an API for people who want to use my librarys to extend this library or to use it for their own projects. This project also works as a learning ground for me and the team.

## API and Versioning
The API Declaration can be found in the source files.
This software uses semantic versioning, the specification can be optained from  
http://semver.org