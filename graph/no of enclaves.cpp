#include <iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& grid,int i,int j,int m,int n)
{
	if(i<0 || j<0 || i>m-1 || j>n-1 || grid[i][j]==0 ) 
	   return;
	   
	   
	grid[i][j]=0;
	
	dfs(grid,i,j+1,m,n);
	dfs(grid,i+1,j,m,n);
	dfs(grid,i,j-1,m,n);
	dfs(grid,i-1,j,m,n);
}
int number_of_enclaves(vector<vector<int>>&grid)
{
	int res=0;
	 int m=grid.size();
	 int n=grid[0].size();
	 
	 for(int i=0;i<m;i++)
	 {
	 	if(grid[i][0]==1)
	 	{
	 		dfs(grid,i,0,m,n);
		}
		
		if(grid[i][n-1]==1)
         {
         	dfs(grid,i,n-1,m,n);
		 }		 
	 }
	 
	  
	 for(int i=0;i<n;i++)
	 {
	 	if(grid[0][i]==1)
	 	{
	 		dfs(grid,0,i,m,n);
		}
		
		if(grid[n-1][i]==1)
         {
         	dfs(grid,n-1,i,m,n);
		 }		 
	 }
	 
	 
	 for(int i=0;i<m;i++)
	 {
	 	for(int j=0;j<n;j++)
	 	{
	 		if(grid[i][j]==1)
	 		{
	 			res++;
			 }
		}
	 }
	 return res;
	 
}

int main(int argc, char** argv) {
	 vector<vector<int>>grid = {
	 {0,0,0,0},
	 {1,0,1,0},
	 {0,1,1,0},
	 {0,0,0,0}
	 };
	 
	 cout<<number_of_enclaves(grid);
	 
}
