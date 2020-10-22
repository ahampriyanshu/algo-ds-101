#include<stdio.h>
int main()
{
int numberArray[10],lowerBound,upperBound,ci,ri,lci,rci,swap,g,y;
lowerBound=0;
upperBound=9;
y=lowerBound;
while(y<=upperBound)
{
printf("Enter the number:");
scanf("%d",&numberArray[y]);
fflush(stdin);
y++;
}
//create min heap
y=lowerBound+1;
while(y<=upperBound)
{
ci=y;
while(ci>lowerBound)
{
ri=(ci-1)/2;
if(numberArray[ri]>numberArray[ci])
{
g=numberArray[ci];
numberArray[ci]=numberArray[ri];
numberArray[ri]=g;
ci=ri;
}
else break;
}
y++;
}
//adjust min heap
while(upperBound>lowerBound)
{
g=numberArray[upperBound];
numberArray[upperBound]=numberArray[lowerBound];
numberArray[lowerBound]=g;
upperBound--;
ri=lowerBound;
while(ri<upperBound)
{
lci=(ri*2)+1;
rci=lci+1;
if(lci>upperBound)break;
if(rci>upperBound)swap=lci;
else
{
if(numberArray[lci]<numberArray[rci])swap=lci;
else swap=rci;
}
if(numberArray[swap]<numberArray[ri])
{
g=numberArray[swap];
numberArray[swap]=numberArray[ri];
numberArray[ri]=g;
ri=swap;
}
else break;
}
}
upperBound=9;
y=lowerBound;
while(y<=upperBound)
{
printf("%d\n",numberArray[y]);
y++;
}
return 0;
}