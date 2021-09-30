#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int computeMinHours(vector<int> &piles, int speed)
{
    int n = piles.size();
    int res = 0;
    int i = 0;
    for (i = 0; i < n; i++)
        res += ceil((float)piles[i] / speed);
    return res;
}
int computeMax(vector<int> &piles)
{
    int n = piles.size();
    int maxval = INT_MIN;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, piles[i]);
    return maxval;
}
int minEatingSpeed(vector<int> &piles, int H)
{
    int n = piles.size();
    if (n == 1)
    {
        double b = (double)piles[0];
        int temp = ceil(b / H);
        return temp;
    }
    int lo = 1;
    int hi = computeMax(piles);
    int mid;
    int intval;
    while (lo < hi)
    {
        mid = lo + (hi - lo) / 2;
        intval = computeMinHours(piles, mid);
        if (intval <= H)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return lo;
}

int main()
{
    vector<int> piles;
    int H;
    cout << "Enter contents of each pile (enter any negative number to stop)\n";
    while (true)
    {
        int x;
        cout << "Enter content of pile: ";
        cin >> x;
        if (x < 0)
            break;
        piles.push_back(x);
    }
    cout << "Enter number of hours for guards to return \n";
    cin >> H;
    int res = minEatingSpeed(piles, H);
    cout << "The minimum eating speed should be " << res << " bananas per hour";
    return 0;
}