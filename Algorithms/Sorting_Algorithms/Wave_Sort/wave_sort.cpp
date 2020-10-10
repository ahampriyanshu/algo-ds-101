using namespace std;
#include <iostream>

//UTILITY FUNCS

void printArray(int arr[], int size)
{

    cout << "The array = [ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    return;
}

//UTILITY FUNCS==============

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}

// SORT==========================

void waveSort(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {

        if (i >= 1)
        {
            if (arr[i - 1] >= arr[i])
            {
                swap(&arr[i - 1], &arr[i]);
            }
        }

        if (i <= size - 1)
        {
            if (arr[i] < arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
            }
        }
    }
    return;
}

//MAIN FUNCTION=====================

int main()
{

    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements of array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Before sort: ";
    printArray(arr, size);

    waveSort(arr, size);

    cout << "After sort: ";
    printArray(arr, size);

    return 0;
}