#include <iostream>
#include <string>

using namespace std;

int main()
{
  unsigned short year, a, b;

  cout << "\nFor which year do you want to know Easter date?\n> ";
  cin >> year;

  a = (19 * (year % 19) + 15) % 30;
  b = (2 * (year % 4) + 4 * (year % 7) + 6 * a + 6) % 7;

cout << "Easter date in " << year << " is "
  << ((a + b > 26) ?
    ("May " + to_string(a + b - 26)) :
    ("April " + to_string(4 + a + b)))
  << endl;

return 0;
}
