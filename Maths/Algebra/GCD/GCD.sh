#!/bin/bash
echo "Enter two numbers to find their GCD"
read a b
x=$((a))
y=$((b))
while [ $a -ne $b ]
do
if [ $a -gt $b ]
then 
let "a-=b"
else
let "b-=a"
fi
done 
echo "The GCD of "$((x))" and "$((y))" is =  "$((a))
exit
