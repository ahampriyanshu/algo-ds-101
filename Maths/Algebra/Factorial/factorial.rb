puts "Enter a non-negative number:"
num= gets.to_i

fact=1
if (num<0)
	puts "Factorial of a non-negative number doesn't exists"
else
	i=1
	while(i<=num)
		fact=fact*i
		i+=1
	end
	
	puts "factorial of #{num} is #{fact}"
end