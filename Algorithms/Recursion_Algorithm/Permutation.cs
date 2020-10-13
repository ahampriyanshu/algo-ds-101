using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode46
{
    class Permutations
    {
        public static List<string> SinglePermutations(string s)
        {
			// Example: s = "abc"
			
			// Set is used to avoid duplicates
            var hash = new SortedSet<string>();
            var stack = "";
            int len = s.Length;
            GetPermutations(s, hash, stack, len);
            return new List<string>(hash);
			
			// returned value is ["abc", "acb", "bac", "bca", "cab", "cba"] 
        }

        private static void GetPermutations(string item, SortedSet<string> hash, string stack, int len)
        {
			// Checks length of stack if equal to that of item
            if (stack.Length == len)
            {
                hash.Add(stack);
            }
            else
            {
				// lops through the 
                for (var i = 0; i < item.Length; i++)
                {
					// Adds an item to the stack
                    stack += item[i];
					// Populates available combinations and permutation
					// with the elements in stack
                    GetPermutations(item.Remove(i, 1), hash, stack, len);
                    // Removes the last item in stack
					stack = stack.Remove(stack.Length - 1, 1);
                }
            }
        }
    }
}
