#include<iostream>
#include<cstring>
#include <chrono> 
#include <stdlib.h>     
#include <time.h>
#include <time.h> 
using namespace std::chrono; 
using namespace std;
using namespace std;

template<class T>
class deque {
  T* array;
  long capacity, curr_size;
  long start, end;
  public:
    deque(); // initialize a blank deque.
    deque(long n, T x); // initialize a deque of length n with all values as x.
    void extend(); // doubles the capacity of deque when deque is full
    void print(); // prints the deque
    void push_back(T x); // append data x at the end.
    void pop_back(); // erase data at the end.
    void push_front(T x); // append data x at the beginning.
    void pop_front(); // erase data at the beginning.
    T front(); // returns the first element(value) in the deque.
    T back(); // returns the last element(value) in the deque.
    bool empty(); // returns true if deque is empty else returns false.
    long size(); // returns the current size of deque.
    void resize(long x, T d); // changes the size dynamically. If the new size is greater than the current size of the deque, then fill the empty space with the default value d.
    void clear(); // remove all elements of deque.
    T operator[](long n); // returns the nth element of the deque
};

// initialize a blank deque
template<class T>
deque<T>::deque() { 
  capacity = 2;
  array = new T[capacity];
  curr_size = 0;
  start = 0;
  end = 0;
}

// initialize a deque of length n with all values as x
template<class T>
deque<T>::deque(long n, T x){ 
  capacity = n;
  array = new T[capacity];
  for(long i = 0; i < n; i++) {
    array[i] = x;
  }
  start = 0;
  end = n-1;
  curr_size = n;
}

// doubles the capacity of deque when deque is full
template<class T>
void deque<T>::extend(){
  T* temp = new T[2*capacity];
  int j = 0;
  // cout<<start<<" "<<end<<" "<<capacity<<"\n";
  for(int i = start; i<capacity; i++, j++) {
    temp[j] = array[i];
  }
  if(end<start)
  for(int i = 0; i<=end; i++, j++) {
    temp[j] = array[i];
  }
  start=0;
  end = j-1;
  capacity*=2;
  // cout<<endl;
  // for(int k = start; k <=end ; k++)
  //   cout<<temp[k]<<" ";
  delete [] array;
  array = temp;
  // cout<<"\nfrom extend\n";
  // this->print();
  // cout<<"done extend\n";
}

// prints the deque
template<class T>
void deque<T>::print(){
  // cout<<"\ncurr_size "<<curr_size; //<<endl;
  // cout<<" "<<start<<" "<<end<<" "<<capacity<<endl;
  // cout<<this->back()<<" "<<this->front();
  // for(int i = 0; i < capacity; i++)
    // cout<<array[i]<<" ";
  // cout<<endl;
  if(curr_size!=0) {
    if(end<start) {
      for(int i = start; i<capacity; i++) {
        cout<<array[i]<<" ";
      }
      for(int i = 0; i<=end; i++) {
        cout<<array[i]<<" ";
      }
    } else {
      for(int i = start; i<=end; i++) {
        cout<<array[i]<<" ";
      }
    }
    // cout<<"\narray\n";
    // for(int i = 0; i < curr_size; i++){
    //   cout<<(*this)[i]<<" ";
    // }
  }
  cout<<endl;
}

// append data x at the end.
template<class T>
void deque<T>::push_back(T x){
  if(curr_size==0) { array[start] = x; }
  else {
    if(curr_size>=capacity) { this->extend(); }
    end = (end+1)%capacity;
    array[end] = x;
  }
  curr_size++;
}

// erase data at the end.
template<class T>
void deque<T>::pop_back(){
  if(this->empty()) {
    cout<<"Pop back failed : Deque empty\n";
  } else {
    end = (end-1 + capacity)%capacity;
    curr_size--;
    if(curr_size==0){
      start = 0;
      end = 0;
    }
  }
}

// append data x at the beginning.
template<class T>
void deque<T>::push_front(T x){
  if(curr_size==0) { array[start] = x; }
  else {
    if(curr_size>=capacity) { this->extend(); }
    start = (start-1 + capacity)%capacity;
    // cout<<"\nstart "<<start;
    array[start] = x;
  }
  curr_size++;
}

