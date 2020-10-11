#include <bits/stdc++.h> 
using namespace std;
// Function for returning maximum of 2 numbers
int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
}

// Function to obtain minimum number of trials required for finding the highest floor from which the egg can be dropped without breaking
int EggDrop(int n, int k) 
{ 
	// DP table to keep track of minimum number of trials for i eggs and j floors
	int eggFloor[n + 1][k + 1]; 
	int res; 

	for (int i = 1; i <= n; i++) { 
        // If there are no floors, then 0 trials are required.
        eggFloor[i][0] = 0; 
        // If there is only 1 floor, then 1 trial is required.
		eggFloor[i][1] = 1;
	} 

	// If there is only 1 egg, we have to drop it from each floor to check.
    // Hence for j floors, j trials are required
	for (int j = 1; j <= k; j++){
        eggFloor[1][j] = j; 
    }

	// For the rest of the floors from 2nd to nth
	for (int i = 2; i <= n; i++) { 
		for (int j = 2; j <= k; j++) { 
            // Consider the maximum possible trials initially
			eggFloor[i][j] = INT_MAX; 
            // For jth floor, we consider all the trials from 1st floor to jth floor
			for (int x = 1; x <= j; x++) { 
                // For each floor, we consider both cases:
                // a) when the egg breaks: Number of eggs reduce by 1, and we know the critical floor is below xth floor -> eggFloor[i-1][x-1]
                // b) when the egg doesn't break: Number of eggs remain same, and we know the critical is above xth floor -> eggFloor[i][j-x]
                // For considering the worst case scenario, the maximum of both cases is taken
				res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]); 
                // If the obtained result is better (smaller) than previous result for some other x, the previous result is replaced with the better result
				if (res < eggFloor[i][j]) 
					eggFloor[i][j] = res; 
			} 
		} 
	} 

	// The result is available is eggFloor[n][k] after all the possible cases have been considered
	return eggFloor[n][k]; 
} 

int main() 
{ 
    // Initialise variables for number of eggs and number of floors
    // n = number of eggs, k = number of floors
	int n, k;
    cin >> n >> k;
	cout << "Minimum number of trials required: " << EggDrop(n,k) << endl;
	return 0; 
} 