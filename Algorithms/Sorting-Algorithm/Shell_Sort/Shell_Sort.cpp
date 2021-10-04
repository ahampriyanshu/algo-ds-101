// The Shell Sort Algorithm in C++

using namespace std;
#include <iostream> 

// Shell Sort Algorithm in a Function
void ShellSort(int sortArray[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = sortArray[i];
            int j;
            for (j = i; j >= gap && sortArray[j - gap] > temp; j -= gap)
            {
                sortArray[j] = sortArray[j - gap];
            }
            sortArray[j] = temp;
        }        
    }        
}


int main() {
    cout << "\n";
    // Requesting Array Size to the User
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Requesting Array Elements to the User
    int sortArray[size];
    cout << "Enter the array elements: \n";    
    for (int i = 0; i < size; i++)
    {
        cin >> sortArray[i];
    }

    cout << "\n";

    // OUTPUT Array before Shell Sort
    cout << "Array BEFORE the Shell Sort: ";
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << sortArray[i] << ", ";
    }
    cout << "\b\b";
    cout << "]";

    cout << "\n\n";

    // Applying the Shell Sort Algorithm
    cout << "Applying the Shell Sort Algorithm...\n";
    ShellSort(sortArray, size);

    cout << "\n";

    // OUTPUT Array after Shell Sort
    cout << "Array AFTER the Shell Sort: ";
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << sortArray[i] << ", ";
    }
    cout << "\b\b";
    cout << "]";
    cout << endl;

    cout << "\n\n";

    return 0;    
}