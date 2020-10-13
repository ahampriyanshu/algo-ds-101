!#bin/bash
echo enter the value of n
read n
sum=0
k=$n
while [ $n -gt 0 ]
do
d=`echo $n%10|bc`
fact=1
i=1
while [ $i -le $d ]
do
fact=`echo $fact*$i|bc`
i=`echo $i+1|bc`
done
sum=`echo $sum+$fact|bc`
n=`echo $n/10|bc`
done
if [ $sum -eq $k ]
then
echo it is strong number
else
echo it is not strong number
fi