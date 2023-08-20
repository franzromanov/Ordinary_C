#!/bin/bash
cc -c -g RPS.c
cc -c -g frank_talk.c
cc -c -g gameplay.c
cc -o RPS RPS.o frank_talk.o gameplay.o
