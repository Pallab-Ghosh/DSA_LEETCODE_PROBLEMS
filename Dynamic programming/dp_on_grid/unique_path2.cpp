#include <iostream>
#include<vector>
using namespace std;

int dfs(int i,int j,int m,int n,vector<vector<int>>dp,vector<vector<int>>&ans)
{
	if(i==m || j==n)return 0;
	if(dp[i][j]==1)return 0;
	if(i==m-1 and j==n-1)return 1;
	if(ans[i][j]!=-1)return ans[i][j];
	return ans[i][j]=dfs(i+1,j,m,n,dp,ans)+dfs(i,j+1,m,n,dp,ans);
	
}

int dp_with_obst(vector<vector<int>>&v)
{
	int r=v.size();
	int c=v[0].size();
	vector<vector<int>>ans(r+1,vector<int>(c+1,-1));
	return dfs(0,0,r,c,v,ans);
}
int main(int argc, char** argv) {
   vector<vector<int>>v{
   	{0,0,0},
   	{0,1,0},
   	{0,0,0}
   };
   cout<<dp_with_obst(v);
}

