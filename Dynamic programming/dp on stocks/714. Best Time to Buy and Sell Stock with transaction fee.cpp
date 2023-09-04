#include <iostream>
#include<vector>
using namespace std;

 vector<int>v={1,3,7,5,10,3};
 
vector<vector<int>>dp(v.size(),vector<int>(2,-1));

//vector<vector<vector<int>>>dp(v.size(),vector<vector<int>>(2,vector<int>(3,-1)));

int solu(vector<int>v,int ind,int buy,int fee)
{
	if(ind>v.size()-1)
	return 0;
	
	if(dp[ind][buy]!=-1)
	return dp[ind][buy];
	
	int profit=0;
	if(buy)
	{
		profit=max(-v[ind]+solu(v,ind+1,0,fee),solu(v,ind+1,1,fee));
	}
	else
	{
		profit=max(v[ind]-fee+solu(v,ind+1,1,fee),solu(v,ind+1,0,fee));
	}
	return dp[ind][buy]=profit;
}


int ans( vector<int>v)
{

	int fee=3;
	int buy=1;
   return solu(v,0,buy,fee);
}
int main(int argc, char** argv) {
 
  cout<<ans(v);
}
