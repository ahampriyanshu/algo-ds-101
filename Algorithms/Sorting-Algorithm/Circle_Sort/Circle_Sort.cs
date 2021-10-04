 // C# program to implement circle sort 
    using System;

    class Program
    {
        /// <summary>
        /// Main application function.
        /// </summary>
        public static void Main()
        {
            int[] arr = { -32, 41, 6, -2, 16, 0, 23 };

            // Calling circle Sort function 
            // to sort the array 
            CircleSort(arr);

            // Display the sorted array 
            for (int i = 0; i < arr.Length-1; i++)
                Console.Write(arr[i] + " ");
        }

        public static void CircleSort(int[] array)
        {
            var swapMade = false;
            do
            {
                swapMade = CircleSort(array, 0, array.Length - 1);
            } while (swapMade);

        }

        /// <summary>
        /// Runs circle sort on provided array
        /// </summary>
        /// <param name="array">array to be sorted</param>
        /// <param name="lowIndex">Index to start at</param>
        /// <param name="highIndex">Index to end at</param>
        private static bool CircleSort(int[] array, int lowIndex, int highIndex)
        {
            bool swapMade = false;
            if (lowIndex == highIndex)
                return swapMade;
            var subArrayLength = highIndex - lowIndex;
            var midPoint = subArrayLength / 2;

            int currentLowIndex = lowIndex;
            int currentHighIndex = highIndex;
            while (currentLowIndex < currentHighIndex) {
                if (array[currentLowIndex] > array[currentHighIndex]) {
                    var tempLowValue = array[currentLowIndex];
                    array[currentLowIndex] = array[currentHighIndex];
                    array[currentHighIndex] = tempLowValue;
                    swapMade = true;
                }
                currentLowIndex++;
                currentHighIndex--;
            }

            swapMade |= CircleSort(array, lowIndex, lowIndex + midPoint);
            swapMade |= CircleSort(array,lowIndex + midPoint + 1, highIndex);
            return swapMade;

        }
    }
