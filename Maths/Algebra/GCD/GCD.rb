#!/usr/bin/env ruby -w

def gcd(num1, num2)
  return num1 if num2 == 0

  gcd(num2, num1 % num2)
end

num1 = gets.chomp.to_i
num2 = gets.chomp.to_i
puts gcd(num1, num2)