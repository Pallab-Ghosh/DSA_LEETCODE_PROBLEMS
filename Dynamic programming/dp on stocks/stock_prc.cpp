#include <iostream>
#include<vector>
using namespace std;

int fun(vector<int>&v,int buy,int ind, vector<vector<vector<int>>>&dp,int cap)
{
	if(v.size()==ind || cap==0) 
	return 0;
	

	if(dp[ind][buy][cap]!=-1)
	  return dp[ind][buy][cap];
	  
	  
	int profit=0;
	if(buy)
	{
		profit=max(-v[ind]+fun(v,0,ind+1,dp,cap),fun(v,1,ind+1,dp,cap));
	}
	else
	{
		profit=max(v[ind]+fun(v,1,ind+1,dp,cap-1),fun(v,0,ind+1,dp,cap));
	}
	return dp[ind][buy][cap]=profit;
}
int stock2(vector<int>v,int k)
{
	    int buy=1;
	    int ind=0;
	    vector<vector<vector<int>>>dp(v.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
     return fun(v,buy,ind,dp,2);
}
int main(int argc, char** argv) {
     vector<int>v{3,2,6,5,0,3};
     cout<<stock2(v,2);
}
