#include <iostream>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int solve(int n,vector<int>&dp)
{
	if(n<=1)
	return 1;
	
	if(dp[n]!=0)
	return dp[n];
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=solve(i-1,dp)*solve(n-i,dp);
	}
	return dp[n]=ans;
}
int main(int argc, char** argv) {
	int n=3;
	vector<int>dp(4,0);
	int ans=0;
	ans=solve(n,dp);
	cout<< ans;
}
