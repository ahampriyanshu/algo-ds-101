#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void merge(int *a, int size, int low, int high, int mid)
{
	int i, j, k;
	int *c = new int[size];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)
	{
		a[i] = c[i];
	}
}

void mergeSortIterative(int* arr, int size, int low, int high)
{
	int mid;

	for (int i = 2; i <= size; i *= 2) {
		for (int x = 0; x < size; x += i)
		{
			int newHigh;
			if (x + i - 1 < size - 1)
			{
				newHigh = x + i - 1;
			}
			else
			{
				newHigh = size - 1;
			}
			mid = (newHigh - low) / 2;

			merge(arr, size, x, newHigh, mid);
		}
	}
	return ;
}

int main()
{
	std::ifstream inFile;
	std::string inFileName;
	int count = 0;
	int *myIterative;
	int index;
	int nums = 0;

	// Get filename from user
	std::cout << "Enter the input filename: " << std::endl;
	std::cin >> inFileName;

	// Open input file
	inFile.open(inFileName.c_str(), std::ios::app);

	// process input file
	while (!inFile)
	{
		// the file could not be found and opened
		//display error message
		std::cout << "Could not access file" << std::endl;
		std::cin >> inFileName;
	}

	while (inFile >> index) {
		count++;
	}
	myIterative = new int[count];

	inFile.clear();
	inFile.seekg(0, inFile.beg);

	while (inFile >> index) {
		myIterative[nums] = index;
		nums++;
	}


	for (int x = 0; x < nums; x++) {
		std::cout << "Given integers Iterative: " << myIterative[x] << std::endl;
		std::cout << x << std::endl;
	}

	mergeSortIterative(myIterative, nums, 0, nums - 1);
	for (int x = 0; x < nums; x++) {
		std::cout << "Sorted Iterative Array: " << myIterative[x] << std::endl;
		std::cout << x << std::endl;
	}

return 0;
}
