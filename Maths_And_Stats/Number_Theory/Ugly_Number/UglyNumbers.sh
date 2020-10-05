#!/bin/bash
echo "Enter a positive integer : "
read x
while [ $x -ne 1 ]
do
if [ $((x%2)) -eq 0 ]
then
  let "x/=2"
elif [ $((x%3)) -eq 0 ]
then
  let "x/=3"
elif [ $((x%5)) -eq 0 ]
then
  let "x/=5"
else
let "n=1"
echo "It is not a Ugly Number."
break
fi
done
if [ $((n)) -eq 0 ]
then
echo "It is a Ugly Number."
fi
exit
