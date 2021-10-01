#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int i, n, num, sum = 0;
  cout << "Enter The Number" << endl;
  cin >> num;

  for (i = 1; i <= sqrt(num); i++)
  {
    if (num % i == 0)
    {
      if (num / i == 1)
      {
        sum = 0;
      }
      else
      {
        sum = sum + i;
      }
      if (num / i != i && num / i != num)
      {
        sum = sum + (num / i);
      }
    }
  }
  if (sum == num)
  {
    printf("PERFECT NUMBER  \n");
  }
  else
  {
    printf("NOT A PERFECT NUMBER  \n");
  }
  return 0;
}
