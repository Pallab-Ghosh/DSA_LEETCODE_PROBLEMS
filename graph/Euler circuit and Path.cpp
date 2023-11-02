#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void dfs(int start, vector<bool>&visited, vector<int>adj[])
{
    visited[start]=true;
    
    for(auto it=adj[start].begin();it!=adj[start].end();it++)
    {
        int child=*it;
        
        if(!visited[child])
        {
            dfs(child,visited,adj);
        }
    }
}


bool is_connected(int v,vector<int>adj[])

{
    
       vector<bool>visited(v,false);
       
       int start_vertex=-1;
       
       for(int i=0;i<v;i++)
       {
           if(adj[i].size()  != 0)
           {
               start_vertex=i;
               break;
           }
       }
       
       
       dfs(start_vertex,visited,adj);
       
       for(int i=0;i<v;i++)
       {
           if(visited[i]==false && adj[i].size() > 0)
           {
               return false;
           }
       }
       return true;
    
}



	int isEularCircuit(int V, vector<int>adj[])
	{
	  
	    
	  if(is_connected(V,adj)==false)
	  {
	        return 0;
	  }
	
	  
	  int count_odd=0;
	  
	  for(int i=0;i<V;i++)
	  {
	      if(adj[i].size() % 2 != 0)
	      {
	          count_odd++;
	      }
	  }
	  
	  if(count_odd > 2)
	  {
	      return 0;
	  }
	  
	  else if(count_odd == 2)
	  {
	      return 1;
	  }
	  
      else
	   return 2;
	  
	}

int main(int argc, char** argv) {
	return 0;
}
