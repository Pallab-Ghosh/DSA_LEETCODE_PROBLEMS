#include <iostream>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void dfs(int i,int j,int& count,vector<vector<int>>&v)
{
	//first column visit
	for(int c=0;c<v[i].size();c++)
	{
		if(v[i][c])
		{
			v[i][c]=0;
			count++;
			dfs(i,c,count,v);
		}
	}
	
	//then row visit
	for(int r=0;r<v.size();r++)
	{
		if(v[r][j])
		{
		   v[r][j]=0;
			count++;
			dfs(r,j,count,v);
		}
	}
}





 int countServers(vector<vector<int>>& grid)
  {
  	

 	int ans=0;
 	 for(int i=0;i<grid.size();i++)
 	 {
 	 	for(int j=0;j<grid[i].size();j++)
 	 	{
 	 		if(grid[i][j])
 	 		{
 	 		   	int count=0;
 	 		   	dfs(i,j,count,grid);
 	 		   	if(count>1)
 	 		   	{
 	 		   	  ans+=count;	
				}
			}
		}
	 }
	 return ans;
  }
  
int main(int argc, char** argv) {
	vector<vector<int>>v={{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
	cout<<countServers(v);
}
