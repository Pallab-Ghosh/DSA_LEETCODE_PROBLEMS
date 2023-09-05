#include <iostream>

	void dfs(int start,	vector<int>lt[],vector<bool>&vis)
		{
		   vis[start]=true;
		   cout<<start<<" ";
		   vector<int>::iterator it;;
		   for(it=lt[start].begin();it!=lt[start].end();it++)
		   {
		   	  if(!vis[*it])
		   	  {
		   	  	dfs(*it,lt,vis);
			  }
		   }
			
		}


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         
        vector <bool> vis(n, 0);
        dfs(source,adj,vis);  
        for(int i=0;i<n;i++)
        {
            if(vis[source]==true && vis[destination]==true)
            return true;
        }

   return false;
  }

int main(int argc, char** argv) 
{
	return 0;
}
