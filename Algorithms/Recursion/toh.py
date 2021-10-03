#TOWER OF HANOI USING PYTHON

'''Here, we have used recursive method for the implementation of the game
->The function TowerOfHanoi() takes four parameters
                 Number of discs
                 Source rod
                 Auxiliary rod
                 Destination rod
->It first checks the condition if the number of disc is 1, it directly moves it to the Destination rod and terminates the function
->Then, we have recursively called the function to move the remaining n-1 discs from source node to the auxiliary node, using the destination rod as the auxiliary
->After that, the 1 disk that is remaining is directly moved from the source rod to the auxiliary rod
->Lastly, we have again recursively called the the function to move the remaining n-1 rods from the auxiliary rod to the destination rod, using the source node as auxiliary
'''

def tower_of_hanoi(numbers, start, auxiliary, end):  
    //base case
    if(numbers == 1):  
        print('Move disk 1 from rod {} to rod {}'.format(start, end))  
        return
    tower_of_hanoi(numbers - 1, start, end, auxiliary)  
    print('Move disk {} from rod {} to rod {}'.format(numbers, start, end))  
    tower_of_hanoi(numbers - 1, auxiliary, start, end)  
   
numbers =int(input("Enter number of towers"))
//calling function
tower_of_hanoi(numbers, 'A', 'B', 'C')
