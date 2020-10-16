#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Taking inputs using array template from C++ STL..
    array<int, 10> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    array<int, 10> arr2 = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    cout << "Before Swap :" << endl;
    cout << "Elements in the first array : ";
    for (int i = 0; i < 10; i++)
        cout << arr1.at(i) << " "; // This method returns value in the array at the given range.
    cout << "\nElements in the second array : ";
    for (int i = 0; i < 10; i++)
        cout << arr2.at(i) << " ";
    arr1.swap(arr2); // Swapping two arrays..
    cout << "\n\nAfter Swap :" << endl;
    cout << "Elements in the first array : ";
    for (int i = 0; i < 10; i++)
        cout << arr1.at(i) << " ";
    cout << "\nElements in the second array : ";
    for (int i = 0; i < 10; i++)
        cout << arr2.at(i) << " ";
    return 0;
}