#include<iostream>
#include<algorithm>
#define INT_MAX 2147483647
using namespace std;

struct TreeNode{
    //stores data - represents left, right, middle
    int keys[3];
    // 4 pointers which refer to child, also stores parent node pointer
    struct TreeNode* p1, *p2, *p3, *p4, *parent;
    //maintains numbers of keys in keys array
    int keyCount;
};

TreeNode* root = NULL;

//prints inorder traversal of 2-3 tree
void printInorder(TreeNode* root){
    if(!root)
        return;
    printInorder(root->p1);
    cout<<root->keys[0]<<" ";
    printInorder(root->p2);
    if(root->keyCount==2)
        cout<<root->keys[1]<<" ";
    printInorder(root->p3);
}

//prints preorder traversal of 2-3 tree
void printPreorder(TreeNode* root){
    if(!root)
        return;
    cout<<root->keys[0]<<" ";
    printPreorder(root->p1);
    if(root->keyCount==2)
        cout<<root->keys[1]<<" ";
    printPreorder(root->p2);
    printPreorder(root->p3);
}

//prints postorder traversal of 2-3 tree
void printPostorder(TreeNode* root){
    if(!root)
        return;
    printPostorder(root->p1);
    printPostorder(root->p2);
    printPostorder(root->p3);
    if(root->keyCount==2)
        cout<<root->keys[1]<<" ";
    cout<<root->keys[0]<<" ";
}

//creates and initializes a new node
TreeNode* newNode(int key){
    TreeNode* node = new TreeNode;
    node->keys[0] = key;
    node->keys[1] = node->keys[2] = INT_MAX;
    node->p1 = node->p2 = node->p3 = node->p4 = node->parent = NULL;
    node->keyCount = 1;
    return node;
}

//searches the 2-3 tree and returns the node containing the key, returns NUlL when not found
TreeNode* search(TreeNode* root, int key){
    if(!root)
        return NULL;
    if(key<root->keys[0])
        return search(root->p1, key);
    if(key>root->keys[0] && key < root->keys[1])
        return search(root->p2, key);
    if(key > root->keys[1])
        return search(root->p3, key);
    return root;
}

// checks if node is in overflow condition 
bool isOverflow(TreeNode* node){
    return node && node->keyCount == 3;
}

// fixes the overflow condition, splits the overflowing node and shifts its middle to the parent
void fixOverflow(TreeNode *node) {
    cout<<"Fix Overflow Start\n";
	while (isOverflow(node)) { 
		int median = node->keys[1];
		TreeNode *temp = newNode(node->keys[2]);
		temp->p2 = node->p4;
		temp->p1 = node->p3;
		if (temp->p2)
			temp->p2->parent = temp;
		if (temp->p1)
			temp->p1->parent = temp;
		node->keys[1] = node->keys[2] = INT_MAX;
		node->p3 = node->p4 = NULL;
		node->keyCount = 1;
		TreeNode *p = node->parent;
		if (!p) {
			root = newNode(median);
			node->parent = temp->parent = root;
			root->p2 = temp;
			root->p1 = node;
			break;
		} else {
			temp->parent = p;
			if (node == p->p1) { 
				p->keys[2] = p->keys[1];
				p->keys[1] = p->keys[0];
				p->keys[0] = median;
				p->keyCount++;
				p->p4 = p->p3;
				p->p3 = p->p2;
				p->p2 = temp;
			} else if (node == p->p2) { 
				p->keys[2] = p->keys[1];
				p->keys[1] = median;
				p->keyCount++;
				p->p4 = p->p3;
				p->p3 = temp;
			} else { 
				p->keys[2] = median;
				p->keyCount++;
				p->p4 = temp;
			}
			node = p;
		}
	}
    cout<<"Fix Overflow End\n";
}

// utility function to insert in a 2-3 tree, in case the overflow condition occur, fixOverflow is called
void insert(int key) {
    cout<<"Insert Start\n";
	TreeNode *node = NULL;
	TreeNode *temp = root;
	while(temp){
		node = temp; 
		if (key < temp->keys[0])
			temp = temp->p1;
		else if (temp->keyCount == 1)
			temp = temp->p2;
		else
			temp = temp->p3;
	}
	if (!node){
        cout<<"ok\n";
		root = newNode(key);
    }
	else {
		if (key < node->keys[0]){
			node->keys[2] = node->keys[1];
			node->keys[1] = node->keys[0]; 
			node->keys[0] = key;
		} else if (key > node->keys[0] && key < node->keys[1]){
			node->keys[2] = node->keys[1];
			node->keys[1] = key;
		} else
			node->keys[2] = key;

		node->keyCount++;
		if (isOverflow(node)) 
			fixOverflow(node);
	}
    cout<<"Insert End\n";
}

// checks underflow condition
bool isUnderflow(TreeNode* node){
    return node && node->keyCount<1;
}

// checks if a node can donate one of its keys
bool canDonate(TreeNode* node){
    return node && node->keyCount>1;
}

bool isEmpty(TreeNode* node){
    return node->keyCount==0;
}

bool isRoot(TreeNode* node){
    return node == root;
}

