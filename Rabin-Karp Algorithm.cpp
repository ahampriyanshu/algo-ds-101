#include <iostream>

using namespace std;

void print(string s1,int start,int m){
    string ans="";
    for(int i=start;i<(start+m);i++){
        ans+=s1[i];
    }
    cout<<ans<<'\n';
}

void RabinKarp(string s1,string s2){
    int d=256;
    int q=101;
    int h=1;
    int n=s1.size(),m=s2.size();
    //to calculate pow(d,m-1)
    for(int i=1;i<m;i++){
        h=(h*d)%q;
    }
    int hashPat=0,hashTxt=0;
    for(int i=0;i<m;i++){
        hashPat=(hashPat*d+s2[i])%q;
        hashTxt=(hashTxt*d+s1[i])%q;
    }
    for(int i=0;i<=n-m;i++){
        if(hashPat==hashTxt){
            int x=0;
            for(int j=0;j<m;j++){
                if(s2[j]!=s1[i+j]){
                    x==1;
                    break;
                }
            }
            if(x==0){
                print(s1,i,m);
            }
        }
        if(i<n-m){
            hashTxt=((hashTxt-s1[i]*h)*d+s1[i+m])%q;
            if(hashTxt<0){
                hashTxt+=q;
            }
        }
    }
}


int main()
{
    string txt = "AABAACAADAABAABA";string pat="AABA";
    RabinKarp(txt,pat);
    return 0;
}
