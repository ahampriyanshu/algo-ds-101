using System;

namespace Tower_Of_Hanoi
{
    class Tower_Of_Hanoi
    {
        static void Main(string[] args)
        {
            int numOfDisks;
            char source = 'A', auxiliary = 'B', destination = 'C';
            Console.WriteLine("The Tower of Hanoi consists of three rods and a number of disks of different sizes.");
            Console.Write("Enter the number of disks: ");
            
            numOfDisks = Convert.ToInt32(Console.ReadLine());

            if(numOfDisks > 0)
            {
                TowerOfHanoi(numOfDisks, source, auxiliary, destination);
            }
            else
            {
                Console.WriteLine("The number should be greater than 0");
            }
        }

        public static void TowerOfHanoi(int numDisk, char source, char auxiliary, char destination)
        {

            if (numDisk > 1)
            {
                TowerOfHanoi(numDisk - 1, source, auxiliary, destination);
                Console.WriteLine("Move disk " + numDisk + " from source " + source + " to destination " + destination);
                TowerOfHanoi(numDisk - 1, auxiliary, destination, source);
            }
            else
            {
                Console.WriteLine("Move disk 1 from cource " + source + " to destination " + destination);
            }

        }
    }
}
