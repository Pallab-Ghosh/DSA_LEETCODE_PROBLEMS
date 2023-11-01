#include <iostream>
#include<vector>
#include<stack>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void dfs_for_topo_sort(vector<vector<int>>& adj,stack<int>&st,int start,vector<bool>&vis)
{
	vis[start]=true;
	
	for(int &it:adj[start])
	{
		if(!vis[it])
		{
			dfs_for_topo_sort(adj,st,it,vis);
		}
	}
	st.push(start);
}



void dfs(int start, vector<bool>&vis ,vector<vector<int>>& adjReversed)
{
	vis[start]=true;
	
	for(int &it:adjReversed[start])
	{
		if(!vis[it])
		{
			dfs(it,vis,adjReversed);
		}
	}
}


int kosaraju(int v, vector<vector<int>>& adj)
    {
        //code here
        stack<int>st;
        vector<bool>vis(v,false);
        
        
        //for topo_sort to get the sequence of vertices to start the DFS;
        for(int i=0;i<v;i++)
        {
        	if(!vis[i])
        	{
        		dfs_for_topo_sort(adj,st,i,vis);
			}
		}
		
		//For reverse the edges of the graph
			vector<vector<int>> adjReversed(v);
		for(int u=0;u<v;u++)
		{
			for(int &child:adj[u])
			{
				 adjReversed[child].push_back(u);
			}
		}
		
		
		int count=0;
		
	 
		vis= vector<bool>(v,false);
		
	     while(!st.empty())
		  {
            int node = st.top();
            st.pop();
            if(!vis[node])
			 {
                dfs(node,vis,adjReversed);
                count++;
            }
        }
        return count;
    }
    
    
int main(int argc, char** argv) {
	int V=11;
	vector<vector<int>>adj={{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3},{6,5},{6,7},{7,8},{8,9},{9,6},{9,10}};
	cout<<kosaraju(V,adj);
}
