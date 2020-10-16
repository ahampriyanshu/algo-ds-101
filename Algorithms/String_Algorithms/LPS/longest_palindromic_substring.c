#include <stdio.h> 
#include <string.h> 
void print(char* str, int low, int high) 
{ 
    for (int i = low; i <= high; ++i) 
        printf("%c", str[i]); 
} 
  

void longestSubstr(char* str) 
{ 
    int maxLength = 1; 
    int start = 0; 
    int len = strlen(str); 
    int low, high;
    for (int i = 1; i < len; ++i) { 
        low = i - 1; 
        high = i; 
        while (low >= 0 && high < len 
               && str[low] == str[high]) { 
            if (high - low + 1 > maxLength) { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
        low = i - 1; 
        high = i + 1; 
        while (low >= 0 && high < len 
               && str[low] == str[high]) { 
            if (high - low + 1 > maxLength) { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
    } 
    printf("Longest palindrome substring is: "); 
    print(str, start, start + maxLength - 1); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    char s[1000], i;
    int n;
    printf("enter the length of string \n");
    scanf("%d", &n);
    printf("Please enter your string \n");
    for(i = 0; i < n; i++){
        scanf("%c", &s[i]);
    }
    longestSubstr(s); 
    return 0; 
} 