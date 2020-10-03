#include <iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order)
from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order)
from the unsorted subarray is picked and moved to the sorted subarray.
*/

/*
	Begin to iterate through the array from index 0 to n - 1, iterator = i
	find the smallest element in this range, let the index of element be min_ind
	swap elements at indices i, and min_ind
	continue
*/

void selection_sort(int *arr, int n) {
	int i, j, min_ind = 0, ind = 0;
	for (i = 0; i < n; i++) {
		min_ind = arr[i];
		ind = i;
		for (j = i + 1; j < n; j++) {
			if (min_ind > arr[j]) {
				min_ind = arr[j];
				ind = j;
			}
		}
		int temp = arr[i];
		arr[i] = min_ind;
		arr[ind] = temp;
	}
}

void input(int *arr, int n) {
	cout << "Elements: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void display(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main()
{
	int *arr, n;
	cout << "Number of elements: " << endl;
	cin >> n;

	arr = new int[n];

	input(arr, n);

	auto start = high_resolution_clock::now();
	selection_sort(arr, n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout <<"\nRunning time of selection sort is: " << duration.count() <<" microseconds" << endl;

	cout << "\nSorted array is: " << endl;
	display(arr, n);

	cout << "Press any key to exit. ";
	cin.get();
	cin.ignore();
}