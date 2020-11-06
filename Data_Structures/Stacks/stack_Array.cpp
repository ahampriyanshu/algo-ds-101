#include<iostream>
using namespace std;

class stack{
    private:
        int top;
        int j;
        int arr[];

    public:
        stack(){
            // int j;
            top = -1;
            cout << "What stack size you want? " << endl;
            cin >> j;
            for (int i = 0; i < j; i++)
            {
                arr[i] = 0;
            }
        }

        bool isEmpty(){
            if (top==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        } 

        bool isFull(){
            if (top==(j-1))
            {
                return true;
            }
            else
            {
               return false;
            }
        }

        void push(int i){
            if (isFull())
            {
                cout<<"Stack is Overflown"<<endl;
            }
            else
            {
                top++;
                arr[top] = i;
            }
        }

        int pop(){
            if (isEmpty())
            {
                cout << "Stack is Underflown" << endl;
                return 0;
            }
            else
            {
                int a = arr[top];
                arr[top] = 0;
                top--;
                return a;
            }
        }

        int count(){
            return top+1;
        }

        int peek(int i){
            return arr[i];
        }

        void change(int val, int pos){
            arr[pos] = val;
            cout << "Value changed at " << pos << " position to " << val << endl;
        }

        void display(){
            cout << "All values in the stack are:" << endl;
            for (int i = (j-1); i >= 0; i--)
            {
                cout << i + 1 << ".  " << arr[i]<<endl;
            }
        }

};

int main()
{
    stack s1;
    int opt, pos, val;
    system("clear");
    do
    {
        // system("clear");
        cout << "Select Operation's number to perform" << endl;
        cout << "0 EXIT" << endl;
        cout << "1 PUSH" << endl;
        cout << "2 POP" << endl;
        cout << "3 CHECK EMPTY" << endl;
        cout << "4 CHECK FULL" << endl;
        cout << "5 PEEK at position" << endl;
        cout << "6 COUNT" << endl;
        cout << "7 CHANGE" << endl;
        cout << "8 DISPLAY" << endl;
        cout << "9 CLEAR SCREEN" << endl<<endl;

        cin >> opt;

        switch (opt)
        {
        case 1:
            system("clear");
            cout << "Enter the number to push to the stack" << endl;
            cin >> val;
            s1.push(val);
            cout << endl<< endl<< endl;
            break;
        
        case 2:
            system("clear");
            cout << "Pop done!" << endl;
            cout<< s1.pop()<<" removed"<<endl;
            cout << endl<< endl<< endl;
            break;

        case 3:
            system("clear");
            if (s1.isEmpty())
            {
                cout << "Stack is underflown" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            cout << endl<< endl<< endl;
            break;

        case 4:
            system("clear");
             if (s1.isFull())
            {
                cout << "Stack is overflown" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            cout << endl<< endl<< endl;
            break;
        
        case 5:
            system("clear");
            cout << "Enter position number to peek at" << endl;
            cin >> pos;
            cout << s1.peek(pos) << " is at " << pos<< endl;
            cout << endl<< endl<< endl;
            break;

        case 6:
            system("clear");    
            cout << s1.count() <<endl;
            cout << endl<< endl<< endl;
            break;

        case 7:
            system("clear");
            cout << "Enter position number to make the change at" << endl;
            cin >> pos;
            cout << "Enter the number " << endl;
            cin >> val;
            s1.change(val,pos) ;
            cout << endl<< endl<< endl;
            break;

        case 8:
            system("clear");
            s1.display();
            cout << endl<< endl<< endl;
            break;

        case 9:
            system("clear");
            break;

        default:
            system("clear");
            cout << "Please enter a valid number "<<endl;
            break;
        }

        // system("clear");
    } while (opt != 0);

    return 0;
}
