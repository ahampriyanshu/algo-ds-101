#include<bits/stdc++.h>
using namespace std;

int main(){
 
    
    deque<int>q;

    //q={}
    q.push_back(1); // inserts an element at back

    //q={1}

    q.push_front(2); //inserts an element at front
    //q={2,1}

   cout<< q.at(1)<<'\n'; //prints elemant at position 1 {1}

    cout<<q.size()<<'\n'; //prints no of elements in the deque = 2

    q.resize(4); //resizes the deque to contain 4 elements {1,2,0,0}

    
    cout<<q.front()<<'\n'; //prints element at front {2}

    cout<<q.back()<<'\n'; // prints last element {0}

    q.pop_back();
    // q={2,1,0}

    q.pop_front();
    //q={1,0}
    
   
}
