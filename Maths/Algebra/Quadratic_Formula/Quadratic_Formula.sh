#!/bin/bash
echo "Enter coefficients of a, b and c : "
read a b c
d=$((b*b - (4*a*c))) 

if [ $d -gt 0 ]
then
disc=$(bc <<< "scale=4;sqrt($d)")
x1=$(bc<<<"scale=4;((((-$b + $disc)/(2*$a))))")
x2=$(bc<<<"scale=4;((((-$b - $disc)/(2*$a))))")
echo "Roots are real and different"
echo " x1 = " $x1
echo " x2 = " $x2

elif [ $d -eq 0 ]
then
disc=$(bc <<< "scale=4;sqrt($d)")
x1=$(bc<<<"scale=4;(((((-$b + $disc)/(2*$a))))")
echo "Roots are real and equal"
echo " x1=x2= "$x1

elif [ $d -lt 0 ]
then
let "d=-d"
disc=$(bc<<<"scale=4;sqrt($d)")
real=$(bc<<<"scale=4;((-$b/(2*$a)))")
imag=$(bc<<<"scale=4;(($disc/(2*$a)))")
echo " x1 = "$real " + "$imag " i"
echo " x2 = "$real " - "$imag " i"
fi
