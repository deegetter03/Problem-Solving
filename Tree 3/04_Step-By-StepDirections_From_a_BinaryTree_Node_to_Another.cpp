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

class Solution {
public:
    bool getpath(TreeNode* root, int a, stack<string>& st) {
        if (root == NULL)
            return 0;
        if (root->val == a)
            return 1;
        bool len = getpath(root->left, a, st);
        if (len) {
            st.push("L");
            return len;
        }
        len = getpath(root->right, a, st);
        if (len) {
            st.push("R");
            return len;
        }
        return 0;
    }

    string getDirections(TreeNode* root, int startvalue, int destvalue) {
        stack<string> s;
        stack<string> t;
        getpath(root, startvalue, s);
        getpath(root, destvalue, t);
        while (s.size() != 0 && t.size() != 0 && s.top() == t.top()) {
            s.pop();
            t.pop();
        }
        int n = s.size();
        int m = t.size();
        string ans = "";
        while (!s.empty()) {
            s.pop();
            ans += "U";
        }
        while (!t.empty()) {
            string temp = t.top();
            t.pop();
            ans += temp;
        }
        return ans;
    }
};