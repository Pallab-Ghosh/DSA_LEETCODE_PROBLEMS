#include <iostream>
#include<vector>
using namespace std;


int climbing_stairs(int n,vector<int>&dp)
{
	if(n<=1)
	return 1;
	
	
	if(dp[n]!=-1)
	return dp[n];
	
	return dp[n]=climbing_stairs(n-1,dp)+climbing_stairs(n-2,dp);
}


int main(int argc, char** argv) {
	int n=3;
	vector<int>dp(n+1,-1);
	cout<<climbing_stairs(n,dp);
}
