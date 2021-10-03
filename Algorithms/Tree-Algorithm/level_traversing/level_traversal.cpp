
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> levelOrder(Node* root)
    {
      //Your code here
      vector<int> ans;
      
      if(!root) return ans;
      
      queue<Node*> q;
      q.push(root);
      
      while(!q.empty())
      {
          Node *t = q.front();
          ans.push_back(t->data);
          
          if (t->left) q.push(t->left);
          if (t->right) q.push(t->right);
          q.pop();
      }
      return ans;
    }
