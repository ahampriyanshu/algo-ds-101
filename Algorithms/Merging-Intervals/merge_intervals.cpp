#include<bits/stdc++.h>
using namespace std;
 
// An interval has start time and end time
struct Interval
{
    int start, end;
};
 
// To compare two intervals accoridng to their start time
bool myComp(Interval interval1, Interval interval2)
{
    return (interval1.start < interval2.start);
}
 
// This function takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(Interval arr[], int n)
{
    // Test if the given set has at least one interval
    if (n <= 0)
        return;
 
    // Create an empty stack of intervals
    stack<Interval> s;
 
    // sorting the intervals in increasing order of start time
    sort(arr, arr+n, myComp);
 
    // push the first interval to stack
    s.push(arr[0]);
 
    // Start from the next interval and merge if necessary
    for (int i = 1 ; i < n; i++)
    {
        // get interval from stack top
        Interval top = s.top();
 
        // if current interval is not overlapping with stack top,
        // push it to the stack
        if (top.end < arr[i].start)
            s.push(arr[i]);
 
        // Otherwise update the ending time of top if ending of current
        // interval is more
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
 
    // Print contents of stack
    cout << "\n After merging Intervals are: ";
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return;
}
int main()
{
  Interval arr[]= {{1,6},{3,9},{11,13},{2,5}};  //creating an array
    int n = sizeof(arr)/sizeof(arr[0]); //size of the array
    mergeIntervals(arr,n);
    return 0;
}
