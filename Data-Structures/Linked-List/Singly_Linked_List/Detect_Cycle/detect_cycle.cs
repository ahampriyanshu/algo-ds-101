using System;
namespace DSA
{
    public class Node
    {
        public int Value { get; set; }
        public Node Next;
        public Node(int val)
        {
            this.Value = val;
        }
    }

    class ClosedLoop
    {
        public static bool DetectLoop(Node _head)
        {
            Node slow = _head, fast = _head.Next.Next;
            while (slow != null && fast != null && fast.Next != null)
            {
                if (slow == fast)
                {
                    Console.WriteLine("Loop detected at: " + slow.Value);
                    return true;
                }
                slow = slow.Next; //1 step increment
                fast = fast.Next.Next; //2 step increment
            }
            return false;
        }

        static void Main(string[] args)
        {
            Node tail = new Node(0);
            Node _actualHead = tail;

            Node intersection = null;

            //Creating linked list by adding nodes to the end of the list.
            for (int i = 1; i < 10; i++)
            {
                Node n = new Node(i);
                tail.Next = n;
                tail = n;
                //Taking the loop intersection. Comment below 'if' to avoid loop.
                if (i == 4)
                    intersection = tail;
            }

            //Completing the loop
            tail.Next = intersection;

            if (!DetectLoop(_actualHead))
                Console.WriteLine("No loop detected");
        }
    }
}
