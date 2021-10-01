class DynamicStack
  def initialize
    @stack = []
  end

  def is_empty?
    @stack.empty?
  end

  def push(value)
    @stack << value
  end

  def pop
    is_empty? ? nil : @stack.pop
  end

  def peek
    @stack.last
  end
end

class StaticStack
  # @param [Integer] capacity
  def initialize(capacity)
    @stack = Array.new(capacity)
    @top = -1
    @capacity = capacity
  end

  def is_empty?
    @top == -1
  end

  def push(value)
    raise "Stack full" if is_full?
    @top += 1
    @stack[@top] = value
  end

  def pop
    return nil if is_empty?
    value = @stack[top]
    @top -= 1
    value
  end

  def peek
    is_empty? ? nil : @stack[@top]
  end

  private

  def is_full?
    @top >= @capacity - 1
  end
end

stack_kinds = [DynamicStack, StaticStack]
params = [[], [4]]

stack_kinds.zip(params).each do |klass, param|
  puts "Create new stack: #{klass}"
  stack = klass.new(*param)
  puts "Is stack empty? #{stack.is_empty?}"
  (1..5).each do |num|
    puts "Push to stack: #{num}"
    stack.push(num)
  end
  puts "Element at top is #{stack.peek}"
  loop do
    break if stack.is_empty?
    puts "Pop Element: #{stack.pop}"
  end
end
