using System;
using System.Collections;
using System.Collections.Generic;

namespace DataStructures
{
    class SimpleQueue
    {
        private LinkedList<int> queue = new LinkedList<int>();

        public void Enqueue(int val) {
            queue.AddLast(val);
        }

        public int Dequeue() {
            int ret = queue.First.Value;
            queue.RemoveFirst();
            return ret;
        }
        public int Peek() {
            return queue.First.Value;
        }

        public int Size() {
            return queue.Count;
        }

        public bool IsEmpty() {
            return queue.Count == 0;
        }

        public void Print()
        {
            foreach (int i in queue) Console.Write(i + " ");
        }

        static void Main(string[] args)
        {
            SimpleQueue myQueue = new SimpleQueue();

            myQueue.Enqueue(55);
            myQueue.Enqueue(33);
            myQueue.Enqueue(12);
            myQueue.Enqueue(77);
            myQueue.Enqueue(25);

            Console.WriteLine("Current queue: ");
            myQueue.Print();
            Console.WriteLine();

            int n = myQueue.Dequeue();
            Console.WriteLine("The dequeued value: {0}", n);
            n = myQueue.Dequeue();
            Console.WriteLine("The dequeued value: {0}", n);
            Console.WriteLine("Current queue: ");
             myQueue.Print();
            Console.WriteLine();
        }
    }
}
