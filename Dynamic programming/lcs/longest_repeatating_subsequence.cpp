#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int repeating_subsequence(string s1)
{
	string s2=s1;
	int dp[s1.length()+1][s2.length()+1];
	int l1=s1.length();
	int l2=s2.length();
	for(int i=0;i<l1+1;i++)
	{
		dp[i][0]=0;
	}
	
	for(int i=0;i<l2+1;i++)
	{
		dp[0][i]=0;
	}
	
	for(int i=1;i<l1+1;i++)
	{
		for(int j=1;j<l2+1;j++)
		{
			if(s1[i-1]==s2[j-1] and i!=j)
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[l1][l2];
}
int main(int argc, char** argv) {
	string s1="aabebcdd";
	cout<<repeating_subsequence(s1);
}
