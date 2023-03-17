#include <iostream>
using namespace std;

int knapsack(int values[],int weight[],int w,int n)
{
	int dp[n+1][w+1];
	
	for(int i=0;i<n+1;i++)
	{
		dp[i][0]=0;
	}
	
	for(int j=0;j<w+1;j++)
	{
		dp[0][j]=0;
	}
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<w+1;j++)
		{
			if(weight[i-1]<=j)
			{
				dp[i][j]=max(values[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][w];
}





int main(int argc, char** argv) {
	int value[]={1,2,3};
	int weight[]={4,5,1};
	int w=4;
	cout<<knapsack(value,weight,w,3);
}
