// C# program to implement stooge sort 
    using System;

    class Program
    {
        /// <summary>
        /// Main application function.
        /// </summary>
        public static void Main()
        {
            int[] arr = { -32, 41, 6, -2, 16, 0, 23 };

            // Calling pancake Sort function 
            // to sort the array 
            PancakeSort(arr);

            // Display the sorted array 
            for (int i = 0; i < arr.Length-1; i++)
                Console.Write(arr[i] + " ");
        }

        /// <summary>
        /// Runs pancake sort on provided array
        /// </summary>
        /// <param name="array">array to be sorted</param>
        public static int[] PancakeSort(int[] array)
        {
            for (var subArrayLength = array.Length - 1; subArrayLength >= 0; subArrayLength--)
            {
                // get the position of the maximum element of the subarray
                var indexOfMax = IndexOfMax(array, subArrayLength);
                if (indexOfMax != subArrayLength)
                {
                    // flip the array to the maximum element index
                    // the maximum element of the subarray will be located at the beginning
                    Flip(array, indexOfMax);
                    // flip the entire subarray
                    Flip(array, subArrayLength);
                }
            }

            return array;

        }
        /// <summary>
        /// method to get the index of the maximum subarray element
        /// </summary>
        /// <param name="array">array to be searched</param>
        /// <param name="n">Max index</param>
        /// <returns>Index of max element</returns>
        private static int IndexOfMax(int[] array, int n)
        {
            int result = 0;
            for (var i = 1; i <= n; ++i)
            {
                if (array[i] > array[result])
                {
                    result = i;
                }
            }

            return result;
        }

        /// <summary>
        /// method for flipping the array
        /// </summary>
        /// <param name="array">Array to be modified</param>
        /// <param name="end">Index of last item to be flipped</param>
        private static void Flip(int[] array, int end)
        {
            for (var start = 0; start < end; start++, end--)
            {
                var temp = array[start];
                array[start] = array[end];
                array[end] = temp;
            }
        }
    }
