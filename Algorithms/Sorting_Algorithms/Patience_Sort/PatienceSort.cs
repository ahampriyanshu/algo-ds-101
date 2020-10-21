using System;
using System.Collections.Generic;

// To compile: csc PatienceSort.cs
namespace PatienceSort
{    
    class Program
    {
        //Example:
        static void Main(string[] args)
        {
            // Expected input:
            // One line, n: ammount of integer numbers to sort
            // next n lines: A new number
            // Example:
            // 4
            // 3
            // 1
            // 2
            // 4
            // Prints the following output:
            // 1 2 3 4 

            int n = Convert.ToInt32(Console.ReadLine());
            int[] numbers = new int[n];

            for(var i = 0; i < n; i++)
                numbers[i] = Convert.ToInt32(Console.ReadLine());

            // We pass the array numbers. At the end of the function, it should be sorted
            PatienceSort(ref numbers);

            // Print output array
            foreach (var i in numbers)
                Console.Write(i.ToString() + ' ');
            Console.WriteLine();

        }

        /*
            Patience sort works the same way as the "Patience" card game.
            We start with a deck of cards (a number array in this case) and,
            for each card, we search the left-most pile such that the card at the top
            of the pile is higher or equal to out current card. If we can't find such
            pile, we start a new one after the rightmost pile with only the current card,
            and so on until we run out of cards

            When there's no more cards, we take the smallest visible card (aka the smallest 
            card at the top of some pile) and take it, and we repeat until there's no more 
            piles.

            The resulting sequence of cards turns out to be sorted :)

            The following is a simulation of a 'Patience' game. 
        */        
        static void PatienceSort(ref int[] numbers) 
        {
            // The list of piles, the maximum number of piles we could have is
            // n (the number of elements in the array), when all elements
            // are sorted in increasing order. (Note that C# could increase the 
            // size of the list, but we prefer to allocate space only once)
            List<Stack<int>> piles = new List<Stack<int>>(numbers.Length);


            // For each number, find the pile such that
            // its top is greater or equal, and put 
            // this number as its top
            foreach(var i in numbers) 
            {
                // 'pushed' checks if there's a stack that can hold our
                // current number, if it does not exist, push a new one
                var pushed = false; 
                foreach(var pile in piles)
                    if (pile.Peek() >= i)
                    {
                        pile.Push(i);
                        pushed = true;
                        break; // We only care about the left-most
                    }

                if (!pushed) 
                { 
                    // Since we couldn't add this number to any pile, we create a new one
                    // with just this number
                    var newStack = new Stack<int>();
                    newStack.Push(i);
                    piles.Add(newStack);
                }
            }

            var nextNum = 0; // next array position
            int minPile = 0;     // the index of the pile with the smallest top 
            var empty = false;
            while(!empty) // We stop when every pile is empty
            {
                var min = int.MaxValue;
                empty = true;
                // We search linearly the minimum until there's no more numbers  
                for(var i = 0; i < piles.Count; i++){
                    var pile = piles[i];

                    empty = empty && pile.Count == 0;

                    if(pile.Count == 0)
                        continue; // If the pile is empty, we skip it

                    if(pile.Peek() <= min)
                    {
                        min = pile.Peek();
                        minPile = i;
                    }
                }

                // If we found a new number, add it in its corresponding position
                if(!empty)
                {
                    numbers[nextNum] = piles[minPile].Pop();
                    nextNum++;
                }
            }
        }
    }
}
