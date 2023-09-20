#include <iostream>

 void dfs(list<int>lt[],int start,vector<bool>&vis)
    {
        vis[start]=true;
         list<int>::iterator it;
        for(it=lt[start].begin();it!=lt[start].end();it++)
        {
            if(!vis[*it])
            {
                dfs(lt,*it,vis);
            }
        }
    }
    
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        list<int>lt[n];
        vector<int>ans;
        vector<int>ind(n,0);
        queue<int>q;
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            
            lt[x].push_back(y);
            ind[y]++;
        }
        
        vector<bool>vis(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int start=q.front();
            q.pop();
            if(!vis[start])
            {
                dfs(lt,start,vis);
                ans.push_back(start);
            }
        }
       
        return ans;
    }

int main(int argc, char** argv) {
	return 0;
}
