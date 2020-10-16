
//C++ program to perform Cuckoo Hashing

#include<bits/stdc++.h>
using namespace std;

#define hashTableNum 2 //Number of table hash consist

//Number of element to be hashed
static int tableSize=0;  //Initialized to zero

//Array to store hash value
int cuckooTable[hashTableNum][100];

//Array to store hashed position of element
int Position[hashTableNum];

//Initialize cuckooTable with minimum value of Integer type
void fillTable(){
	
	for (int j=0; j<tableSize; j++){
	
		for(int i=0; i<hashTableNum; i++){
	
			cuckooTable[i][j]= INT_MIN;  //for minimum Integer value
	
		}	
	}

}

//Print the hash table after performing Cuckoo Hashing
void printTable(){

	cout<<"\nHash Tables are:\n"<<endl;
	
	//Print both hash table
	for(int i=0; i<hashTableNum; i++, printf("\n")){
		
		int tableNum=i+1;
		cout<<"Table: " << tableNum << "-> ";

		//Print hash position of various element
		for(int j=0; j<tableSize; j++){
		
			if(cuckooTable[i][j]==INT_MIN){

				cout<<" N ";

			}
		
			else{

				cout<<" "<<cuckooTable[i][j];

			}

		}
	}
	
	cout<<endl;

}

//Evaluates hash position for elements
int getHashValue(int function, int key){
	
	switch(function){
	
		case 1: return key%tableSize; //first hash position
	
		case 2: return (key/tableSize)%tableSize; //second hash position
	
	}

}

//Arrange the position element and perform relocations
void getArrange(int key, int hashTable, int currPosition, int n){

	//If an element has not allocated any position in hash table
	if(currPosition == n){

		cout << key << " do not have a position\n" << endl;
		return;

	}

	//Generate the hash position for the key
	for(int i=0; i < hashTableNum; i++){

		Position[i]= getHashValue(i+1, key);

		if(cuckooTable[i][Position[i]] == key){

			return;

		}
	}

	//If an old key already exist at generated position
	//relocates the old key in another hash table
	if(cuckooTable[hashTable][Position[hashTable]]!=INT_MIN){

		int oldKey = cuckooTable[hashTable][Position[hashTable]];

		cuckooTable[hashTable][Position[hashTable]] = key;

		//Perform relocation of old key
		getArrange(oldKey, (hashTable+1) % hashTableNum, currPosition+1, n);

	}

	else{

		//Allocates new key at generated position
		cuckooTable[hashTable][Position[hashTable]]= key;

	}
}


//Perform Cuckoo Hashing
void cuckooFunction(int keys[], int n){

	fillTable();

	//Perform allocation for every element or key
	for(int i=0, currPosition=0; i<n; i++, currPosition=0){

		getArrange(keys[i], 0, currPosition, n);

	}

	//Displays the final hash table
	printTable();

}


//Driver Code
int main(){

	int n;

	//Number of keys on Cuckoo Hashing is to be performed
	cout<<"Enter number of terms to be inserted:";
	cin>>n;

	tableSize=n;

	int keyTable[n];  //Array to store keys or elements
	cout<<"Enter desired numbers:\n";

	//Initialize each key or elment in array
	for(int i=0; i<n; i++){

		cin>>keyTable[i];

	}

	cuckooFunction(keyTable, n);

	return 0;
}