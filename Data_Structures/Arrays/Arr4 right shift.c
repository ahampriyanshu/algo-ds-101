

#include<stdio.h>

#define MAX 5 

void AcceptArray(int *Arr1 , int n)
{
	int cnt ;
	int x ;
	int *ptr = Arr1 ;
	printf("Accept an array");
	for(cnt=0;cnt<n ; cnt++)
	{
		printf("enter the %d element \n ",cnt);
		scanf("%d",&x);
		printf("ptr is at %x \n",ptr);
		*ptr=x;
		ptr++;	
	}
	*ptr=-1;
	
}
void DisplayArray(int *Arr1[],int n )
{
	int cnt ;int x;
	int *ptr=Arr1;
	
	for(cnt=n-1; cnt>0 ; cnt--)
	{
		printf("cnt=%d ptr =%x ptr -1 %x \n ",cnt ,ptr ,(ptr-1));
		x=*(ptr-1);
		*ptr=x;
	//	printf("%d",*ptr);
		ptr--;		
	}
	*ptr=-1;

	
}
void main(void)
{
	int Arr[MAX];
	int cnt ;
	int x ;
	
	printf("in main %x ",&Arr[0]);
	printf("\n enter your array \n");
	AcceptArray(Arr,MAX);
	printf("\n you have entered \n ");
	DisplayArray(Arr,MAX );
	
	
	
}

