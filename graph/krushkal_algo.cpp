#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#define n 7
class dsu{
	int parent[n];
	int value[n];
	public:
		dsu()
		{
			for(int i=1;i<n;i++)
			{
				parent[i]=i;
				value[i]=1;
			}
		}
		
		int find(int i)
		{
			if(parent[i]==i)
			{
				return i;
			}
			else 
			{
				return parent[i]=find(parent[i]);
			}
		}
		
		void unite(int x,int y)
		{
			int s1=find(x);
			int s2=find(y);
			if(s1!=s2)
			{
				if(value[s1]<value[s2])
				{
					parent[s1]=s2;
					value[s2]+=value[s1];
				}
				else
				{
					parent[s2]=s1;
					value[s1]+=value[s2];
				}
			}
		}
};





using namespace std;
class graph{
   vector<vector<int>>v;
	public:
		
		void add_edge(int x,int y,int z)
		{
			v.push_back({z,x,y});
		}
		
	void krushkal()
	{
		sort(v.begin(),v.end());
		dsu s;
		int ans=0;
		cout<<"the mst is "<<endl;
		for(auto it:v)
		{
			int z=it[0];
			int x=it[1];
			int y=it[2];
			if(s.find(x)!=s.find(y))
			{
				s.unite(x,y);
				ans+=z;
				cout<<x<<" "<<y<<" "<<z<<endl;
			}
		}
		cout<<ans;
	}
	
};


int main(int argc, char** argv) {
      graph g;
      g.add_edge(1,2,2);
      g.add_edge(2,3,3);
      g.add_edge(2,6,7);
      g.add_edge(2,4,3);
      g.add_edge(1,4,1);
      g.add_edge(1,5,4);
      g.add_edge(5,4,9);
      g.add_edge(4,3,5);
      g.add_edge(3,6,8);
      cout<<endl;
      cout<<endl;
    g.krushkal();
}
