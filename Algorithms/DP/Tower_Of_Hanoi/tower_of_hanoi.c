#include <stdio.h>

void hanoi(char from, char helper, char to, int n) {
	//Base case - only one disk to move
	if (n == 1) {
		printf("Move disk 1 from tower %c to tower %c\n", from, to);
		return;
	}

	//When two or more disks must be moved we call the function again
	hanoi(from, to, helper, n - 1);
	printf("Move disk %d from tower %c to tower %c\n", n, from, to);
	hanoi(helper, from, to, n - 1);
}

int main() {
	int n;
	
	//Prompt for user interaction
	printf("Enter the number of disks to play: ");
	scanf_s("%d", &n);

	//Calculate the game moves
	hanoi('A', 'B', 'C', n);

	return 0;
}