#!/bin/bash
echo "Enter first term of the Geometric Progression : "
read a
echo "Enter the common ratio : "
read r
echo "Enter the number of terms in Geometric Progression : "
read n
echo $((a))
for((i=1;i<=n;i++))
do
nth=$((a*(r**i)))
echo $((nth))
done
