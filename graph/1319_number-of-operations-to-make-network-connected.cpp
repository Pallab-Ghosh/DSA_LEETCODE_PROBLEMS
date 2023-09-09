#include <iostream>
#include<vector>
#include<list>
using namespace std;


void dfs(int start,list<int>adj[],vector<bool>&vis)
{
	vis[start]=true;
	list<int>::iterator it;
	for(it=adj[start].begin();it!=adj[start].end();it++)
	{
		if(!vis[*it])
		{
			dfs(*it,adj,vis);
		}
	}
}
 int makeConnected(int n, vector<vector<int>>& connections) 
    {
    		 if(connections.size() <n-1);
        list<int>adj[n];
        for(int i=0;i<connections.size();i++)
        {
        	int x=connections[i][0];
        	int y=connections[i][1];
        	
        	adj[x].push_back(y);
        	adj[y].push_back(x);
		}
		
		int c=-1;
		vector<bool>visited(n,false);
		for(int i=0;i<n;i++)
		{
			if(visited[i]==false)
			{
				dfs(i,adj,visited);
				c++;
			}
		}
		return c;
    }

int main(int argc, char** argv) {
	int n = 6;
	vector<vector<int>>connections={
	{0,1},
	{0,2},
	{0,3},
	{1,2},
	{1,3}
	};
	cout<<makeConnected(n,connections);
}
