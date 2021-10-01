echo "Enter any two numbers to find their LCM : "
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
lcm=$(((x*y)/a))
echo "LCM of "$x" and "$y" is = "$lcm
