class Queue
  include Enumerable
  Node = Struct.new :element, :next
  attr_reader :head, :tail, :size

  def initialize(items = [])
    @head = nil
    @tail = nil
    @size = 0

    items.to_ary.each { |element| enqueue element }
  end

  def enqueue(element)
    n = Node.new element, nil
    if @tail
      @tail.next = n
      @tail = n
    else
      @head = @tail = n
    end
    @size += 1
    element
  end

  def dequeue
    return nil unless @head

    n = @head
    if @size == 1
      clear
      return n.element
    end

    @head = n.next
    @size -= 1
    n.element
  end

  def front
    @head&.element
  end

  def back
    @tail&.element
  end

  def empty?
    @size.zero?
  end

  def clear
    @head = nil
    @tail = nil
    @size = 0
  end

  def each
    return unless @head

    n = @head
    while n
      yield n.element
      n = n.next
    end
  end

  alias << enqueue
end
