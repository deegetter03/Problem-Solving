#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.lc938
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//METHOD1
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == NULL) return 0;
    int sum = 0;
        // agar root node (>)bada hai low se toh left subtree traverse kar do
    if (root->val > low) 
        sum += rangeSumBST(root->left, low, high);
        //agar root node is greater && smaller than high then sum value of nodes accordingly
    if (root->val >= low && root->val <= high) 
        sum += root->val;
        //if required then traverse right subtree but only when if root node is smaller than high
    if (root->val < high) 
        sum += rangeSumBST(root->right, low, high);
    return sum;
}
};

//METHOD2
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL) return 0;
        int curr = (root->val >= low && root->val <= high) ? root->val : 0;

        int leftSum = rangeSumBST(root->left, low, high);
        int rightSum = rangeSumBST(root->right, low, high);
        return curr + leftSum + rightSum;
    }
};