#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        map<int,Node*>mp;
        queue<pair<int,Node*>>q;
        q.push({0,root});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            auto node = it.second;
            int ind = it.first;
            if(mp.find(ind)==mp.end()){
                mp[ind] = node;
            }
            if(node->left)q.push({ind-1,node->left});
            if(node->right)q.push({ind+1,node->right});
        }
        vector<int>ans;
        for(auto it:mp){
            auto k = it.second;
            ans.push_back(k->data);
        }
        return ans;
    }
};