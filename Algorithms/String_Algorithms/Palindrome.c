/** 
 * @author  Ytalo Ramon
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define STRINGSIZE 11

int is_palindrome(char *word);

int main(int argc, char const *argv[]){
    
    char inputs[STRINGSIZE][STRINGSIZE] = {
        "ana",
        "carl",
        "anaa",
        "level",
        "levell",
        "a",
        "deified",
        "deiffied",
        "civicc",
        "tesett",
        "vuc"
    };

    for(int i = 0; i < STRINGSIZE; i++)
        printf("\"%s\" is palindrome ? %s\n", inputs[i],
                is_palindrome(inputs[i]) ? "Yes" : "NO");
    
    return 0;
}

int is_palindrome(char *word){
    int i = -1, j = strlen(word);
    while (i < j && word[++i] == word[--j]);
    
    return j <= i;
}