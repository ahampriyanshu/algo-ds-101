#include<bits/stdc++.h>
using namespace std ;

int main()
{
    // declaring unordered_set for storing int type values
    unordered_set<int> s ;

    // for inserting an element

    s.insert(1) ; 
    s.insert(2) ;
    s.insert(3) ;
    s.insert(4) ;

    // count of an element
    // count will be either 1 (the element is in the set) or 0 (the element is not in the set)
    // because set/unordered_set only contain distinct elements
    cout << s.count(1) << endl  ;  //  1
    cout << s.count(2) << endl  ;  //  1
    cout << s.count(5) << endl  ;  //  0
    cout << s.count(6) << endl  ;  //  0

    // for erasing an element
    s.erase(1) ;
    cout << s.count(1) << endl  ;  //  0
    s.erase(2) ;
    cout << s.count(2) << endl  ;  //  0

    // insert never adds an element if it is already there
    cout << s.count(1) << endl  ;  //  0
    s.insert(1) ;
    cout << s.count(1) << endl  ;  //  1
    s.insert(1) ;
    cout << s.count(1) << endl  ;  //  1 , the count is still one

    // size of an unordered_set
    cout << s.size() << endl  ;  // 3 , and we know that the elements are 1 , 3 , 4

    // how to access an unordered_set
    // we can't access an unordered_set or a set by using [] notation
    // for printing/accessing the elements of set we can simply do this
    for(auto x:s)
    {
        cout << x << " " ;  //  it will print the elements of the s
    }
    cout << endl ;

    // by using iterators 
    // Iterators are generally used to access elements of an unordered_set/set/vector

    auto x = s.begin() ;  //  this will point to the first element of unordered_set

    // we can access the element by using '*' symbol
    cout << *x << endl ;
    // note: the output of the above line is not fixed 
    // it can be a any value from the unordered set elements 

    //  it will print the elements of the s
    // s.end() point towards the next position from last element
    // that's why will we continue our loop till iterator is not equal to s.end()
    // once iterator becomes equal to s.end() the loop will stop immediately
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " " ;
    }
    cout << endl ;

    // search for an element
    // s.find(x) will tells that whether 'x' is presents in unordered set or not 
    // and if s does not contain x then it will points towards s.end()
    auto it=s.find(8) ;
    if(it==s.end()) // means element is not found
    {
        cout << "element is not found" << endl ;
    }
    else
    {
        cout << "element is found" << endl ;
    }
    // above line will print 'element is not found' , because 8 is not presents in s



    return 0  ;
}
