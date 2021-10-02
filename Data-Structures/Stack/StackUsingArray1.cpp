#include <iostream>

using namespace std;
#define n 10
class stacks
{
    int* arr;
    int top;
public:
    stacks()
    {
       arr=new int[n];
       top=-1;
    }
    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop()
    {
        if(top==-1)
        {
        cout<<"stack underflow"<<endl;
        return;
        }
        cout<<arr[top];
        top--;
    }
    int Top()
    {
        if(top==-1)
        {
            cout<<"no element"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool emptys()
    {
        return top==-1;
    }

};
int main()
{
    //cout << "Hello world!" << endl;
    stacks st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    return 0;
}
