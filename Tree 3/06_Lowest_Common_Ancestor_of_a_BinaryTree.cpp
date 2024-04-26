#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.,lc236
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if any p or q found return that node
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // if left is null and right 7 , return 7
        if (left == NULL)
            return right;
        // vice-versa
        else if (right == NULL)
            return left;
        // if left=2 and right = 3 then root is the lca
        else
            return root;
    }
};