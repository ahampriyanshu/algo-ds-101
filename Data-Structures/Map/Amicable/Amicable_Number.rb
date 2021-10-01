class AmicableNumber
  class << self
    def are_amicables?(number_1, number_2)
      # Prevents for not valid arguments errors
      raise ArgumentError, "Both arguments must be Integer positive number. Argumens: (#{number_1}, #{number_2})" unless is_valid?(number_1) && is_valid?(number_2)
      sum_divisors_of(number_1) === sum_divisors_of(number_2)
    end

    private
    # Validates if params are positive integer numbers
    def is_valid?(number)
      number.is_a?(Integer) && number > 0
    end

    # Returns the sum of the divisors
    def sum_divisors_of(number)
      divisors = divisors_of(number)
      divisors.sum
    end

    # Finds all divisor of each number
    def divisors_of(number)
      (1..number).select { |divisor| number % divisor === 0 }
    end
  end
end

puts AmicableNumber.are_amicables?(220, 284) # true
puts AmicableNumber.are_amicables?(1184, 1210) # true
puts AmicableNumber.are_amicables?(1184, 121) # false
puts AmicableNumber.are_amicables?("A", 98) # Raise error