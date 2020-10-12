echo "Enter the number of elements in the array: "
read n

echo "Enter the elements: "
read -a arr

for (( i = 0; i < $n ; i++ ))
do
        for (( j = $i; j < $n; j++ ))
        do
                if [ ${arr[$i]} -gt ${arr[$j]} ]; then
                        t=${arr[$i]}
                        arr[$i]=${arr[$j]}
                        arr[$j]=$t
                fi
        done
done

echo "After Sorting: "
for (( i=0; i < $n; i++ ))
do
        echo ${arr[$i]}
done
