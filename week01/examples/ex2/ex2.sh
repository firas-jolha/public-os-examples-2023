#!/bin/bash

PATTERN="*task*"
find /proc -name $PATTERN 1> output.txt 2> errors.txt

printf "\nFirst 3 lines of output.txt:\n"
head -n 3 output.txt

printf "\nFirst 3 lines of errors.txt\n"
head -n 3 errors.txt
