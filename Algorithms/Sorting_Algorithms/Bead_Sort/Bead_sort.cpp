#include <bits/stdc++.h>
using namespace std;
void beadSort(int *a, int len)
{
    int max = a[0];
    for (int i = 1; i < len; i++)
        if (a[i] > max)
           max = a[i];

    char beads[max*len];
    memset(beads, 0, sizeof(beads));
    for (int i = 0; i < len; i++)
        for (int j = 0; j < a[i]; j++)
            beads[i*max +j] = 1;

    for (int j = 0; j < max; j++)
    {
        int sum = 0;
        for (int i=0; i < len; i++)
        {
            sum += beads[i*max +j];
            beads[i*max +j] = 0;
        }

        for (int i = len - sum; i < len; i++)
            beads[i*max +j] = 1;
    }

    for (int i = 0; i < len; i++)
    {
        int j;
        for (j = 0; j < max && beads[i*max +j]; j++);
        a[i] = j;
    }
}
int main()
{
    int n;
    cout<<"enter the no of element in array :";
    cin>>n;
    cout<<"enter the elements: ";
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    beadSort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
