#!/bin/bash
echo "Enter number of terms in Fibonacci Series : "
read n
f0=0
f1=1
for((i=0;i<=n;i++))
do
f=$f0+$f1
f0=$f1
f1=$f
echo $((f))
done
