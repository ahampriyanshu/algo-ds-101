#include <bits/stdc++.h>
    using namespace std;

int sub(string s,string output[],string s1[])
{
    if(s.length()==1)
    {
        string s2=s1[s[0]-48];
        for(int i=0;i<s2.length();i++)
        {
            output[i]=s2[i];
        }
        return s2.length();
    }
    string smallstr=s.substr(1);
    int smallsize=sub(smallstr, output,s1);
    string s3=s1[s[0]-48];
    for(int i=0;i<s3.length();i++)
    {
        for(int j=0;j<smallsize;j++)
        {
          output[j+smallsize+i]=output[j];
        }
    }
    int x=s3.length()*smallsize,y=0,z=0;
    for(int i=0;i<x;i++)
    {
        output[i]=s3[z]+output[i];
        y++;
        if(y==smallsize)
        {
            z++;
            y=0;
        }
    }

    return s3.length()*smallsize;
}
int main() {
    string s;
    cin>>s;
    string* output= new string[10000000];
    string s1[10];
    s1[0]=".;";
    s1[1]="abc";
    s1[2]="def";
    s1[3]="ghi";
    s1[4]="jkl";
    s1[5]="mno";
    s1[6]="pqrs";
    s1[7]="tu";
    s1[8]="vwx";
    s1[9]="yz";

    int n=sub(s,output,s1);
    cout<<"[";
    for(int i=0;i<n;i++)
    {
        cout<<output[i];
        if(i!=n-1)
        {
            cout<<",";
        }
    }
    cout<<"]";
}
