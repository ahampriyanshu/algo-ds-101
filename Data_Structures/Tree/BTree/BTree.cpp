#include<iostream>
#include<algorithm>
using namespace std;

//implementing BTree of Order 6

struct BTreeNode
{
    //Array containing keys in a node
    int *vals;
    //Array containing pointer to children in a node
    BTreeNode **children;
    //Checks if node is a leaf node or not
    bool isLeaf;
    //Maintains number of keys present in vals array
    int numberOfKeys;
};

// Pointer to root of tree and a temporary pointer
BTreeNode* root = NULL, *x = NULL;

//Creates a new empty node
BTreeNode * newNode(){
    BTreeNode* newptr = new BTreeNode;
    newptr->vals = new int[5];
    newptr->children = new BTreeNode *[6];
    newptr->isLeaf = true;
    newptr->numberOfKeys = 0;
    for (int i=0;i<6;i++){
        newptr->children[i] = NULL;
    }
    return newptr;
}

//Performs DFS Traversal on the tree, inorder traversal to be precise
void traverseBTree(BTreeNode* node){
    int i;
    for(i=0; i< node->numberOfKeys; i++){
        if(!node->isLeaf)
            traverseBTree(node->children[i]);
        cout<<" "<<node->vals[i];
    } 
    if(!node->isLeaf){
        traverseBTree(node->children[i]);
    }
    cout<<"\n";
}

//Handles the splitting of child when the tree is full to prevent overflow
int splitChild(BTreeNode *node, int index){
    int mid;
    BTreeNode* temp1 = newNode();
    temp1->isLeaf = true;
    if (index==-1){
        mid = node->vals[2];
        node->vals[2] = 0;
        node->numberOfKeys-=1;
        BTreeNode* temp = newNode();
        temp->isLeaf = false;
        node->isLeaf = true;
        for(int i=3;i<5;i++){
            temp1->vals[i-3] = node->vals[i];
            temp1->children[i-3] = node->children[i];
            temp1->numberOfKeys+=1;
            node->vals[i] = 0;
            node->numberOfKeys-=1;
        }
        for(int i=0;i<6;i++){
            node->children[i] = NULL;
        }
        temp->vals[0] = mid;
        temp->children[temp->numberOfKeys] = node;
        temp->children[temp->numberOfKeys+1] = temp1;
        temp->numberOfKeys++;
        root = temp;
    } else {
        BTreeNode *temp2 = node->children[index];
        mid = temp2->vals[2];
        temp2->vals[2] = 0;
        temp2->numberOfKeys-=1;
        for(int i=3;i<5;i++)
        {
            temp1->vals[i-3] = temp2->vals[i];
            temp1->numberOfKeys+=1;
            temp2->vals[i] = 0;
            temp2->numberOfKeys-=1;
        }
        x->children[index+1] = temp2;
        x->children[index+1] = temp1; 
    }
    return mid;
}

//Handles the cases related to insertion of node in the tree and calls appropriate functions when needed
void insertNode(int val){
    int i, temp;
    x = root;
    if(!x){
        root = newNode();
        x = root;
    } else {
        if(x->isLeaf && x->numberOfKeys==5){
            temp = splitChild(x, -1);
            x = root;
            for(i=0; i<(x->numberOfKeys);i++){
                if((val>x->vals[i]) && (val<x->vals[i + 1])){
                    i++;
                    break;
                } else if (val < x->vals[0]){
                    break;
                } else {
                    continue;
                }
            }
            x = x->children[i];
        } else {
            while (!x->isLeaf){
                for(i=0;i<(x->numberOfKeys);i++){
                    if((val>x->vals[i]) && (val<x->vals[i + 1])){
                        i++;
                        break;
                    } else if (val < x->vals[0]){
                        break;
                    } else {
                        continue;
                    }
                }
                if((x->children[i])->numberOfKeys==5){
                    temp = splitChild(x, i);
                    x->vals[x->numberOfKeys] = temp;
                    x->numberOfKeys+=1;
                    continue;
                } else {
                    x = x->children[i];
                }
            }
        }
    }
    x->vals[x->numberOfKeys] = val;
    sort(x->vals, x->vals + x->numberOfKeys);
    x->numberOfKeys+=1;
}

