echo -n "Enter number : "
read n

# store single digit
i=1
# store number of digit
sum=0
# use while loop to caclulate the sum of all digits
while [ $i -le $n ]
  do
   sum=$(( $sum + $i )) # calculate sum of digit
        i=$(( $i + 1 ))
  done
echo  "Sum of all digit  is $sum"
