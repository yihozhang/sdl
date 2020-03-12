case $1 in
    small)
        N=9
        ;;
    medium)
        N=21
        ;;
    large)
        N=30
        ;;
    xlarge)
        N=40
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac


LOW1=-$N         # number of entries
HIGH1=$N         # range of entries
LOW2=0           # number of entries
HIGH2=$N         # range of entries


# just seed fact files
echo $LOW1 > low1.facts
echo $LOW2 > low2.facts
echo $HIGH1 > high1.facts
echo $HIGH2 > high2.facts
