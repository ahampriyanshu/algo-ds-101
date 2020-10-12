const int MARKER = numeric_limits<int>::min();

BinaryTreeNode* deserialize(istream& sstream) {
  if (sstream.eof()) {
    return nullptr;
  }
  int val;
  sstream.read((char*) &val, sizeof(val));
  if (val == MARKER) {
    return nullptr;
  }

  BinaryTreeNode* pNode = new BinaryTreeNode(val);
  pNode->left = deserialize(sstream);
  pNode->right = deserialize(sstream);

  return pNode;
}

void test(vector<int>& v, bool display_output = false) {
  cout << "Start De-Serialize" << endl;
  ifstream infile("temp.class", ios::binary);
  BinaryTreeNode* root2 = deserialize(infile);
  infile.close();

  if (display_output) {
    cout << "\nDeserialized :\n";
    display_preorder(root2);
    cout << endl << endl;
  }

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