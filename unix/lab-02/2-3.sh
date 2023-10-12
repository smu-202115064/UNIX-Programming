#!/bin/bash

let x=1
let y=2

while (( y <= 9 ))
do
    let x=1
    while (( x <= 9 ))
    do
        if (( ($y * $x) >= 10 ))
        then
            echo -n " $(( $y * $x ))"
        else
            echo -n "  $(( $y * $x ))"
        fi
        let x+=1
    done
    echo ""
    let y+=1
done

exit 0