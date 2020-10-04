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

        public IEnumerator GetEnumerator()
        {
            return queue.GetEnumerator();
        }

        static void Main(string[] args)
        {
            // QUEUE
            // create a new queue object
            SimpleQueue myQueue = new SimpleQueue();

            // formatting
            Console.WriteLine("====================================");
            Console.WriteLine("Queue:");
            Console.WriteLine("====================================");

            // enque 4 items to the queue
            myQueue.Enqueue(55);
            myQueue.Enqueue(33);
            myQueue.Enqueue(12);
            myQueue.Enqueue(77);
            // print the contents of the queue
            Console.WriteLine("Current queue: ");
            foreach (int i in myQueue) Console.Write(i + " ");
            Console.WriteLine();

            // remove first value from queue "A"
            Console.WriteLine("Removing some values ");
            int n = myQueue.Dequeue();
            Console.WriteLine("The removed value: {0}", n);
            // remove newly first value from queue "M"
            n = myQueue.Dequeue();
            Console.WriteLine("The removed value: {0}", n);
            // print the contents of the queue
            Console.WriteLine("Current queue: ");
            foreach (char i in myQueue) Console.Write(i + " ");
            Console.WriteLine();

            // formatting
            Console.WriteLine("====================================");

            // wait for user input to close program
            Console.ReadLine();
        }
    }
}
