#include <iostream>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>

using namespace std;

vector<int>eventualSafeNodes(vector<vector<int>>v)
{
	int n=v.size();
	vector<int>ind(n,0);
	list<int>l1[n];
	
	for(int i=0;i<n;i++)
	{
		
				for(auto it:v[i])
				{
					l1[it].push_back(i);
					ind[i]++;
				}
	
	}

	vector<int>ans;
	queue<int>q;
	for(int i=0;i<n;i++)
	{
		if(ind[i]==0)
		q.push(i);
	}
	                 //o(nlogn+e+v)
	while(!q.empty())
	{
		int start=q.front();
		q.pop();
		ans.push_back(start);
		for(auto it:l1[start])
		{
			ind[it]--;
			if(ind[it]==0)
			{
				q.push(it);
			}
		}
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
