#include <iostream.h>
#include <conio.h>

// Function to check whether given sequence is in AP or not 
// The common differences for the sequence is calculated and checked
int is_ap(int ap[],int terms,int common_difference[])
{
    int index=0;
    // Looping through elements to get the common differences between them in given sequence
    while(index<(terms-1))
    {
	// Storing current common difference by substracting prev number from next number
	common_difference[index]=ap[index+1]-ap[index];
	// If the index is not zero and if current commmon difference
	// is not equal to previous common difference then sequence is not in AP
	if ((index!=0) && (common_difference[index] != common_difference[index-1]))
		break;
	index += 1;
    }

    // If loop runs upto index becoming terms-1 then sequence in AP
    // as all common difference are same, hence returning 1
    if(index==(terms-1))
	return 1;
    // otherwise returning -1
    else
	return -1;
}

// Function to calculate sum if number of terms is even
int evensum_ap(int ap[], int terms, int common_difference[])
{
    int sum;
    // Implementing the formula for sum of AP with even no of terms = (n/2)*(2*a +(n-1)*d)
    sum = (terms / 2) * ((2 * ap[0]) + ((terms - 1) * common_difference[0]));
    return sum;
}

// Function to calculate sum if number of terms is odd
int oddsum_ap(int ap[], int terms, int common_difference[])
{
    int sum;
    // Implementing the formula for sum of AP with odd no of terms = n*(a+((n-1)/2)*d)
    sum = terms*(ap[0]+((terms-1)/2)*common_difference[0]);
    return sum;
}


// Driver Code

void main()
{
    clrscr();

    int terms;
    // Taking input for no of terms
    cout<<"Enter the no of terms :"<<endl;
    cin>>terms;
    
    // Initialising the two arrays for sequence and common difference
    int ap[100], common_difference[100];

    // Taking input for terms in sequence
    cout<<"Enter the terms of sequence :"<<endl;
    for(int i=0;i<terms;i++)
	cin>>ap[i];

    // If sequence not in AP, print message for the same
    if(is_ap(ap,terms,common_difference)==-1)
	cout<<"Sequence is not an AP."<<endl;

    // If sequence is in AP
    else
	// If no of terms is even, calculate sum for even no of terms
	if(terms%2==0)
		cout<<"Sum Of AP is : "<<evensum_ap(ap,terms,common_difference);

	// Otherwise calculate sum for odd no of terms
	else
		cout<<"Sum Of AP is : "<<oddsum_ap(ap,terms,common_difference);
    getch();
}


/*
Input description: 
    Line 1 -- No of terms
    Line 2 -- Elements of the sequence (each on a newline)

Output Description :
    Sum of AP is : Sum
	or
    Sequence is not in AP.


Example Outputs:

    Input 1:
	Enter the no of terms :
	4
	Enter the terms of sequence :
	1
	3
	5
	7
    
    Output 1:
	Sum Of AP is : 16
    


    Input 2:
	Enter the no of terms :
	3
	Enter the terms of sequence :
	2
	6
	10
    
    Output 2:
	Sum Of AP is : 18
*/