#include <iostream>
#include<vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int& c)
{
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1)
     return;

     grid[i][j]=2;
     c++;
     dfs(grid,i-1,j,n,m,c);
     dfs(grid,i+1,j,n,m,c);
     dfs(grid,i,j+1,n,m,c);
     dfs(grid,i,j-1,n,m,c);
}
  
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int c=0;
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,n,m,c);
                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
int main(int argc, char** argv) {
     vector<vector<int>>v{
	 {0,0,1,0,0,0,0,1,0,0,0,0,0},
	 {0,0,0,0,0,0,0,1,1,1,0,0,0},
	 {0,1,1,0,1,0,0,0,0,0,0,0,0},
	 {0,1,0,0,1,1,0,0,1,0,1,0,0},
	 {0,1,0,0,1,1,0,0,1,1,1,0,0},
	 {0,0,0,0,0,0,0,0,0,0,1,0,0},
	 {0,0,0,0,0,0,0,1,1,1,0,0,0},
	 {0,0,0,0,0,0,0,1,1,0,0,0,0}
	 };
	 cout<<maxAreaOfIsland(v);
}
