shellsort()
{
    arr=("$@")
    len=${#arr[@]}
    gap=$(( $n / 2 ))
    while [ $gap -gt 0 ]; do
        for((ind=$gap;$ind<$n;ind++)); do
            temp=${arr[$ind]}
            j=$ind
            while [[ $j -ge $gap && ${arr[$(( $j - $gap ))]} -gt $temp ]]; do
                arr[$j]=${arr[$(( $j - $gap ))]}
                j=$(( $j - $gap ))
            done
            arr[$j]=$temp
        done
        gap=$(( $gap / 2 ))
    done
    echo ${arr[@]}
}


echo -n "Enter the total numbers: "
read n
echo "Enter numbers: "
i=0

while [ $i -lt $n ]
do
    read a[$i]

    i=`expr $i + 1`
done

shellsort ${a[@]}
