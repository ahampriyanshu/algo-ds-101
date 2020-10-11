#!/bin/bash
echo "Enter a positive integer : "
read x
while [ $x != 1 ] 
do
	if [ $x%2 == 0 ]
	then
	$x = $x/2	
	fi
done
echo "done"
exit
