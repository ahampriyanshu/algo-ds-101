#include <bits/stdc++.h>
using namespace std;

int Peak_finder(int arr[], int n)
{
    if (n == 1)
        //Only one element in the array
        return arr[0];

    if (arr[0] >= arr[1])
        //Decreasing order
        return 0;

    if (arr[n - 1] >= arr[n - 2])
        //Increasing Order
        return n - 1;

    for (int i = 1; i < n - 1; i++)
    {

        // checking neighbours of the element
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }
}

int main()
{
    int arr[100], n;
    cout << "How many elements do you want to enter? ";
    cin >> n;
    cout << "\nEnter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Index of a peak point is " << Peak_finder(arr, n);
    return 0;
}