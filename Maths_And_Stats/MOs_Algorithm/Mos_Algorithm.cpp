// Mos Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// User: kcirym10
// Mos Algorithm is widely used for decreasing complexity in query base problems

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//This variable represents the block size and is global in order to be used insede of the compare function
int block;

//Structure that represents a query range
struct Query {
    int L, R;
};

bool compare(Query x, Query y) {
    if (x.L / block != y.L / block)
        return x.L / block < y.L / block;

    return x.R < y.R;
}

void queryResults(vector<int> a, const int n, vector<Query> q, const int m) {
    //Set the block size
    block = (int)sqrt(n);

    //Sort all queries using the compare function so that
    //all queries belonging to the same block are grouped together
    sort(q.begin(), q.end(), compare);

    //Initialize the current L, current R and the current sum
    int currentL = 0, currentR = 0, currentSum = 0;

    for (int i = 0; i < m; i++) {
        //Get the L and R values of the current range
        int L = q[i].L, R = q[i].R;

        //Remove the extra elements of the previous range
        while (currentL < L) {
            currentSum -= a[currentL];
            currentL++;
        }

        //Add elements from the current range
        while (currentL > L) {
            currentSum += a[currentL - 1];
            currentL--;
        }

        while (currentR <= R) {
            currentSum += a[currentR];
            currentR++;
        }

        //Remove the elements from the previous range
        while (currentR > R + 1) {
            currentSum -= a[currentR - 1];
            currentR--;
        }

        // Print sum of current range 
        cout << "Sum of [" << L << ", " << R
            << "] is " << currentSum << endl;
    }
}

int main()
{
    //Default values in order to run the code but a vector can be implemented in order to 
    /*int a[] = { 1, 1, 2, 1, 3, 4, 5, 2, 8 };
    int n = sizeof(a) / sizeof(a[0]);
    Query q[] = { {0, 4}, {1, 3}, {2, 4} };
    int m = sizeof(q) / sizeof(q[0]);*/
    vector<int> a;
    vector<Query> q;
    int n;
    int m;
    Query temp;
    int iTemp;


    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter all n elements\n";
    for (int i = 0; i < n; i++) {
        cin >> iTemp;
        a.push_back(iTemp);
    }

    cout << "Enter the number of query calls: ";
    cin >> m;
    
    cout << "Enter the pair of query calls\n";
    for (int i = 0; i < m; i++) {
        cin >> temp.L;
        cin >> temp.R;
        q.push_back(temp);
    }
    
    queryResults(a, n, q, m);
    
    return 0;
}
