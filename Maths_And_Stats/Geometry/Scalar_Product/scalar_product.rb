# @param [Array] vector_a
# @param [Array] vector_b
def scalar_product(vector_a, vector_b)
  raise "Different vector dimension" unless vector_a.length == vector_b.length
  vector_a.zip(vector_b)
    .map { |a, b| a * b }
    .sum
end

puts "Enter vector value separated by comma, like 1,2,3,4,5"
print "First vector => "
vector_a = gets.chomp.split(",").map(&:to_f)
print "Second vector => "
vector_b = gets.chomp.split(",").map(&:to_f)
puts "Scalar product: #{scalar_product(vector_a, vector_b)}"
