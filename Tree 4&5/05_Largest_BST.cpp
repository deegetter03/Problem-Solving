#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//   right(right) {}
// };

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

class Solution
{
public:
  bool isValidBST(Node *root, int min, int max) {
    if (root == NULL)  return true;
    if (min >= root->data || root->data >= max)  return false;
    return isValidBST(root->left, min, root->data) && isValidBST(root->right, root->data, max);
  }

  int countNodes(Node *root) {
    if (root == NULL)  return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }

  int largestBst(Node *root) {
    if (root == NULL)  return 0;

    if (isValidBST(root, INT_MIN, INT_MAX))  return countNodes(root);

    int leftSize = largestBst(root->left);
    int rightSize = largestBst(root->right);

    return max(leftSize, rightSize);
  }
};