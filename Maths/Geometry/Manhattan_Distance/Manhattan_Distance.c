// Nothing Special

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int manhattan_dist(int a1 , int a2 , int b1 , int b2) {
    return (abs(a1 - a2) + abs(b1 - b2));
}

int main() {
	int x1, x2, y1, y2, dist=0;
    printf("Enter points of A: ");
    scanf("%d %d" , &x1 , &x2);
    printf("Enter points of B: ");
    scanf("%d %d" , &x2 , &y2);
    dist = manhattan_dist(x1 , x2 , y1 , y2);
    printf("The Manhattan distance is: %d\n" , dist);
	return 0;
}
