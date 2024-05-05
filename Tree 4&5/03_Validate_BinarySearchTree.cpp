#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool checkBST(TreeNode *root, long from, long to) {
    if (!root) return true;
    if (root->val <= from || root->val >= to)
      return false;
    return checkBST(root->left, from, root->val) && checkBST(root->right, root->val, to);
  }
  bool isValidBST(TreeNode *root) {
    return checkBST(root, LONG_MIN, LONG_MAX);
  }
};