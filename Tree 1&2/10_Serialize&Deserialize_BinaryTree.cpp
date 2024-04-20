#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Codec {
    string s;
    int index;

public:
    // Encodes a tree to a single string.
    void ser(TreeNode* node) {
        // normalizing val
        node->val += 1000;

        // insert char1 to stores partialVal
        s.push_back(char(node->val & 127));

        node->val = node->val >> 7;
        node->val = node->val << 2;
        node->val += 64;

        // insert char2 to stores partial val and
        // it indicates existence of left and right subtrees
        if (node->left)
            node->val += 2;
        if (node->right)
            node->val += 1;
        s.push_back(char(node->val));

        // recursive preorder traversal
        if (node->left) {
            ser(node->left);
            // delete node once it is serialized
            TreeNode* temp = node->left;
            node->left = nullptr;
            delete (temp);
        }
        if (node->right) {
            ser(node->right);
            // delete node once it is serialized
            TreeNode* temp = node->right;
            node->right = nullptr;
            delete (temp);
        }
    }

    string serialize(TreeNode* root) {
        s = "";
        if (root)
            ser(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* des(string& d) {
        // decoding node val from two bytes
        int v = d[index++];
        int x = d[index++];
        v = v | (((x - 64) >> 2) << 7);
        TreeNode* node = new TreeNode(v - 1000);

        // extracting info about subtrees
        // and performing recursive preorder traversal
        if (x & 2)
            node->left = des(d);
        if (x & 1)
            node->right = des(d);

        return node;
    }
    TreeNode* deserialize(string data) {
        index = 0;
        if (data == "")
            return nullptr;
        return des(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));