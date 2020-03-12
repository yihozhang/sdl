#!/bin/bash

case $1 in
    small)
        N=169
        ;;
    medium)
        N=598
        ;;
    large)
        N=1170
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
HIGH=`expr $N \* 2`

# just seed fact files
echo $LOW > low.facts
echo $MED > med.facts
echo $HIGH > high.facts