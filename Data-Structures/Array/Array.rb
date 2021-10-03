#!/usr/bin/ruby

#If the elments are string
puts "Enter the elements with space"

#Taking stdin as string
array_as_string =  gets

#Spliting each elements(substring) separated by delimiter whitespace and returning an array
arrayStringType = array_as_string.split

#Prints the array in newline
puts arrayStringType

#------------------------------------------------------------------------

#If the elements are integers
puts "Enter the the elements with space"

#Taking stdin as string
array_as_string =  gets

#Spliting each elements separated by delimiter whitespace, converting substrings to integer and returning as array
arrayIntegerType = array_as_string.split.map(&:to_i)

#Prints the array in newline
puts arrayIntegerType