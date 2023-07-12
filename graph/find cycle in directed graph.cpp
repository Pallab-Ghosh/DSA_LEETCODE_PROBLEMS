#include <iostream>
#include<vector>
#include<stack>
#define n 4
using namespace std;
class graph{
	vector<int>v[n];
    public:
    
		
    void add_edge(int x,int y)
    {
        v[x].push_back(y);
    }

    void display()
    {
        	vector<int>::iterator it;
        for(int i=0;i<n;i++)
        {
            for (it=v[i].begin();it!=v[i].end();it++)
            {
               cout<<*it<<" ";
            }
            cout<<endl;
        }
    }
    
    bool dfs(int start,vector<bool>visited, vector<bool>recstack)
    {
    	
    	if(visited[start] == false)
        {
        // Mark the current node as visited and part of recursion stack
        visited[start] = true;
        recstack[start] = true;
 
        // Recur for all the vertices adjacent to this vertex
        vector<int>::iterator i;
        for(i = v[start].begin(); i != v[start].end(); ++i)
        {
            if ( !visited[*i] && dfs(*i, visited, recstack) )
                return true;
                
            else if (recstack[*i])
                return true;
        }
       }
        
    recstack[start] = false;
    return false;
    }
    
	
    
    bool cycle(int s)
    {
    	vector<bool>recstack(n,false);
    	vector<bool>visited(n,false);
    	for(int i=0;i<n;i++)
    	{
    		if(visited[i]==false)
    		{
    			return dfs(i,visited,recstack);
			}
		}
	}
};

int main(int argc, char** argv) {
	graph g;
	g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(1,3);
   // g.add_edge(3,4);
    //g.add_edge(2,4);
    g.display();
   if(g.cycle(0))
    {
    	cout<<"has cycle";
	}
	else
	{
		cout<<"no cycle";
	}
	
}
