#!/usr/bin/env ruby

puts "Enter the sides of the triangle:"
sides = gets.chomp(" ")
            .split(" ")
            .map(&:to_f)
            .sort

if sides.length != 3
  raise ArgumentError, "Please enter the lengths of the three sides of a triangle"
end

if sides[0]**2 + sides[1]**2 == sides[2]**2
  puts "According to Pythagorean Theorem, a^2 + b^2 = c^2, you have a right triangle"
else
  puts "According to Pythagorean Theorem, you do not have a right triangle"
end
