#include <iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;


vector<int>findMinHeightTrees(int n,vector<vector<int>>v)
{
	if(n==1)
	return {0};
	
	
	list<int>l1[n];
	vector<int>ind(n,0);
	for(int i=0;i<v.size();i++)
	{
		int x=v[i][0];
		int y=v[i][1];
		
		l1[x].push_back(y);
		l1[y].push_back(x);
	    
	    ind[x]++;
	    ind[y]++;
	}
	

	queue<int>q;
	vector<int>ans;
	for(int i=0;i<n;i++)
	{
		if(ind[i]==1)
		q.push(i);
	}
	
	
	list<int>::iterator it;
	
	while(!q.empty())
	{
		ans.clear();
		int size=q.size();
		
		 while(size--)
		 {
		 	
		 	int start=q.front();
		 	
		 	q.pop();
		 	
		 	ans.push_back(start);
		 	
		   for(auto it:l1[start])
           {
               ind[it]--;
               if(ind[it]==1)
               {
                   q.push(it);
               }
           }
	    }

}

return ans;
}



int main(int argc, char** argv) {
	
	int n=6;
	vector<vector<int>>v={{0,3},{1,3},{2,3},{4,3},{4,5}};

	vector<int>ans=findMinHeightTrees(n,v);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
