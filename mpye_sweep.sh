#!/bin/bash
for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
do
    let x=i*100
    let z=800+$x
    echo $z
    sleep 0.1
    ./ssr_thing 13 $z
done
./ssr_thing 13 0
