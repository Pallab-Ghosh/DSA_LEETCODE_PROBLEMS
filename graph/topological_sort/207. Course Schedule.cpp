#include <iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;


bool topological_sort(list<int>l1[],int n,vector<int>&indegree)
{
	queue<int>q;
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
		 q.push(i);
	}
	
	list<int>::iterator it;
	
	int c=0;
	while(!q.empty())
	{
		int start=q.front();
		q.pop();
		cout<<start<<" ";
		c++;
		for(auto it:l1[start])
		{
			indegree[it]--;
			if(indegree[it]==0)
			{
				q.push(it);
			}
		}
	}
 return c==n?true:false;

}

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
   {
   	
   vector<int>indegree(numCourses,0);
	list<int>l1[numCourses];

	for(int i=0;i<prerequisites.size();i++)
	{
	
		int x=prerequisites[i][1];
		int y=prerequisites[i][0];
		
		l1[x].push_back(y);
	
		indegree[y]++;
	}
	return topological_sort(l1,numCourses,indegree);
    }


int main(int argc, char** argv) {
	vector<vector<int>>edges={{1,0}};
	
	int n=4;
	vector<int>indegree(n,0);
	list<int>l1[n];
	

	for(int i=0;i<edges.size();i++)
	{
	
		int x=edges[i][0];
		int y=edges[i][1];
		
		l1[x].push_back(y);
	
		indegree[y]++;
	}
	  
	  if(canFinish(n,edges))
	  {
	  	cout<<"possible";
	  }
	  else
	  {
	  	cout<<"not";
	  }
}
