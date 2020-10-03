using System;
using System.Collections.Generic;

namespace BubbleSort
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> list = new List<int>{ 2, 1, 45, 2, 8, 33, 99, 123, 56, 85 };

            Console.WriteLine("Before sorting: ");
            foreach (var number in list)
            {
                Console.Write(number + " ");
            }
            BubbleSort(list);

            Console.WriteLine("\nAfter sorting: ");
            foreach (var number in list)
            {
                Console.Write(number + " ");
            }
        }

        static void BubbleSort(List<int> list)
        {
            for (int i = 0; i < list.Count; i++)
            {
                for (int j = 1; j < list.Count - i; j++)
                {
                    if(list[j-1] > list[j])
                    {
                        var temp = list[j-1];
                        list[j-1] = list[j];
                        list[j] = temp;
                    }
                }
            }
        }
    }
}
