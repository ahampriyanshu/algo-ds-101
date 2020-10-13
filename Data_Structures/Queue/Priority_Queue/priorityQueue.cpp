#include <iostream>
#include <cstring>
#include <queue> //added queue header file
using namespace std;

class Fun{
  
  public:
     void operator()(string s){
         cout<<"Having Fun with "<<s;
     }
     };

     // make functional object for priority queue
     class Person{
     public:
         string name;
         int age;
        Person(){


        }

        Person(string n, int a)
        {
            name = n;
            age = a;
        }
     };
    // make class of comparison of two person's age 
     class PersonCompare { 
     public:
        bool operator()(Person A, Person B){
            return A.age < B.age;  
        }
     };


     int main()
     {
         int n;
         cin>>n;
         // make priority for a person and in order to handle person compare we make another class Person compare instead of comparating function
        priority_queue<Person,vector<Person>, PersonCompare > pq;

        // make some  person object and takes data from user
         for(int i=0;i<n;i++)
         {
            string name;
            int age;
            cin>>name>>age;
            Person p(name,age);
            pq.push(p);
         }

         int k = 3;
         for(int i=0;i<k;i++){
             Person p= pq.top();
             cout<<p.name<<" "<<p.age<<endl;
             pq.pop();
            
         }
         return 0;
     }


