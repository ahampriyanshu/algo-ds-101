// https://www.csharpstar.com/circular-singly-linked-list-csharp/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CircularLinkedList
{
    class Circularlist
    {
        private int currentdata;
        private Circularlist nextdata;
        public Circularlist()
        {
            currentdata = 0;
            nextdata = this;
        }
        public Circularlist(int value)
        {
            currentdata = value;
            nextdata = this;
        }
        public Circularlist Insdata(int value)
        {
            Circularlist node = new Circularlist(value);
            if (this.nextdata == this)
            {
                node.nextdata = this;
                this.nextdata = node;
            }
            else
            {
                Circularlist temp = this.nextdata;
                node.nextdata = temp;
                this.nextdata = node;
            }
            return node;
        }
        public int Deldata()
        {
            if (this.nextdata == this)
            {
                System.Console.WriteLine("\nOnly one node...");
                return 0;
            }
            Circularlist node = this.nextdata;
            this.nextdata = this.nextdata.nextdata;
            node = null;
            return 1;
        }
        public void Traverse()
        {
            Traverse(this);
        }
        public void Traverse(Circularlist node)
        {
            if (node == null)
                node = this;
            System.Console.WriteLine("Forward Direction...");
            Circularlist snode = node;
            do
            {
                System.Console.WriteLine(node.currentdata);
                node = node.nextdata;
            }
            while (node != snode);
        }
        public int Gnodes()
        {
            return Gnodes(this);
        }
        public int Gnodes(Circularlist node)
        {
            if (node == null)
                node = this;
            int count = 0;
            Circularlist snode = node;
            do
            {
                count++;
                node = node.nextdata;
            }
            while (node != snode);
            System.Console.WriteLine("\nCurrent Node Value : " + node.currentdata.ToString());
            System.Console.WriteLine("\nTotal nodes :" + count.ToString());
            return count;
        }
        static void Main(string[] args)
        {
            Circularlist node1 = new Circularlist(100);
            node1.Deldata();
            Circularlist node2 = node1.Insdata(200);
            node1.Deldata();
            node2 = node1.Insdata(200);
            Circularlist node3 = node2.Insdata(300);
            Circularlist node4 = node3.Insdata(400);
            Circularlist node5 = node4.Insdata(500);
            node1.Gnodes();
            node3.Gnodes();
            node5.Gnodes();
            node1.Traverse();
            node5.Deldata();
            node2.Traverse();
            node1.Gnodes();
            node2.Gnodes();
            node5.Gnodes();
            Console.Read();
        }
    }
}