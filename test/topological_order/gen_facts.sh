
# include general utilities
# . `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $1 in
    small)
        N=389
        ;;
    medium)
        N=1342
        ;;
    large)
        N=2572
        ;;
    xlarge)
        N=50000000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac

N=$N        # number of elements in tree



echo -e "0\t1" > edge.facts
for i in `seq 1 $N` ; do
    j=`expr 2 \* $i`
    echo -e "$i\t$j" >> edge.facts
    j=`expr 1 + $j`
    echo -e "$i\t$j" >> edge.facts
done