//Implementing Deletion in a class as there is circular dependency between removeFromSubtree and removeFromGeneral
//Such a case is very difficult to handle with sequential programming, hence using a class
class Deletion{
    public:
    //Returns the index of predecessor of the current node
    //Predecessor is the just smaller value, which means last element of the rightmost leaf to the left
    int getPredecessor(BTreeNode* node, int i){
        BTreeNode* temp = node->children[i];
        while(!temp->isLeaf)
            temp = temp->children[temp->numberOfKeys];
        return temp->vals[temp->numberOfKeys-1];
    }

    //Returns the index of successor of the current node
    //Successor is the just larger value, which means the first element of the leftmost leaf to the right
    int getSuccessor(BTreeNode* node, int i){
        BTreeNode* temp = node->children[i+1];
        while(!temp->isLeaf)
            temp = temp->children[0];
        return temp->vals[0];
    }

    //Borrows the value from the just previous child and copies it to the current one
    //Used when filling values in case there are less than 2 child
    void borrowFromPrevious(BTreeNode* node, int i){
        BTreeNode* c = node->children[i];
        BTreeNode* s = node->children[i-1];
        for(int j = c->numberOfKeys-1;j>=0;j--)
            c->vals[i+1] = c->vals[i];
        if(!c->isLeaf)
            for(int j = c->numberOfKeys;j>=0;j--)
                c->children[j+1] = c->children[j];

        c->vals[0] = node->vals[i-1];
        if(!c->isLeaf)
            c->children[0] = s->children[s->numberOfKeys];
        node->vals[i-1] = s->vals[s->numberOfKeys-1];
        c->numberOfKeys+=1;
        s->numberOfKeys-=1;
    }

    //Borrows the value from the just next child and copies it to the current one
    //Used when filling values in case of there are less than 2 child
    void borrowFromNext(BTreeNode* node, int i){
        BTreeNode* c = node->children[i];
        BTreeNode* s = node->children[i+1];
        c->vals[c->numberOfKeys] = node->vals[i];
        if(!c->isLeaf)
            c->children[c->numberOfKeys+1] = s->children[0];
        node->vals[i] = s->vals[0];
        for(int j=1;j<s->numberOfKeys;j++)
            s->vals[j-1] = s->vals[j];
        if(!s->isLeaf)
            for(int j=1;j<=s->numberOfKeys;j++)
                s->children[j-1] = s->children[j];
        c->numberOfKeys+=1;
        s->numberOfKeys-=1; 
    }

    //Merges the current child with the next child and frees the memory of unused pointer
    void merge(BTreeNode* node, int i){
        BTreeNode* c = node->children[i];
        BTreeNode* s = node->children[i+1];
        c->vals[2] = node->vals[i];
        for(int j=0;j<s->numberOfKeys;j++)
            c->vals[j+3] = s->vals[j];
        if(!c->isLeaf)
            for(int j=0;j<=s->numberOfKeys;j++)
                c->children[j+3] = s->children[j];
        for(int j=i+1;j<node->numberOfKeys;j++)
            node->vals[j-1] = node->vals[j];
        for(int j=i+2;j<=node->numberOfKeys;j++)
            node->children[j-1] = node->children[j];
        c->numberOfKeys+=(s->numberOfKeys+1);
        node->numberOfKeys-=1;
        delete(s);
    }

    // Return the value the just >= the given key
    int findClosestKey(BTreeNode* node, int key){
        int i=0;
        while(i<node->numberOfKeys && node->vals[i]<key)
            ++i;
        return i;
    }

