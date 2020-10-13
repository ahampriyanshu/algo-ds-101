#include <iostream>
#include <cmath>
using namespace std;

float standardDeviation(float data[])
{
    float sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for(i = 0; i < 10; ++i)
    {
        sum += data[i];
    }

    mean = sum/10;

    for(i = 0; i < 10; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / 10);
};

int main()
{
    int i;
    float data[10];

    cout << "Enter 10 elements: ";
    for(i = 0; i < 10; ++i)
        cin >> data[i];

    cout << endl << "Standard Deviation = " << standardDeviation(data);

    return 0;
}

