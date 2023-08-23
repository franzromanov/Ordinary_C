#!/bin/bash
x86_64-w64-mingw32-gcc -c -g RPS.c
x86_64-w64-mingw32-gcc -c -g frank_talk.c
x86_64-w64-mingw32-gcc -c -g gameplay.c
x86_64-w64-mingw32-gcc -o RPS RPS.o frank_talk.o gameplay.o
