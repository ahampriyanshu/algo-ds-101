#include <bits/stdc++.h> 
using namespace std;
         
//function is for constructing pi array , pre processing pattern 
//to know the maximum suffix length that is equal to prefix
void calculate_lps(string str, vector<int>&pi){
    pi[0] = 0;                   
    int len = 0,i=1;
    
    while (i<str.length()){
        if(str[i]==str[len]){   
            len++;
            pi[i] = len;
            i++;
            continue;
        }
        else{                   
            if(len==0){         
                pi[i] = 0;
                i++;
                continue;
            }
            else{              
                len = pi[len-1];
                continue;
            }
        }
    }
}


void KMP(string pattern,string text){
  
    int m = pattern.length();
    int n = text.length();
    
    vector<int>pi(m);
    
    calculate_lps(pattern,pi); 
    
    int i=0,j=0;
    while(i<n){
        if(pattern[j]==text[i])
        {i++;
         j++;}

        if (j == m) { 
            cout<<"pattern found at index: "<<i - m <<"\n";   // the pattern found
            j = pi[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i]) {  
            if (j == 0)        
                i++;
            else
                j = pi[j - 1]; 
        }
    }
}

int main()
{
    string text = "afafaksncnndnn";
    string pattern = "ksn";
    KMP(pattern, text);
    
    return 0; 
}
