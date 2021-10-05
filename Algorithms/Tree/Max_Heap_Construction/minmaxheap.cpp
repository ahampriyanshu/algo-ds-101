#include <iostream>

using namespace std;

void min_heapify(int *heap,int i,int n)
{
    int j, temp;
    temp = heap[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && heap[j+1] < heap[j])
            j = j + 1;
        if (temp < heap[j])
            break;
        else if (temp >= heap[j])
        {
            heap[j/2] = heap[j];
            j = 2 * j;
        }
    }
    heap [j/2] = temp;
    return;
}
void build_minheap(int *heap, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        min_heapify(heap,i,n);
    }
}
void max_heapify(int *heap, int i, int n)
{
    int j, temp;
    temp = heap[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && heap[j+1] > heap[j])
            j = j + 1;
        if (temp > heap[j])
            break;
        else if (temp <= heap[j])
        {
            heap[j / 2] = heap[j];
            j = 2 * j;
        }
    }
    heap[j/2] = temp;
    return;
}
void build_maxheap(int *heap,int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(heap,i,n);
    }
}

int main()
{
    int n, i, ch;
    cout<<"\n ENTER THE SIZE OF HEAP :";
    cin>>n;
    int heap[20];
    cout<<"\n ENTER THE ELEMENTS : ";
    for (i = 1; i <= n; i++)
    {
          cin>>heap[i];
    }
    do
    {
    cout<<"\n\n\t\t  OPERATIONS MENU\n\t\t1.Min Heap\n\t\t2.Max Heap\n\t\t3.Exit ";
    cout<<"\n ENTER YOUR CHOICE :";
    cin>>ch;
    switch(ch)
    {
        case 1:
          {
            build_minheap(heap, n);
            cout<<"Min Heap\n";
            for (i = 1; i <= n; i++)
            {
                cout<<heap[i]<<endl;
            }
            break;
          }
        case 2:
            {
                build_maxheap(heap,n);
                cout<<"Max Heap\n";
                for (i = 1; i <= n; i++)
                {
                    cout<<heap[i]<<endl;
                }
                break;
            }
        case 3:
            {
                exit(0);
            }
    }
 }while(ch!=3);
}
