#!/bin/bash
echo "Enter first term of the AP : "
read a
echo "Enter the common differnce :"
read d
echo "Enter number of terms :"
read n
for ((i=0;i<=n;i++))
do
echo $((a+(i*d)))
done
