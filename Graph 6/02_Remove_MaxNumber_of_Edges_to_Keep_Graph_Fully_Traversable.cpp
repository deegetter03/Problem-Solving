#include <bits/stdc++.h>
using namespace std;

//lc1579
class Solution {
public:
    
    int findParent(int x, vector<int>&parent){
        if(x==parent[x])
            return x;
        return parent[x]=findParent(parent[x],parent);
    }
    void findUnion(int x, int y, vector<int>& parent){
        x=findParent(x,parent);
        y=findParent(y,parent);
        if(x==y)
            return;
        parent[y]=x;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        int ans=0;
        vector<int> parent1, parent2; // one for alice and one for bob
        parent1.resize(n);
        parent2.resize(n);

        for(int i=0 ; i<n ; i++){
            parent1[i]=i;
            parent2[i]=i;
        }
        
        for(auto x:e){ 
            // first connect type 3
            int a=x[1]-1, b=x[2]-1;
            if(x[0]==3){
                // if already connected then it is extra and should be added to ans
                if(findParent(a,parent1)==findParent(b,parent1)) 
                    ans++;
                else{ 
                    // connect for both
                    findUnion(a,b,parent1); 
                    findUnion(a,b,parent2);
                }
            }
        }

        for(auto x:e){ 
            // now check for alice
            int a=x[1]-1, b=x[2]-1;
            if(x[0]==1){
                if(findParent(a,parent1)==findParent(b,parent1))
                    ans++;
                else
                    findUnion(a,b,parent1); // connect type 1 if not connected already
            }
        }

        for(auto x:e){ 
            // check for bob
            int a=x[1]-1, b=x[2]-1;
            if(x[0]==2){
                if(findParent(a,parent2)==findParent(b,parent2))
                    ans++;
                else
                    findUnion(a,b,parent2); // connect type 2 if not connected already
            }
        }

        for(int i=0 ; i<n ; i++){ // check if both can traverse whole graph
            if(findParent(i,parent1)!=findParent(0,parent1))
                return -1;
            if(findParent(i,parent2)!=findParent(0,parent2))
                return -1;
        }
        return ans;
    }
};