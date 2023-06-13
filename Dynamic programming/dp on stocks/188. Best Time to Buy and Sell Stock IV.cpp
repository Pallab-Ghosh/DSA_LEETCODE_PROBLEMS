#include <iostream>
#include<vector>
using namespace std;

 int fun(vector<int>& prices,int ind,int buy,int cap,vector<vector<vector<int>>>&dp)
    {
     
          if(ind==prices.size())return 0;
          if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        if(cap==0)return 0;
           int profit=0;

          if(buy)
          {
              profit=max(-prices[ind]+fun(prices,ind+1,0,cap,dp),fun(prices,ind+1,1,cap,dp));
          }
          else
          {
              profit=max(prices[ind]+fun(prices,ind+1,1,cap-1,dp), fun(prices,ind+1,0,cap,dp));
          }
       return dp[ind][buy][cap]=profit;
    }
    
    int maxProfit(int k, vector<int>& prices)
	 {
         vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));//k transactions so dp[n][2][k+1]=t.c
        return fun(prices,0,1,k,dp);
    }

int main(int argc, char** argv) {
	return 0;
	vector<int>v={2,4,1};
	int k=2;
	cout<<maxProfit(k,v);
	
}
