#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
  
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 

#define ALPHABET_SIZE (26) 
 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    bool isEndOfWord; 
}; 
  
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode = NULL; 
  
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode)); 
  
    if (pNode) 
    { 
        int i; 
  
        pNode->isEndOfWord = false; 
  
        for (i = 0; i < ALPHABET_SIZE; i++) 
            pNode->children[i] = NULL; 
    } 
  
    return pNode; 
} 
  
void insert(struct TrieNode *root, const char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
  
    struct TrieNode *pCrawl = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]); 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  

    pCrawl->isEndOfWord = true; 
} 
  

bool search(struct TrieNode *root, const char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
    struct TrieNode *pCrawl = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]); 
  
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  
int main() 
{ 
    char keys[][8] = {"the", "a", "there", "answer", "any", 
                     "by", "bye", "their"}; 
  
    char output[][32] = {"Not present in trie", "Present in trie"}; 
  
  
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    int i; 
    for (i = 0; i < ARRAY_SIZE(keys); i++) 
        insert(root, keys[i]); 
  
    printf("%s --- %s\n", "the", output[search(root, "the")] ); 
    printf("%s --- %s\n", "these", output[search(root, "these")] ); 
    printf("%s --- %s\n", "their", output[search(root, "their")] ); 
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] ); 
  
    return 0; 
} 
