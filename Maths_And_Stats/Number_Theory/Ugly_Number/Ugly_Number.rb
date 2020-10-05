class UglyNumber
  VALID_DIVIDERS = [2, 3, 5] # All valid dividers are stored in array for a better manipulation
  
  def self.is_ugly?(number)
    # Checks if number is less or equal to one
    if number < 1
      return false
    elsif number == 1
      return true
    end
    ugly_dividers = VALID_DIVIDERS.select { |divider| number % divider == 0} # Select only the values which number can be divided
    ugly_dividers.any? ? is_ugly?(number / ugly_dividers.first) : false # If some divider exists, returns recursively the function with number divided by first divider as param
  end
end

puts UglyNumber.is_ugly?(0) # false
puts UglyNumber.is_ugly?(1) # true
puts UglyNumber.is_ugly?(6) # true
puts UglyNumber.is_ugly?(8) # true
puts UglyNumber.is_ugly?(14) # false
puts UglyNumber.is_ugly?(29) # false
puts UglyNumber.is_ugly?(101) # false
puts UglyNumber.is_ugly?(81) # true