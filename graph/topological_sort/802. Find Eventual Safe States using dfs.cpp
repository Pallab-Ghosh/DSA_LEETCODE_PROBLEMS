#include <iostream>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>

using namespace std;


bool dfs(int start,int parent,list<int>l1[],vector<int>&vis,vector<int>&rec)
{
	vis[start]=true;
	rec[start]=true;
	
	list<int>::iterator it;
	for(it=l1[start].begin();it!=l1[start].end();it++)
	{
		if(!vis[*it] && dfs(*it,start,l1,vis,rec))
		{
			return true;
		}
		
		else if(rec[*it]==true)
		{
			return true;
		}
	}
	
	rec[start]=false;
	return false;
}

vector<int>eventualSafeNodes(vector<vector<int>>v)
{
	int n=v.size();
	vector<int>ind(n,0);
	list<int>l1[n];
	
	for(int i=0;i<n;i++)
	{
		
				for(auto it:v[i])
				{
					l1[i].push_back(it);
					ind[it]++;
				}
	
	}

      vector<int>visited(n,false);
      vector<int>rec(n,false);
      
      for(int i=0;i<n;i++)
      {
      	if(!visited[i])
      	{
      		dfs(i,-1,l1,visited,rec);
		}
      	
	  }
	  
	  
	  vector<int>ans;
	  for(int i=0;i<rec.size();i++)
	  {
	  	if(rec[i]==false)
	  	 ans.push_back(i);
	  }
	  
	  sort(ans.begin(),ans.end());
	  return ans;
}

//[1,2],[2,3],[5],[0],[5],[],[]
int main(int argc, char** argv) {
	
	vector<vector<int>>v={{1,2},{2,3},{5},{0},{5},{},{}};
	vector<int>ans=eventualSafeNodes(v);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
