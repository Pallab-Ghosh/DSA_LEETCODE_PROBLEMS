#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void make( vector<int>&parent,int n)
   {
          for(int i=0;i<parent.size();i++)
          {
              parent[i]=i;
          }
   }

   int find(int i,vector<int>&parent)
   {
       if(i==parent[i])
       return i;

       return parent[i]=find(parent[i],parent);
   }

 

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(1001,0);
    
        vector<int>ans;

        make(parent,n);

        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int p1=find(u,parent);
            int p2=find(v,parent);

            if(p1==p2)
            {
                ans=it;
            }
            parent[p1]=p2;
        }
        return ans;
    }

int main(int argc, char** argv) {
	return 0;
}
