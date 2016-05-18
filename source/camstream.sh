#!/bin/bash
raspivid -o - -t 99999 |cvlc -vvv stream:///dev/stdin --sout '#standard{access=http,mux=ts,dst=:8090}' :demux=h264