// fixes the underflow condition, redistribution and merging operations are done to overcome underflow
void fixUnderflow(TreeNode *node) {
	while (isUnderflow(node)){ 
		TreeNode *p = node->parent;
		TreeNode *x = NULL; 
		TreeNode *z = NULL; 
		if (node == p->p1){ 
			z = p->p2;
		} else if (node == p->p2) { 
			x = p->p1;
			z = p->p3;
		} else { 
			x = p->p2;
		}
		if (canDonate(z)) { 
			if(node == p->p1) {
				node->keys[0] = p->keys[0];
				p->keys[0] = z->keys[0]; 
			} else {
				node->keys[0] = p->keys[1];
				p->keys[1] = z->keys[0]; 
			}
			node->p2 = z->p1;
			if (node->p2)
				node->p2->parent = node;
			node->keyCount++;
			z->keys[0] = z->keys[1];
			z->keys[1] = INT_MAX;
			z->p1 = z->p2;
			z->p2 = z->p3;
			z->p3 = NULL;
			z->keyCount--;

		} else if (canDonate(x)) { 
			if(x == p->p1) {
				node->keys[0] = p->keys[0];
				p->keys[0] = x->keys[1]; 
			} else {
				node->keys[0] = p->keys[1];
				p->keys[1] = x->keys[1]; 
			}
			node->p1 = x->p3;
			if (node->p1)
				node->p1->parent = node;
			node->keyCount++;
			x->keys[1] = INT_MAX;
			x->p3 = NULL;
			x->keyCount--;
		} else {
			if (z){
				if (node == p->p1)
					node->keys[0] = p->keys[0];
				else
					node->keys[0] = p->keys[1];
				node->keys[1] = z->keys[0];
				node->p2 = z->p1;
				node->p3 = z->p2;
				if (node->p2)
					node->p2->parent = node;
				if (node->p3)
					node->p3->parent = node;
				node->keyCount += 2;
				if (node == p->p1) {
					p->p2 = p->p3;
					p->keys[0] = p->keys[1];
				}
				p->p3 = NULL;
				p->keys[1] = INT_MAX;
				p->keyCount--;
				if (isEmpty(p) && isRoot(p)) {
					free(p);
					node->parent = p = NULL;
					root = node;
				}
				free(z);
			} else {
				if (x == p->p1)
					x->keys[1] = p->keys[0];
				else
					x->keys[1] = p->keys[1];
				x->p3 = node->p1;
				if (x->p3)
					x->p3->parent = x;
				x->keyCount++;
				if (x == p->p1) {
					p->p2 = p->p3;
					p->keys[0] = p->keys[1];
				}
				p->p3 = NULL;
				p->keys[1] = INT_MAX;
				p->keyCount--;
				if (isEmpty(p) && isRoot(p)) {
					free(p);
					x->parent = p = NULL;
					root = x;
				}
				free(node);
			}
		}
		node = p;
	}
}

// gets the inorder successor to the given node
TreeNode* getMin(TreeNode* root){
    if(root->p1)
        getMin(root->p1);
    return root;
}

TreeNode* getMax(TreeNode* root){
    if(root->p3)
        getMax(root->p3);
    if(root->p2)
        getMax(root->p2);
    return root;
}

bool isLeaf(TreeNode* node){
    return !node->p1 && !node->p2;
}

// delete helper function, performs simple deletion and checks if there is underflow or not, if yes, then calls, fixUnderflow
void deleteNode(int key) {
	TreeNode *node = search(root, key);
	if (isLeaf(node)) {
		if (key == node->keys[0]) {
			node->keys[0] = node->keys[1];
			node->keys[1] = INT_MAX;
		} else
			node->keys[1] = INT_MAX;
		node->keyCount--;
		if (isUnderflow(node)) { 
			if (isRoot(node)) {
				free(root);
				root = NULL;
			} else
				fixUnderflow(node);
		}
	} else {
		TreeNode *y = NULL;
		if (key == node->keys[0])
			y = getMin(node->p2);
		else
			y = getMin(node->p3);
		if (key == node->keys[0])
			node->keys[0] = y->keys[0];
		else
			node->keys[1] = y->keys[0];
		y->keys[0] = y->keys[1];
		y->keys[1] = INT_MAX;
		y->keyCount--;

		if (isUnderflow(y))
			fixUnderflow(y);
	}
}

int main(){
    while(1){
        cout<<"++++++++++++++++++++++++++++++++++\n";
        cout<<"Select an Operation\n";
        cout<<" 1. Insert\n 2. Delete \n 3. Search \n 4. Inorder Traverse\n 5. Preorder Traverse\n 6. Postorder Traverse\n 7. Exit \n";
        cout<<"++++++++++++++++++++++++++++++++++\n";
        int selection;
        cin>>selection;
        if(selection == 1){
            cout<<"Enter Number to Insert\n";
            int key;
            cin>>key;
            insert(key);
        } else if(selection==2){
            cout<<"Enter Number to Delete\n";
            int num;
            cin>>num;
            deleteNode(num);
        } else if(selection==3){
            cout<<"Enter Number to Search\n";
            int num;
            cin>>num;
            TreeNode* temp = search(root,num);
            if(temp)
                cout<<"Found\n";
            else
                cout<<"Not Found\n";
        } else if(selection==4){
            printInorder(root);
            cout<<"\n";
        } else if(selection==5){
            printPreorder(root);
            cout<<"\n";
        } else if(selection==6){
            printPostorder(root);
            cout<<"\n";
        } else if(selection==7){
            break;
        }
    }
}

