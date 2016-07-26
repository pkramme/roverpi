#!/bin/bash
cat video | nc.traditional 192.168.1.100 5000 & raspivid -o video -t 0 -w 480 -h 272
