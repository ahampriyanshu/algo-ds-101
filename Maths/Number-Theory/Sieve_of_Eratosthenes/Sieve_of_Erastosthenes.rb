class SieveOfErastosthenes
  def initialize(limit)
    @limit = limit
    @primes = initial_array
  end

  # Auto invokation of the class
  def self.call(limit)
    new(limit).call
  end

  def call
    find_primes
    @primes.select { |n| n }.length # Select only prime numbers in array and return only prime values.
  end
  
  private
  
  def initial_array
    (0..@limit).map {|i| i >= 2 ? true : false}
  end
  
  # Iterates over all truthies values to filter multiples and get primes
  def find_primes
    index = 0
    while index < @primes.length do
      find_multiples(index) if @primes[index]
      index += 1
    end
  end

  # Finds all multiples of the current index number, starting with its square.
  def find_multiples(index)
    multiples_index = index * index
    while multiples_index < @primes.length do
      @primes[multiples_index] = false
      multiples_index += index
    end
  end  
end

puts SieveOfErastosthenes.call(-1) # 0
puts SieveOfErastosthenes.call(1) # 0
puts SieveOfErastosthenes.call(100) # 25 
puts SieveOfErastosthenes.call(1000000) # 78498