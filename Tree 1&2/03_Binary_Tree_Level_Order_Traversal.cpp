#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            // create inner list to store current level of element
            vector<int> innerList;
            // do 2 steps that have been told for current level elements
            for (int i = 1; i <= n; i++) {
                // remove front and add to innerList
                TreeNode* temp = q.front();
                q.pop();
                innerList.push_back(temp->val);

                // add next level elements
                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }
            // add innerList to ans
            ans.push_back(innerList);
        }
        return ans;
    }
};