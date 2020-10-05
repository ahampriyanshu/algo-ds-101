# Problem: We are given n disks and a series of rods, we need to transfer all the disks to the final rod under the given constraints:
  # Constraint 1: We can move only one disk at a time
  # Constraint 2: Only the uppermost disk from the rod can be moved
  # Constraint 3: Any bigger disk cannot be placed on the smaller disk


def TowerOfHanoi(n , FROM_R, TO_R, AUX_R):
   if n == 1:
      print ("Move Disk 1 From Rod",FROM_R,"To Rod",TO_R)
      return
   TowerOfHanoi(n-1, FROM_R, AUX_R, TO_R)
   # Recursion begins here
   print ("Move Disk", n,"from rod",FROM_R,"to rod",TO_R)
   TowerOfHanoi(n-1, AUX_R, TO_R, FROM_R)


# Check input number is whole 
def inputNumber(message):
  while True:
    try:
       userInput = int(input(message))       
    except ValueError:
       print("Not an integer or whole number! Try again.")
       continue
    else:
       return userInput


# Provide the input N = Number of disks 
n = inputNumber("Please Enter The Number Of Disks For This Game:")
print(f"The Number Of Disks Chosen Is: {n}")
# A, C, B are the names of the rods
TowerOfHanoi(n, 'A', 'C', 'B')
print(f"The Total Number Of Moves To Shift The Stack Of {n} Disks Is: {((2**n)-1)}")



