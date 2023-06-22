#include <iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#define n 9
using namespace std;

class graph{
	vector<pair<int,int>>v[n];
    int distance[n];
	public:
		graph()
		{
			for(int i=0;i<n;i++)
			{
				distance[i]=INT_MAX;
			}
		}
		
		void add_edge(int x,int y,int z)
		{
			v[x].push_back({y,z});
			v[y].push_back({x,z});
		}
		
		void dikstra(int start)
		{
			vector<bool>visited(n,false);
			vector<pair<int,int>>::iterator it;
			set<pair<int,int>>s;
		    distance[start]=0;
		   s.insert({0,start});
		   while(!s.empty())
		   {
		   	  auto node=*s.begin();
		   	  int u=node.second;
		   	  int dis=node.first;
		   	  cout<<u<<" ";
		   	  s.erase(s.begin());
		   	  if(visited[u])
		   	  {
		   	  	continue;
			  }
			  visited[u]=true;
			  for(it=v[u].begin();it!=v[u].end();it++)
			  {
			  	  int child_u=it->first;
			  	  int value=it->second;
			  	  if(distance[u]+value<distance[child_u])
			  	  {
			  	  	 distance[child_u]=distance[u]+value;
			  	  	 s.insert({distance[child_u],child_u});
				  }
			  }
		   }
		   
		   for(int i=0;i<n;i++)
		   {
		   	cout<<"0---->"<<i<<"---->"<<distance[i]<<endl;
			   }	
		}
		
		
		void display()
		{
				vector<pair<int,int>>::iterator it;
				for(int i=0;i<n;i++)
				{
					cout<<i<<"----> ";
					for(it=v[i].begin();it!=v[i].end();it++)
					{
						cout<<"( "<<it->first<<","<<it->second<<" )";
					}
					cout<<endl;
				}
		}
		
};




int main(int argc, char** argv) {
	graph g;
	g.add_edge(0,1,4);
	g.add_edge(0,4,8);
	g.add_edge(1,2,8);
	g.add_edge(1,4,11);
	g.add_edge(4,5,1);
	g.add_edge(4,8,7);
	g.add_edge(2,3,7);
	g.add_edge(2,8,2);
	g.add_edge(2,6,4);
	g.add_edge(8,5,6);
	g.add_edge(5,6,2);
	g.add_edge(6,7,10);
	g.add_edge(3,7,9);
	g.add_edge(3,6,14);
	cout<<"----------";
	g.dikstra(0);
	cout<<endl;
   
}
