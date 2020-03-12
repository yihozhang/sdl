#!/bin/bash

case $1 in
    extrasmall)
        N=10
        ;;
    small)
        N=109
        ;;
    medium)
        N=768
        ;;
    large)
        N=1945
        ;;
    xlarge)
        N=50000000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac

LOW=0
MED=$N
HIGH=`expr $N \* 10`

# just seed fact files
mkdir -p facts
echo $LOW > low.facts
echo $MED > med.facts
echo $HIGH > high.facts

