#include <iostream>
#include <queue>

using namespace std;

/* A binary search node that contain generic data. */
template <typename T>

class bstNode{
public:
    T data;
    bstNode<T> *left, *right;

    bstNode(T elem){
        this->data = elem;
        left = right = NULL;
    }
    ~bstNode(){
        delete left;
        delete right;
    }
};

/*  The three main fuction along with some additional fuctions are implemented
    in this BST class.
*/
class BST{
private:
    bstNode<int> *root;

public:
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }

private:
    /*  As we know that private are not accessible outside the class.
        This is defined as deleteData takes root node as primary one every time. 
    */

    /*  This Function can takes any node pointer of BST and delete data from it,
        considering node as 'root'. 
    */
    bstNode<int> *deleteDataHelper(bstNode<int> *node, int data){
        /*Nothing to delete i.e (node == NULL) */
        if (!node){
            return NULL;
        }

        /*  If root is not the node to be delete then finding it in
            either left or right-subtree depending of given data    
        */
        if (node->data > data){
            node->left = deleteDataHelper(node->left, data);
            return node;
        }
        else if (node->data < data){
            node->right = deleteDataHelper(node->right, data);
            return node;
        }

        /*IF (node->data == data)*/
        else{
            /*If the node to be deleted is leaf node i.e. having no children */
            if (node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }

            /*If the node to be deleted is having right child */
            else if (node->left == NULL && node->right != NULL){
                bstNode<int> *temp = node->right; //storing address of right child
                node->right = NULL;
                delete node;
                return temp;
            }

            /*If the node to be deleted is having left child */
            else if (node->left != NULL && node->right == NULL){
                bstNode<int> *temp = node->left; //storing address of left child
                node->left = NULL;
                delete node;
                return temp;
            }

            /*  If the node to be deleted is having both children.
                In this case, we either find maximum from left-subtree or
                minimum from right-subtree of node so that it takes 
                deleted node position. In here, i found right-minimum.
            */
            else{
                bstNode<int> *rightMinNode = node->right;

                /*getting right minimum node*/
                while (rightMinNode->left != NULL){
                    rightMinNode = rightMinNode->left;
                }

                /*getting right minimum node data*/
                int rightMinData = rightMinNode->data;

                /*Replacing 'node->data' that is to be deleted with right minimum node*/
                node->data = rightMinData;

                /*Delete right minimum node from right-subtree*/
                node->right = deleteDataHelper(node->right, rightMinData);
                return node;
            }
        }
    }

public:
    void deleteData(int data){
        /*First search data in BST, if present then delete*/
        if (findData(data)){
            this->root = deleteDataHelper(this->root, data);
        }
    }

private:
    /*  This Function can takes any node pointer of BST and insert data in it,
        considering node as 'root'. 
    */
    bstNode<int> *insertDataHelper(bstNode<int> *node, int data){
        /*(node == NULL)*/
        if (!node){
            node = new bstNode<int>(data);
            return node;
        }

        /*  If data is greater than or equal to node->data 
            then it will be inserted in right-subtree else in left-subtree.
        */
        // If the data to be inserted is in left-subtree 
        if (node->data > data){
            node->left = insertDataHelper(node->left, data);
        }

        // If the data to be inserted is in right-subtree 
        else{
            node->right = insertDataHelper(node->right, data);
        }
        return node;
    }

public:
    /* This function insert data in BST */

    void insertData(int data){
        this->root = insertDataHelper(this->root, data);
    }

private:
    /*  This Function can takes any node pointer of BST and search data in it,
        considering node as 'root'. 
    */

    bool findDataHelper(bstNode<int> *node, int data){
        /*(node == NULL)*/
        if (!node){
            return false;
        }

        /*  If data is greater than or equal to node->data 
            then it will be definetily in right-subtree else in left-subtree.
        */
        // If the data is found
        if (node->data == data){
            return true;
        }

        // If the data to be search is in left-subtree
        else if (node->data > data){
            return findDataHelper(node->left, data);
        }

        // If the data to be search is in left-subtree
        else{
            return findDataHelper(node->right, data);
        }
    }

public:
    /*This function search data in BST, if present or not*/

    bool findData(int data){
        return findDataHelper(this->root, data);
    }

private:
    /* This takes a node and print all descendents in level-order.  */

    void printBTLevelWise(bstNode<int> *root){

        if (!root){
            return;
        }
        /*  To Hold the address of children of current nodes so that
            it can print first node and its children after that
        */
        queue<bstNode<int> *> q;
        q.push(root);

        while (!q.empty()){
            bstNode<int> *front = q.front();
            q.pop();
            cout << front->data << ": ";
            if (front->left){
                cout << "L=" << front->left->data << " ";
                q.push(front->left);
            }
            if (front->right){
                cout << "R=" << front->right->data << " ";
                q.push(front->right);
            }
            cout << '\n';
        }
    }

public:
    /*This Function prints the BST in level-wise order*/
    void print(){
        printBTLevelWise(this->root);
    }
};

