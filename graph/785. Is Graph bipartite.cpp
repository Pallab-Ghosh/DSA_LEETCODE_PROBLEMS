#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
                         bool bfs(int start,vector<int>color,int n,vector<vector<int>>& graph)
     {
         queue<int>q;
         color[start]=0;
         q.push(start);

         while(!q.empty())
         {                                   //o(n+2e)
             int node=q.front();
             q.pop();
             for(auto it:graph[node])
             {
                 if(color[it]==-1)
                 {
                     color[it]=!color[node];
                     q.push(it);
                 }
                 else if(color[it]==color[node])
                 {
                       return false;
                 }
             }
         }
         return true;
     }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
       
       vector<int>color(n,-1);

       for(int i=0;i<n;i++)
       {
           if(color[i]==-1)
           {
               if(bfs(i,color,n,graph)==false)
               {
                      return false;
               }
           }
       }
       return true;
        
    }


int main(int argc, char** argv) {
	return 0;
}
