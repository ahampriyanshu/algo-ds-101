import java.util.*;

/*
ArrayDeque abstract data structure :- 
An ArrayDeque (also known as an "Array Double Ended Queue", pronounced as "ArrayDeck") is a special kind of a growable array that allows us to add or remove an element from both sides.

The ArrayDeque data structure is implemented in java collections framework through the ArrayDeque interface
We can also say that ArrayDeque is a collections framework API that realizes the ArrayDeque abstract data structure
*/

public class ArrayDequeDemo
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        // Creating an ArrayDeque of integers
        ArrayDeque<Integer> ArrDq = new ArrayDeque<Integer>();
        // We can also create an ArrayDeque of other data types like Character or String etc.

        System.out.println("Instruction Format : command_ name element_value");
        System.out.println("1. Add an element to the front or left end of ArrayDeque : command-> \"addFirst value\". Example \"addFirst 20\" will add 20 to the front of ArrayDeque");
        System.out.println("2. Add an element to the end or right end of ArrayDeque : command-> \"addLast value\" .Example \"addLast 50\" will add 50 to the rear end of ArrayDeque");
        System.out.println("3. Remove the element at the front or left end of ArrayDeque : command-> \"removeFirst\"");
        System.out.println("4. Remove the element at the rear end or right end of ArrayDeque : command-> \"removeLast\"");
        System.out.println("5. Show the present size of the ArrayDeque : command-> \"size\"");
        System.out.println("6. Check if the ArrayDeque is empty : command-> \"isEmpty\"");
        System.out.println("7. Exit the program: command-> \"Exit\"");
        // Note that the method names are same the commands to do a specific operation on ArrayDeque

        while(true)
        {
            String[] command = in.nextLine().split(" ");
            boolean got_value = false;
            try
            {
                String command_name = command[0];
                int value = 0;
                int output = 0;
                if (command.length > 1)
                {
                    value = Integer.parseInt(command[1]);
                    got_value = true;
                }
                switch(command_name)
                {
                    case "addFirst" : 
                        // addFirst method adds an element to the front (left) end of the ArrayDeque
                        if (got_value)
                            ArrDq.addFirst(value);
                        else
                            throw new NumberFormatException();
                        break;
                    case "addLast" : 
                        // addLast method adds an element to the rear (right) end of the ArrayDeque
                        if (got_value)
                            ArrDq.addLast(value);
                        else
                            throw new NumberFormatException();
                        break;
                    case "removeFirst" :     
                        // removeFirst method removes and returns an element from the front (left) end of the ArrayDeque
                        output = ArrDq.removeFirst();
                        System.out.println("Removed " + output + " from the front of the ArrayDeque");
                        break;
                    case "removeLast" : 
                        // removeLast method removes and return an element from the rear (right) end of the ArrayDeque
                        output = ArrDq.removeLast();
                        System.out.println("Removed " + output + " from the end of the ArrayDeque");
                        break;
                    case "size" : 
                        // size method returns the present size of ArrayDeque
                        output = ArrDq.size();
                        System.out.println("Size of the ArrayDeque is : " + output);
                        break;
                    case "isEmpty" :
                        // isEmpty method returns a boolean true if the ArrayDeque is empty else it return false
                        Boolean empty = ArrDq.isEmpty();
                        if (empty)
                            System.out.println("Array deque is Empty");
                        else
                            System.out.println("Array deque is not Empty");
                        break;
                    case "Exit":
                        in.close();
                        return;
                    default :
                        System.out.println("Please enter a valid command");
                }
                System.out.println("ArrayDeque : ");
                System.out.println(ArrDq); 
            }
            catch(NumberFormatException e)
            {
                System.out.println("Please enter a valid number");
            }
            catch(Exception e)
            {
                System.out.println("Exception :" + e.getMessage());
            }
        }
    }
}
