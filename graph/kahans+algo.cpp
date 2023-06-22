#include <iostream>
#include<vector>
#define n 5
#include<queue>
using namespace std;

class graph{
	vector<int>v[n];
	int indegree[n];
	public:
		graph()
		{
			for(int i=1;i<n;i++)
			{
				indegree[i]=0;
			}
		}
		void add_edge(int x,int y)
		{
			v[x].push_back(y);
			indegree[y]++;
		}
		
		void kanhs_algo()
		{
			queue<int>q;
			for(int i=1;i<n;i++)
			{
				if(indegree[i]==0)
				{
					q.push(i);
				}
			}
			
			
			while(!q.empty())
			{
				int s=q.front();
				cout<<s<<" ";
				q.pop();
				for(auto it:v[s])
				{
					indegree[it]--;
					if(indegree[it]==0)
					{
						q.push(it);
					}
				}
			}
		}
};



int main(int argc, char** argv) {
	graph g;
	g.add_edge(1,2);
	g.add_edge(1,4);
	g.add_edge(2,3);
	g.add_edge(2,4);
	g.add_edge(2,3);
	g.add_edge(4,3);
	g.add_edge(4,5);
	g.kanhs_algo();
}
