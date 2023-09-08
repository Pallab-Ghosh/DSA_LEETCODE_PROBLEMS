#include <iostream>
#include<vector>
#include<list>

using namespace std;
 int solve(map<int,vector<int>> mp, vector<bool> &vis, int i){
        
        vis[i] = 1;
        // map<int,vector<int>> store;
        
        // vis[0] = 1; 
        queue<int> q; 
        
        q.push(i); 
        set<int> bfs; 
        
        while(!q.empty()) {
            
            int node = q.front(); 
            q.pop(); 
            bfs.insert(node); 
             
            for(auto it : mp[node]) {
                 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        
        int size = bfs.size();
        for(auto it: bfs){
            if(mp[it].size() != size-1)
             return false;
        }
        return true; 
        
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
          map<int,vector<int>> mp;
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        // adj list ban gyi
        
        vector<bool> vis(n,0);
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                // naya component hai
                // check karo complete hai ya nahi
                int val = solve(mp,vis,i);
                ans += val;
            }
        }
        
        return ans;
        
    }
    
    
    int main()
    {
    	
	}
