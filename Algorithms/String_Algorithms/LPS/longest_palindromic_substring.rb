
puts "Enter the String:"
input = gets.chomp
puts "Entered String is: '#{input}'."

n = input.length

table = Array.new(n) { Array.new(n, false) }

max_len = 1
i = 0
while (i < n)
  table[i][i] = true
  i = i + 1
end

start = 0
i = 0
while i < n - 1
  if (input[i] == input[i + 1])
    table[i][i + 1] = true
    start = i 
    max_len = 2
  end
  i = i + 1
end

k = 3
while k <= n
  i = 0
  while i < (n - k + 1)
    j = i + k - 1
    if (table[i + 1][j - 1] and input[i] == input[j])
      table[i][j] = true

      if k > max_len
        start = i 
        max_len = k
      end
    end
    i = i + 1
  end
  k = k + 1
end

puts "Longest palindromic substring is #{input[start..start+max_len-1]}"
