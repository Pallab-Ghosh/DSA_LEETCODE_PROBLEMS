#include <iostream>
#include<string.h>
using namespace std;
int dp[4][5];
int knapsack(int values[],int weight[],int w,int n)
{
	if(n==0 || w==0)
	{
		return 0;
	}
	
	if(dp[n][w]!=-1)
	{
		return dp[n][w];
	}
	
	else if(weight[n-1]<=w)
	{
		return dp[n][w]=max(values[n-1]+knapsack(values,weight,w-weight[n-1],n-1),knapsack(values,weight,w,n-1));
	}
	else
	{
	    return dp[n][w]=knapsack(values,weight,w,n-1);
	}
}

int main(int argc, char** argv) {
	int values[]={1,2,3};
	int weight[]={4,5,1};
	int w=4;
	memset(dp,-1,sizeof(dp));
	cout<<knapsack(values,weight,w,3);
}
