//using static members
#include <bits/stdc++.h>
#define LOG(x) cout << x << "\n";
using namespace std;
class OOPS{
public:
  static int count;
};
int OOPS::count = 5;
int main(int argc, char const *argv[]) {

  LOG(OOPS::count);//we don't need to create an object.
  return 0;
}
