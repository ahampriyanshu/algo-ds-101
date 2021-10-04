#!/bin/bash
# Bubble Sort Array sorting algortihm in O(n^2) complexity
# E.g. Array Size = 6
# Elements:
# 1
# 7
# 8
# 14
# 12
# 21
# Sorted Array:
# 1
# 7
# 8
# 12
# 14
# 21

echo "Enter Array Size"
read len

# taking input from user
echo "Provide Number for an Array:"
for (( i = 0; i < $len; i++ ))
do
    read arr[$i]
done

# Bubble Sort Logic
for (( i = 0; i < $len ; i++ ))
do
    for (( j = $i; j < $len; j++ ))
    do
        if [ ${arr[$i]} -gt ${arr[$j]}  ]; then
            temp=${arr[$i]}
            arr[$i]=${arr[$j]}
            arr[$j]=$temp
        fi
    done
done

# Printing the sorted number
echo "Sorted Array: "
for (( i=0; i < $len; i++ ))
do
    echo ${arr[$i]}
done