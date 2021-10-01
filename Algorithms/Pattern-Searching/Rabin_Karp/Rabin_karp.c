#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007 // selected prime number

int main(){
    char pattern[10000], text[1000];
    printf("Enter Text:-\n");
    scanf("%[^\n]%*c",text);
    printf("Enter Pattern to be searched :- \n");
    scanf("%[^\n]%*c",pattern);

    int l1 = strlen(pattern), l2 = strlen(text);
    long long hp = 0, ht = 0, val = 1;

    long long random = rand()%(MOD-1) + 1; // generating random value x

    for(int i=0; i<l1 ;i++){
        hp = (random*hp)%MOD; // calculating hash of pattern
        ht = (random*ht)%MOD; // calculating hash of first sub-string
                              // of text
        hp += pattern[i];
        ht += text[i];

        hp %= MOD;
        ht %= MOD;
        val = (val*random)%MOD;
    }
    
    for(int i = 0; l2-l1-i >= 0 ;i++){
        if(i != 0){
            long long new_ht = (random*ht-val*text[i-1]+text[l1+i-1])%MOD;
            new_ht = (new_ht + MOD)%MOD;
            ht = new_ht;
        }

        if(hp == ht){
            int j;
            
            for (j = 0; j < l1 ; j++){ 
                if (text[i+j] != pattern[j]) 
                    break; 
            }
            
            if(j == l1)
                printf("Pattern found at index :- %d\n",i);//output all indices where pattern was
                                                           //found in text
        }
    }

    return 0;
}