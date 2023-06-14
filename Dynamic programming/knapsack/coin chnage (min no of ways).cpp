#include <iostream>
#include<vector>
using namespace std;

  int solu(vector<int>& coins,int n,int amount,vector<vector<int>>&dp)
   {
     
       if(amount==0)
        return 0;

     if(n==0 && amount>0) 
         return INT_MAX-1;

       if(dp[n][amount]!=-1)
         return dp[n][amount];

        if(coins[n-1]<=amount)
        {
          return dp[n][amount]=min(1+solu(coins,n,amount-coins[n-1],dp),solu(coins,n-1,amount,dp));
        } 

        else
        {
           return dp[n][amount]=solu(coins,n-1,amount,dp);
        }
   } 



    int coinChange(vector<int>& coins, int amount) {
      
        int n=coins.size();
        if(amount == 0) return 0;
       if(coins.size()==1 && coins[0]>amount)
           return -1;

          vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
         int ans=solu(coins,n,amount,dp);
         return ans>INT_MAX-1?-1:ans;
    }
    
    int main()
    {
    	vector<int>coins{2};
    	int amount=3;
    	cout<<coinChange(coins,amount);
	}
