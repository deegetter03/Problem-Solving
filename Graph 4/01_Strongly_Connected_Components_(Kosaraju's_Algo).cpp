#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void new_dfs(vector<bool>&visited,vector<vector<int>>&transpose,int src)
    {
        visited[src]=true;
        for(int i=0;i<transpose[src].size();i++)
        {
            if(visited[transpose[src][i]]==false)
            new_dfs(visited,transpose,transpose[src][i]);
        }
    }
    void dfs(vector<int>&vis,vector<vector<int>>& adj,int src, stack<int>&st)
    {
        vis[src]=1;
        for(int i=0;i<adj[src].size();i++)
        {
            if(vis[adj[src][i]]==0)
             dfs(vis,adj,adj[src][i],st);
        }
        st.push(src);
    }
    int kosaraju(int v, vector<vector<int>>& adj)
    {
         vector<int>vis(v,0);
         stack<int>st;
           for(int i=0; i<v;i++){
           if(!vis[i])
           dfs(vis,adj,i,st);
           }
           vector<vector<int>>transpose(v);
           for(int i=0;i<v;i++)
           {
               for(int j=0;j<adj[i].size();j++)
               {
                   transpose[adj[i][j]].push_back(i);
               }
           }
           int count=0;
           vector<bool>visited(v,false);
           while(!st.empty())
           {
               if(visited[st.top()]==false)
               {
                   count++;
                    visited[st.top()]=true;
                   new_dfs(visited,transpose,st.top());
               }
               st.pop();
           }
        return count ;
    }
};