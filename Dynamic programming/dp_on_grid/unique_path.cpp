#include <iostream>
#include<string.h>
#include<vector>
using namespace std;

int dfs(int i,int j,int m,int n,vector<vector<int>>&ans)
{
	if(i==m || j==n)return 0;
	if(i==m-1 and j==n-1)return 1;
	if(ans[i][j]!=-1)return ans[i][j];
	
	return ans[i][j]=dfs(i,j+1,m,n,ans)+dfs(i+1,j,m,n,ans);
}
int unique_path(int m,int n)
{
	vector<vector<int>>v(m+1,vector<int>(n+1,-1));
	return dfs(0,0,m,n,v);
}

int main(int argc, char** argv) {
	int m=3,n=3;
	cout<<unique_path(m,n);
}