// erase data at the beginning.
template<class T>
void deque<T>::pop_front(){
  if(this->empty()) {
    cout<<"Pop front failed : Deque empty\n";
  } else {
    start = (start+1)%capacity;
    curr_size--;
    if(curr_size==0){
      start = 0;
      end = 0;
    }
  }
}

// returns the first element(value) in the deque.
template<class T>
T deque<T>::front(){
  if(this->empty()) {
    cout<<"front failed : Deque empty\nExiting from the program\n";
    exit(1);
  } else {
    return array[start];
  }
}

// returns the last element(value) in the deque.
template<class T>
T deque<T>::back(){
  if(this->empty()) {
    cout<<"back failed : Deque empty\nExiting from the program\n";
    return (T)-1;
    // exit(1);
  } else {
    return array[end];
  }
}

// returns true if deque is empty else returns false.
template<class T>
bool deque<T>::empty(){
  if(this->size()==0) {
    return true;
  }
  return false;
}

// returns the current size of deque.
template<class T>
long deque<T>::size(){
  return curr_size;
  // if you want to calculate it instead of storing it in a variable curr_size
  // if(start<end)
  //   return (end-start+1);
  // return (end+capacity-start+1);
}

// changes the size dynamically. If the new size is greater than the current size of the deque, then fill the empty space with the default value d.
template<class T>
void deque<T>::resize(long x, T d){
  if(x<0) {
    cout<<"Invalid size as input\n";
    return;
  }
  if(x==0) {
    delete [] array;
    capacity = 2;
    array = new T[capacity];
    curr_size = 0;
    start = 0;
    end = 0;
  } else{
    T* temp = new T[x];
    int j = 0, count = x;
    if(end<start) {
      for(int i = start; i<capacity && x>0 ; i++, j++, x--) {
        temp[j] = array[i];
        // cout<<array[i]<<" ";
      }
      for(int i = 0; i<=end && x>0 ; i++, j++, x--) {
        temp[j] = array[i];
      }
    } else if(curr_size>0){
      for(int i = start; i<=end && x>0 ; i++, j++, x--) {
        temp[j] = array[i];
      }
    }
    while(x>0){
      temp[j++] = d;
      x--;
    }
    delete [] array;
    array = temp;
    capacity = count;
    start = 0;
    curr_size = capacity;
    end = capacity-1;
  } 

}
    
// remove all elements of deque.
template<class T>
void deque<T>::clear(){
  delete [] array;
  capacity = 2;
  array = new T[capacity];
  start = 0;
  end = 0;
  curr_size = 0;
}

// returns the nth element of the deque
template<class T>
T deque<T>::operator[](long n){ 
  if(n>=curr_size){
    cout<<"Invalid index access\n";
    exit(1);
  }
  long ind = (n+start)%capacity;
  return array[ind];
}


int main(){
  int t;
  cin>>t;
  deque<int> *d = NULL;
  while(t>0){
    int opt;
    cin>>opt;
    int ele;
    long int n;
    switch(opt){
      case 1:                 // push_front(ele)
        cin>>ele;
        d->push_front(ele);
        d->print();
        break;
      case 2:                // pop_front()
        d->pop_front();
        d->print();
        break;
      case 3:                // push_back(ele)
        cin>>ele;
        d->push_back(ele);
        d->print();
        break;
      case 4:                // pop_back()
        d->pop_back();
        d->print();
        break;
      case 5:               // create a new deque
        delete d;
        d = new deque<int>();
        break;
      case 6:               // create a new deque
        cin>>n;
        cin>>ele;
        delete d;
        d = new deque<int>(n, ele);
        d->print();
        break;
      case 7:               // front()
        cout<<d->front()<<endl;
        break;
      case 8:               // back()
        cout<<d->back()<<endl;
        break;
      case 9:               // empty()
        if(d->empty()){
          cout<<"true"<<endl;
        }else{
          cout<<"false"<<endl;
        }
        break;  
      case 10:                // size()
        cout<<d->size()<<endl;
        break;
      case 11:               // resize(new_size, default)
        cin>>n;
        cin>>ele;
        d->resize(n, ele);
        d->print();
        break;
      case 12:               // clear()
        d->clear();
        d->print();
        break;
      case 13:               // [] accessing
      {
        cin>>n;
        cout<<(*d)[n]<<endl;
        break;
      }
      case 14:               // print() - printing the deque
        d->print();
        break;
    }
    t--;
  }
  return 0;
}
