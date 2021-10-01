#include <iostream>
using namespace std;
int A(int, int);
int main()
{
        int m=NULL, n=0, count=0;
		
		while(count<=7)
		{
			cout<<A(m,n);
			
			count++;	
		};
        return 0;
}
int A(int m,int n)
{	if(n==1 && m==0)
	{
		m+=1;
	}
    if (m==0)
	{
	  cout<<"A("<<m<<","<<n<<")";
      return n+1;
	}
    else if (n==0)
	{
		cout<<"A("<<m<<","<<n<<")";
       return A(m-1,1);
	}
	else
	{
		cout<<"A("<<m<<","<<n<<")";
       return A(m-1, A(m,n-1));
	}
}
