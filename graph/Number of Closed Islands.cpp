#include <iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& grid,int i,int j,int n,int m)
{
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=0)
     return;

     grid[i][j]=1;
     dfs(grid,i-1,j,n,m);
     dfs(grid,i+1,j,n,m);
     dfs(grid,i,j+1,n,m);
     dfs(grid,i,j-1,n,m);
}
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
               dfs(grid,i,0,n,m);

            if(grid[i][m-1]==0)
               dfs(grid,i,m-1,n,m);
        }

        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==0)
               dfs(grid,0,i,n,m);

            if(grid[n-1][i]==0)
               dfs(grid,n-1,i,n,m);
        }

      int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(grid,i,j,n,m);
                    c++;
                }
            }
        }
        return c;
    }

int main(int argc, char** argv) {
  vector<vector<int>>v{
  {1,1,1,1,1,1,1,0},
  {1,0,0,0,0,1,1,0},
  {1,0,1,0,1,1,1,0},
  {1,0,0,0,0,1,0,1},
  {1,1,1,1,1,1,1,0}
  };
	cout<<closedIsland(v);
}
