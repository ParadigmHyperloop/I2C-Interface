#!/bin/bash

MIN=$1
MAX=$3
STEP=$2
NSTEP=$(expr 0 - $STEP)

while [ true ]; do 

for i in $(seq $MIN 20 $MAX); do 
  for j in {14,13,30,29}; do 
    echo ">>> $i"
    ./ssr $j $i > /dev/null; 
  done; 
done; 

for i in $(seq $MAX -20 $MIN); do 
  for j in {14,13,30,29}; do
    echo "<<< $i" 
    ./ssr $j $i > /dev/null; 
  done; 
done; 

done