    //Removes the value from given leaf node, copies the successive values
    void removeFromLeaf(BTreeNode* node, int i){
        for(int j=i+1;j<node->numberOfKeys;j++)
            node->vals[j-1] = node->vals[j];
        node->numberOfKeys-=1;
    }

    //Removes the value from given non leaf node
    //Checks number of keys in children and calls appropriate function
    void removeFromGeneral(BTreeNode* node, int i){
        int key = node->vals[i];
        if(node->children[i]->numberOfKeys >= 3){
            int pre = getPredecessor(node, i);
            node->vals[i] = pre;
            removeFromSubtree(node->children[i], pre);
        } else if(node->children[i+1]->numberOfKeys>=3){
            int suc = getSuccessor(node, i);
            node->vals[i] = suc;
            removeFromSubtree(node->children[i+1], suc);
        } else {
            merge(node, i);
            removeFromSubtree(node, i);
        }
    }

    //Handles the node which has less than 2 keys and fill values accordingly
    void fill(BTreeNode* node, int i){ 
        if(i!=0 && node->children[i-1]->numberOfKeys>=3)
            borrowFromPrevious(node,i);
        else if(i!=node->numberOfKeys && node->children[i+1]->numberOfKeys>=3)
            borrowFromNext(node,i);
        else{
            if(i!=node->numberOfKeys)
                merge(node,i);
            else
                merge(node,i-1);
        }
    } 

    //Removes values from the subtree rooted with given key
    void removeFromSubtree(BTreeNode* node, int key){
        int i = findClosestKey(node,key);
        if(i<node->numberOfKeys && node->vals[i]==key){
            if(node->isLeaf)
                removeFromLeaf(node, i);
            else
                removeFromGeneral(node,i);
        } else {
            if(node->isLeaf){
                cout<<"Key not found in tree\n";
                return;
            }
            bool flag = (i==node->numberOfKeys) ? true : false;
            if(node->children[i]->numberOfKeys<3)
                fill(node, i);
            if(flag && i>node->numberOfKeys)
                removeFromSubtree(node->children[i-1], key);
            else
                removeFromSubtree(node->children[i], key);
        }
    }

    //The utility function to be called by main
    void deleteNode(BTreeNode* root, int val){
        if(!root){
            cout<<"Tree is Empty\n";
            return;
        }
        removeFromSubtree(root, val);
        if(root->numberOfKeys==0){
            BTreeNode* temp = root;
            if(root->isLeaf)    
                root=NULL;
            else
                root = root->children[0];
            delete(temp);
        }
    }
};

// Searches the value in the given tree and returns a pointer to the node
BTreeNode* search(BTreeNode* root, int val){
    int i=0;
    while(i<root->numberOfKeys && val>root->vals[i])
        ++i;
    if(root->vals[i]==val)
        return root;
    if(root->isLeaf)
        return NULL;
    return search(root->children[i], val);
}

int main(){
    while(1){
        cout<<"++++++++++++++++++++++++++++++++++\n";
        cout<<"Select an Operation\n";
        cout<<" 1. Insert\n 2. Delete \n 3. Search \n 4.Traverse\n5. Exit \n";
        cout<<"++++++++++++++++++++++++++++++++++\n";
        int selection;
        cin>>selection;
        if(selection == 1){
            cout<<"Enter Number to Insert\n";
            int key;
            cin>>key;
            insertNode(key);
        } else if(selection == 2){
            cout<<"Enter Number to Delete\n";
            int num;
            cin>>num;
            BTreeNode* temp = search(root,num);
            Deletion d;
            if(temp)
                d.deleteNode(root,num);
            else
                cout<<"Value doesn't exist\n";
        } else if(selection==3){
            cout<<"Enter Number to Search\n";
            int num;
            cin>>num;
            BTreeNode* temp = search(root,num);
            if(temp)
                cout<<"Found\n";
            else
                cout<<"Not Found\n";
        } else if(selection == 4){
            cout<<"Traversal: ";
            traverseBTree(root);
            cout<<"\n";
        } else if(selection == 5){
            break;
        }
    }
}
