#!/bin/bash
cc -c -g RPS.c
cc -c -g frank_talk.c
cc -o RPS RPS.o frank_talk.o
