#include <bits/stdc++.h>
using namespace std;
//lc133

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    void dfs(Node* node, Node* cloneNode) {
        // move to nodes children
        for (auto nbr : node->neighbors) {
            //check if child is present in map
            //if not,make its node & push clone child
            if (mp.find(nbr) == mp.end()) {
                // make clone of child
                Node* clone = new Node(nbr->val);
                mp[nbr] = clone;
                cloneNode->neighbors.push_back(clone);
                dfs(nbr, clone);
            } else {
                // if prst store it to neighbour
                cloneNode->neighbors.push_back(mp[nbr]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        //make clone node of node present
        if (!node) {
            return node;
        }
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;
        dfs(node, cloneNode);
        return cloneNode;
    }
};