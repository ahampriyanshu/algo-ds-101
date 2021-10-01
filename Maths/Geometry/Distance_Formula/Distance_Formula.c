#include<stdio.h>
#include<math.h>

int main()

{
    
	int x1,x2,y1,y2;
	int x,y;		//temporary variables
	float distance;
	printf("Enter X and Y coordinates of first point: ");
	scanf("%d %d",&x1,&y1);
	printf("Enter X and Y coordinates of Second point: ");
	scanf("%d %d",&x2,&y2);

	x=x2-x1;
	y=y2-y1;
	distance=sqrt((x*x)+(y*y)); 
	printf("Distance: %.2f",distance);
    
	return 0;

}
