#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.lc1008
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* createBST(int& i, int mini, int maxx, vector<int>& preorder) {
        if (i >= preorder.size()) return NULL;

        TreeNode* root = NULL;
        if (preorder[i] > mini && preorder[i] < maxx) {
            root = new TreeNode(preorder[i++]);
            root->left = createBST(i, mini, root->val, preorder);
            root->right = createBST(i, root->val, maxx, preorder);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxx = INT_MAX;
        int i = 0;
        return createBST(i, mini, maxx, preorder);
    }
};