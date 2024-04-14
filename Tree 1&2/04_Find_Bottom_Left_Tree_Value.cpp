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
    int findBottomLeftValue(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int ans = -1;
        bool flag = true;
        while (!q.empty()) {
            int curr_size = q.size();
            flag = true;
            for (int i = 0; i < curr_size; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                if (flag) {
                    ans = currNode->val;
                    flag = false;
                }
                if (currNode->left)
                    q.push(currNode->left);
                if (currNode->right)
                    q.push(currNode->right);
            }
        }
        return ans;
    }
};