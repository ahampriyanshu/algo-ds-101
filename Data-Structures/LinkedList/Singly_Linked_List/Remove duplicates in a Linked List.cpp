#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
}*head = NULL;
void create(int size){
    int data, i;
    Node *temp;
    temp = head;
    cout << "Enter data: \n";
    for(int  i = 0; i < size; i++){
        cin >> data;
        if(temp == NULL){
            cout << "Couldn't allocate memory";
            break;
        }
        if( i == 0 ){
            head -> data = data;
            head -> next = NULL;
        }
        else{
            Node *newNode = new Node();
            newNode -> data = data;
            newNode -> next = NULL;
            temp -> next = newNode;
            temp = temp -> next;
        }
        
    }
}
void deleteNum(){
    Node *ptr1, *ptr2, *prev;
    ptr1 = head;
    while(ptr1 != NULL){
        ptr2 = ptr1 -> next;
        prev = ptr1;
        while(ptr2 != NULL){
            if(ptr1 -> data == ptr2 -> data){
                prev -> next = ptr2 -> next;
            }
            prev = ptr2;
            ptr2 = ptr2 -> next;
        }
        ptr1 = ptr1 -> next;
    }
}
void display(){
    Node *temp = head;
    if(head == NULL){
        cout << "Empty list";
    }
    while(temp != NULL){
        cout << temp -> data << "\t";
        temp = temp -> next;
    }
    cout << endl;
}
int main()
{
    int n, i;
    head = new Node();
    cout << "Enter no.of nodes \n";
    cin >> n;
    create(n);
    cout << "Original Linked List: \n";
    display();
    deleteNum();
    cout << "After removin duplicates: \n";
    display();
    
}


