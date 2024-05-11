#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure:

template <typename T>
class TreeNode
{
public:
  T data;
  TreeNode<T> *left;
  TreeNode<T> *right;

  TreeNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }

  ~TreeNode()
  {
    if (left)
      delete left;
    if (right)
      delete right;
  }
};

void traverseLeaf(TreeNode<int> *root, vector<int> &ans)
{
  if (root == NULL)
    return;
  traverseLeaf(root->left, ans);
  if (!root->left && !root->right)
    ans.push_back(root->data);
  traverseLeaf(root->right, ans);
}

void traverseLeft(TreeNode<int> *root, vector<int> &ans)
{
  if (!root || (!root->left && !root->right))
    return;
  ans.push_back(root->data);

  if (root->left)
    traverseLeft(root->left, ans);
  else
    traverseLeft(root->right, ans);
}

void traverseRight(TreeNode<int> *root, vector<int> &ans)
{
  if (!root || (!root->left && !root->right))
    return;

  if (root->right)
    traverseRight(root->right, ans);
  else
    traverseRight(root->left, ans);
  ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
  vector<int> ans;
  if (!root)
    return ans;
  ans.push_back(root->data);

  // Add all the left nodes
  traverseLeft(root->left, ans);

  //  Add all the leaf nodes
  traverseLeaf(root, ans);

  // Add all the right nodes in reverse order
  traverseRight(root->right, ans);
  return ans;
}