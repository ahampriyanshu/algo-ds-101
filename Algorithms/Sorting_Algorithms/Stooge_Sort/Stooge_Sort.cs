using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    // C# program to implement stooge sort 
    using System;

    class Program
    {
        /// <summary>
        /// Main application function.
        /// </summary>
        public static void Main()
        {
            int[] arr = { 2, 4, 5, 3, 1 };
            int n = arr.Length;

            // Calling Stooge Sort function 
            // to sort the array 
            StoogeSort(ref arr);

            // Display the sorted array 
            for (int i = 0; i < n; i++)
                Console.Write(arr[i] + " ");
        }

        /// <summary>
        /// Runs stooge sort on provided array
        /// </summary>
        /// <param name="arr">array to be sorted</param>
        /// <param name="lowIndex">Low index of current sort</param>
        /// <param name="highIndex">High index of current sort</param>
        public static void StoogeSort(ref int[] arr)
        {
            StoogeSort(ref arr,0,arr.Length-1);
        }
        /// <summary>
        /// Runs stooge sort on provided array
        /// </summary>
        /// <param name="arr">array to be sorted</param>
        /// <param name="lowIndex">Low index of current sort</param>
        /// <param name="highIndex">High index of current sort</param>
        public static void StoogeSort(ref int[] arr, int lowIndex, int highIndex, int? depth = 0)
        {
            int arrayLength = (highIndex - lowIndex + 1);
            //if there are not 2 items here, we are done
            if (arrayLength <= 1)
                return;


            // If first element is smaller 
            // than last, swap them 
            if (arr[lowIndex] > arr[highIndex])
            {
                int tempLowIndexValue = arr[lowIndex];
                arr[lowIndex] = arr[highIndex];
                arr[highIndex] = tempLowIndexValue;
            }
            
            //if only 2 values, we know we are done. start to end recursion
            if (arrayLength == 2)
                return;
            
            int thirdOfArrayLength = (highIndex - lowIndex + 1) / 3;

            // Recursively sort first  
            // 2/3 elements 
            
           StoogeSort(ref arr, lowIndex, highIndex - thirdOfArrayLength, depth +1);
            // Recursively sort last 
            // 2/3 elements 
            StoogeSort(ref arr, lowIndex +thirdOfArrayLength, highIndex, depth + 1);

            // Recursively sort first  
            // 2/3 elements again to  
            // confirm 
            StoogeSort(ref arr, lowIndex, highIndex - thirdOfArrayLength, depth + 1);
            
        }

    }
}
