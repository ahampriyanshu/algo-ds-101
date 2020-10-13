using namespace std;

long fac(long i)
{
if (i==0)
{
return (1);
}
else
{return (i*fac(i-1));}
}
int main()
{
int z;
cout<<“enter number”;
cin>>z;
cout<<z<<"!="<< fac (z);
