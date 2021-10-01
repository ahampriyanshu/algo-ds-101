using System;
using System.Collections.Generic;

namespace Stack
{
  class Program
  {
    static void Main(string[] args)
    {
      Stack stack = new Stack();
      Console.WriteLine(stack.isEmpty());
      for (int i = 1; i < 6; i++)
      {
        stack.Push(i);
      }
      Console.WriteLine(stack.isEmpty());
      stack.Peek();
      for (int i = 1; i < 6; i++)
      {
        stack.Pop();
      }
      Console.WriteLine(stack.isEmpty());
    }
  }

  class Stack
  {
    List<int> stack = new List<int>();
    int top;

    public Stack()
    {
      top = -1;
    }

    public void Push(int value)
    {
      stack.Add(value);
      top++;
    }

    public void Pop()
    {
      if (isEmpty())
      {
        Console.WriteLine("Stack is empty!");
      }
      int value = stack[top];
      stack.RemoveAt(top);
      top--;
      Console.WriteLine($"The value {value} was removed of stack");
    }

    public void Peek()
    {
      if (isEmpty())
      {
        Console.WriteLine("Stack is empty!");
      }
      Console.WriteLine($"The topmost element of stack is {stack[top]}");
    }

    public bool isEmpty()
    {
      return top == -1;
    }
  }
}
