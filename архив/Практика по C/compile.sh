#!/bin/sh

gcc $1 -lm -o task.out
./task.out
rm task.out
