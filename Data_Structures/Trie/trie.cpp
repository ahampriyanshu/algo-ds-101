#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	unordered_map<char, TrieNode*> branches;
	bool isEnd;
};

// creates new node and initialises isEnd to false
TrieNode* createNode(void) 
{

	TrieNode* node = new TrieNode;
	node->isEnd = false;

	return node;
}				

void insert(TrieNode*& node, const string &str, int index = 0) 
{
	// inserts a character node to existing trie structure

	if (node == NULL)  // creates a new root if there is none
	{
		node = createNode();
		cout<<"Creating ROOT"<<endl;
	}

	TrieNode* temp = node;

	if (index >= str.length())	// check if we have reached end of the word
	{
		temp->isEnd = true;

		return;
	}
	
	// assigns letter on i'th position of string to key
	char key = str[index];
	if (temp->branches.find(key) == temp->branches.end())
	{
		temp->branches[key] = createNode();
	}

	// recursive definition to insert into trie
	return insert(temp->branches[key], str, index+1);
}

string search(TrieNode* root, const string &str, int index = 0) 
{
	// function which returns word if found else error message

	if (root == NULL) // return not found if no words added
	{
		return "Word not found.";
	}

	TrieNode* temp = root;

	if (index >= str.length()) // return found if end of word encountered
	{
		return "Word found.";
	}

	char key = str[index];
	// recursive definition to iterate through trie
	return search(temp->branches[key], str, index+1);
}

int main() 
{ 
    TrieNode* root = NULL; 

    // Build the dictionary 
    insert(root, "trie"); 
    insert(root, "is");
    insert(root, "an"); 
    insert(root, "efficient");  
    insert(root, "retrieval"); 
    insert(root, "structure");
  
  	// search for "book" in our trie
    string str; 
    cout<<"Enter Word to search:";
    cin>>str;
    cout << search(root, str); 
  
    return 0; 
} 
