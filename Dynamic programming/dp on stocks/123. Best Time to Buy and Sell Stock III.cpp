#include <iostream>
#include<vector>
using namespace std;

int fun(vector<int>v,int index,int buy,int cap,vector<vector<vector<int>>>&dp)
{
	if(v.size()==index)
	return 0;
	
	if(dp[index][buy][cap]!=-1)
	return dp[index][buy][cap];
	
	if(cap==0)
	return 0;
	
	
	int profit=0;
	
	if(buy)
	{
profit=max(-v[index]+fun(v,index+1,0,cap,dp),fun(v,index+1,1,cap,dp));
	}
	
	else
	
	{
   profit=max(v[index]+fun(v,index+1,1,cap-1,dp),fun(v,index+1,0,cap,dp));
	}
	return dp[index][buy][cap]=profit;
}

int dp_on_stocks_III(vector<int>v)
{
    //2 given
	vector<vector<vector<int>>>dp(v.size(),vector<vector<int>>(2,vector<int>(3,-1)));//3d array 2 for buy 3 for 0,1,2, transactions.so 3
	return fun(v,0,1,2,dp);
} 

int main(int argc, char** argv) {
	vector<int>v={3,3,5,0,0,3,1,4};
    cout<<dp_on_stocks_III(v); //here said in this problem maximum 2 transactions would be done so capacity will be 2;
}
