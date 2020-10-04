#
# Calculate N-dimensional distance
#
# @param [Array] vector_a
# @param [Array] vector_b
#
# @return [Float] distance
#
def n_dims_distance(vector_a, vector_b)
  raise "Dimension mismatch" unless vector_a.length == vector_b.length
  sum = vector_a.zip(vector_b)
    .map { |a, b| (a - b)**2 }
    .sum
  Math.sqrt(sum)
end

puts "Enter vector value separated by comma, like 1,2,3,4,5"
print "First vector => "
vector_a = gets.chomp.split(",").map(&:to_f)
print "Second vector => "
vector_b = gets.chomp.split(",").map(&:to_f)
puts "Distance: #{n_dims_distance(vector_a, vector_b).round(3)}"
