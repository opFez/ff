#!/bin/sh

clang src/mono.c -o bin/mono
clang src/is_farbfeld.c -o bin/is_farbfeld
clang src/mandelbrot.c -o bin/mandelbrot -lm -g
