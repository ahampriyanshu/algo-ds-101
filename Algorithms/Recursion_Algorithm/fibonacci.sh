fibonacci()
{
	if [ $1 -le 0 ]
	then
		echo -n "invalid input !"
	elif [ $1 == 1 ]
	then
		echo -n "0 "
	elif [ $1 == 2 ]
	then
		echo -n "1 "
	else
		echo -n "$[`fibonacci $[$1-2]` + `fibonacci $[$1 - 1]` ] "
	fi
}
echo "Enter a number: "
read n
fibonacci $n
echo 

