#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  //make a prioity_queue
  p_queue<int> pq;

  //insert element element in p_queue
  pq.push(12);

  //find the size of q_queue
  cout << pq.size();

  //check if p_queue is empty
  pq.empty();

  //remove element from p-queue
  pq.pop();

  //print top most element.
  cout << pq.top();


  /*
    This is by-default max- prioity_queue, to make min-queue, simple multiply -1 to all the elements
    or use

    p_queue<int,vector<int>, greater<int>> pq;
  */
  return 0;
}
