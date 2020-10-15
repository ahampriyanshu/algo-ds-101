#include<iostream>
using namespace std;
int main(){                                                                                                          
int i,a,b,c=0;
cout<<"To check for the entered pair of numbers are Amicable Numbers or not.\n"<<endl;
cout<<"Enter any two Numbers : ";
cin>>a>>b;

for(i=1;i<=a/2;i++)
{
        if(a%i==0)
                c+=i;                                        
}
if(c==b)                                                                                                                      
        cout<<a<<" and "<<b<<" are Amicable Numbers."<<endl;
else
        cout<<a<<" and "<<b<<" are Not Amicable Numbers."<<endl;

cout<<"\n\nSome Amicable Numbers under 100,000 are :-"<<endl;
int x,y,j,m,n;
for(i=220;i<100000;i++){
        x=0,y=0;
        for(j=1;j<=i/2;j++){
                if(i%j==0){
                       x+=j;
                       //cout<<j<<endl;
                       }}
        m=1,n=0;
        while(m<=x/2){
                if(x%m==0)
                y+=m;
        m++;
        }
        if(i==y){
                if(x!=y){
                       cout<<x<<" and "<<y<<endl;
                       i+=800;    //to save time
        }}}
return 0;
}
