#include <iostream>
#include<vector>
using namespace std;

int fun(vector<int>&prices,int index,int buy,vector<vector<int>>&dp)
{
	if(prices.size()==index)
	{
		return 0;
	}
	if(dp[index][buy]!=-1)
	 return dp[index][buy];
	 
	 
	int profit=0;
	if(buy)
	{
		profit=max(-prices[index]+fun(prices,index+1,0,dp),fun(prices,index+1,1,dp));
	}
	else 
	{
		profit=max(prices[index]+fun(prices,index+1,1,dp),fun(prices,index+1,0,dp));
	}
	return dp[index][buy]=profit;
}
int dp_on_stocks_II(vector<int>v)
{
	int buy=1;//1 means buy o means not buy
	int index=0;
	vector<vector<int>>dp(v.size(),vector<int>(2,-1));  ///// funtion dependes on index and buy..and buy can either 0 or 1 .so                                                         //matrix will be dp[n][2] 2 because 0 or 1.
	return fun(v,index,buy,dp);
}
int main(int argc, char** argv) { 
   vector<int>v={7,1,5,3,6,4};
   cout<<dp_on_stocks_II(v);
}
