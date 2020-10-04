#include<iostream>
using namespace std;
int main()
{
    long d,n,a;
    long an;
    cout<<"Enter first term : ";
    cin>>a;
    cout<<"Enter difference : ";
    cin>>d;
    cout<<"Enter number of terms :";
    cin>>n;
    cout<<"Harmonic progression : ";
    for(int y=1;y<=n;y++)
    {
        an=a+(y-1)*d;
        cout<<"1/"<<an<<"   ";
    }
    return 0;
}