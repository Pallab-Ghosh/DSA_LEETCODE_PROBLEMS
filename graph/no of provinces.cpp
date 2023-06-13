#include <iostream>
#include<vector>
using namespace std;


void dfs(vector<int>list[],int start,vector<bool>&visited)
{
	visited[start]=true;
	vector<int>::iterator it;
	for(it=list[start].begin();it!=list[start].end();it++)
	{
		if(!visited[*it])
		{
			dfs(list,*it,visited);
		}
	}
}

int no_of_provinces(vector<vector<int>>v)
{
	int n=v.size();
	vector<int>list[n];
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j]==1 and i!=j)
			{
				list[i].push_back(j);
				list[j].push_back(i);
			}
		}
		
	}
	   int c=0;
	   vector<bool>visited(n,false);
		for(int i=0;i<v.size();i++)
		{
			cout<<"i---> "<<i<<endl;
			if(visited[i]==false)
			{
				dfs(list,i,visited);
				if(visited[i])
				c++;
			}
		}
		

	return c;
}

int main(int argc, char** argv) {
	vector<vector<int>>v{
	 {1,1,0}
	,{1,1,0}
	,{0,0,1}
	};
	cout<<"ans is ";
	cout<<no_of_provinces(v);
}
