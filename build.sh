#!/bin/sh

gcc examples/mono.c -o mono
gcc examples/is_farbfeld.c -o is_farbfeld
gcc examples/mandelbrot.c -o mandelbrot -lm -g
