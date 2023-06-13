#include <iostream>
#include<vector>
using namespace std;

int fun(int i,int j,int m,int n,vector<vector<int>>&v,vector<vector<int>>&dp)
{
	if(i==m&&j==n)
	   return v[i][j];
	   
	   if(i>m || j>n)
	   return INT_MAX;
	   
	   if(dp[i][j]!=-1)
	   {
	   	return dp[i][j];
	   }
	   return dp[i][j]=v[i][j]+min(fun(i,j+1,m,n,v,dp),fun(i+1,j,m,n,v,dp));
}

int min_path_sum(vector<vector<int>>&v,vector<vector<int>>&dp)
{
	int m=v.size()-1;
	int n=v[0].size()-1;
	return fun(0,0,m,n,v,dp);
}
int main(int argc, char** argv) {
	vector<vector<int>>v{
	{1,3,1},{1,5,1},{4,2,1}
	};
	vector<vector<int>>dp(v.size(),vector<int>(v[0].size(),-1));
	cout<<min_path_sum(v,dp);
}
