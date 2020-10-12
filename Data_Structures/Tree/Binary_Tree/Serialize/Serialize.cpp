const int MARKER = numeric_limits<int>::min();
void serialize(BinaryTreeNode* node, ostream& sstream) {

  if (node == nullptr) {
    sstream.write((char*) &MARKER, sizeof(MARKER));
    return;
  }

  sstream.write((char*) &node->data, sizeof(node->data));
  serialize(node->left, sstream);
  serialize(node->right, sstream);
}

void test(vector<int>& v, bool display_output = false) {
  cout << "Create BST" << endl;
  BinaryTreeNode* root = create_BST(v);
  if (display_output) {
    display_preorder(root);
  }

  cout << "Start Serialize" << endl;
  ofstream outfile("temp.class", ios::binary);
  serialize(root, outfile);
  outfile.close();

  assert(are_identical_trees(root, root2));
}

int main(int argc, char const *argv[]) {
  vector<int> v = { 50, 25, 100 };
  test(v, true);
  
  v = {10 , 3, 8, 45, 9, 35, 69, 15, 12, 25, 24, 27, 13};
  test(v, true);

  v = create_random_vector(100);
  test(v, true);

  v = create_random_vector(2000000,
      numeric_limits<int>::max() - 10);
  cout << "\nRun big test" << endl;
  test(v, false);

  return 0;
}