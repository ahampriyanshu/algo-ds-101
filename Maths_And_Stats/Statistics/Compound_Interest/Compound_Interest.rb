#!/usr/bin/env ruby

def calculateCompoundInterest(principle, rate, time)
  result = principle * ((1 + rate / 100) ** time)
end

puts "Enter your principle value:"
principle = gets.to_f.round(2)
puts "Enter your rate value:"
rate = gets.to_f.round(2)
puts "Enter your time value:"
time = gets.to_i

puts "Your compound interest is #{calculateCompoundInterest(principle, rate, time)}"