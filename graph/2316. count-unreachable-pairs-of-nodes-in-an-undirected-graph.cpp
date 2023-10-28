#include <iostream>
#include<vector>

using namespace std;

   void dfs(vector<int>v[],vector<bool>&vis,int start,int &size )
{
	
   vis[start]=true;
   size++;
   vector<int>::iterator it;
   
   for(it=v[start].begin();it!=v[start].end();it++)
   {
   	  if(!vis[*it])
   	  {
   	  	dfs(v,vis,*it,size);
	  }
   }
 	
}

    long long countPairs(int n, vector<vector<int>>& edges) {
       		vector<int>v[n];
		vector<bool>vis(n,false);
		
        for(int i=0;i<edges.size();i++)
        {
        	int x=edges[i][0];
        	int y=edges[i][1];
        	
        	v[x].push_back(y);
        	v[y].push_back(x);
        
		}
		
	
		long long ans=0, viscount=n;
		
		for(int i=0;i<n;i++)
		{
			if(vis[i]==false)
			{ 
				int size=0;
				dfs(v,vis,i,size);

				ans+=size*(viscount-size);
				viscount=viscount-size;
			}
		}
		
	  return ans;
    }
    
int main(int argc, char** argv) {
	vector<vector<int>>v={{0,2},{0,5},{2,4},{1,6},{5,4}};
	int n=7;
	cout<<countPairs(n,v);
	
}
