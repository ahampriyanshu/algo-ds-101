#include<stdio.h>
int main(){
int i,a,b,c=0;
printf("To check whether the given two numbers are Amicable numbers or not.\n\n");                  
printf("Enter two numbers : ");
scanf("%d%d",&a,&b);
for(i=0;i<=a/2;i++){
        if(a%i==0)
                c+=i;
}
if(c==b)
      printf("%d and %d are Amicable numbers .\n",a,b);
else
      printf("%d and %d are not Amicable numbers .\n",a,b);

printf("\n\nSome Amicable Numbers under 100,000 are :- \n");
int x,y,m,n,j;
for(i=220;i<100000;i++){
        x=0,y=0;
        for(j=1;j<=i/2;j++){
                if(i%j==0)
                        x+=j;}
        m=1,n=0;
        while(m<=x/2){
                if(x%m==0)
                        y+=m;
                m++;}
if(i==y){
        if(x!=y){
                printf("%d and %d \n",x,y);
        i+=500;}
}}
return 0;
}
