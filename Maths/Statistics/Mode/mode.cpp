// Program to find the mode, i.e., the number which appears most often in a set of numbers


#include<bits/stdc++.h>
using namespace std;

void mode(int [], int);

int main()
{
    int a[1000], n, i;
    cout << "Enter no. of elements: ";
    cin >> n;

    cout << "Enter data: ";
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }

    mode(a, n);

    return 0;
}

void mode(int arr[], int num)
{
    int i, k, flag=0, mode=0;

    for(i=0; i<num; i++)
    {
        int count=0;

        for (k=0; k<i; k++)
        {
            if(arr[k] == arr[i]) {
                count++;
            }
        }

        if(count > flag) {
            flag = count;
            mode = arr[i];
        }
    }

    cout << "Mode is: " << mode << endl;
}