#!/bin/bash

let a=$1
let b=$2

echo $a + $b = $(($a + $b))
echo $a - $b = $(($a - $b))
echo $a \* $b = $(($a * $b))
echo $a / $b = $(($a / $b))

exit 0
