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
  vector<int> solve(TreeNode *root, int &maxSum)
  {
    if (root == NULL)
      return {true, 0, INT_MIN, INT_MAX};
    if (root->left == NULL && root->right == NULL)
    {
      maxSum = max(maxSum, root->val);
      return {true, root->val, root->val, root->val};
    }

    vector<int> left = solve(root->left, maxSum);
    vector<int> right = solve(root->right, maxSum);

    if (left[0] && right[0])
    {
      int maxi = left[2];
      int mini = right[3];
      if (root->val > maxi && root->val < mini)
      {
        maxSum = max(maxSum, max(root->val + left[1] + right[1], max(left[1], right[1])));
        return {1, root->val + left[1] + right[1], max(root->val, right[2]), min(root->val, left[3])};
      }
    }
    maxSum = max(maxSum, max(left[1], right[1]));
    return {0, max(left[1], right[1]), INT_MIN, INT_MAX};
  }

  int maxSumBST(TreeNode *root)
  {
    int maxSum = 0;
    solve(root, maxSum);
    return maxSum;
  }
};