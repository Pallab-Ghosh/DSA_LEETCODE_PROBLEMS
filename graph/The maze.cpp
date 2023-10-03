#include <iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;


bool has_path(vector<vector<int>>&maze, vector<int>start,vector<int>end )
{
	int n=maze.size();
	int m=maze[0].size();
	int vis[n][m];
	
	queue<pair<int,int>>q;
	memset(vis,0,sizeof(vis));
	q.push({start[0],start[1]});
	//vector<vector<int>>vis(n,vector<int>(m,0));


	vis[start[0]][start[1]]=1;
	
	vector<int>dx={-1,0,1,0};
	vector<int>dy={0,1,0,-1};
	
	
	
	while(!q.empty())
	{
		auto start=q.front();
		int start_x=start.first;
		int start_y=start.second;
		q.pop();
		
		if(start_x==end[0] && start_y==end[1])
		return true;
		
		
		for(int index=0;index<4;index++)
		{
			int new_x=start_x;
			int new_y=start_y;
			
			while(new_x>=0 && new_x<n && new_y>=0 && new_y<m && maze[new_x][new_y]==0)
			{
				new_x+=dx[index];
				new_y+=dy[index];
			}
			
			//new_x and new_y will be either on 1 or in border
			
			new_x-=dx[index];
			new_y-=dy[index];
			
			if(vis[new_x][new_y]==0)
			{
				vis[new_x][new_y]=1;
				q.push({new_x,new_y});
			}
			
		}
		
	}
	return false;
}


int main(int argc, char** argv) {
   vector<vector<int>>grid=
   {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
   vector<int>start={0,4};
   vector<int>end={4,4};
   
   if(has_path(grid,start,end))
   {
   	 cout<"has path";
   }
   else
   {
   	 cout<<"not pqth";
   }
} 
