#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int fun(string s1)
{
	string s2=s1;
	reverse(s2.begin(),s2.end());
	int l1=s1.length(),l2=s2.length();
	vector<vector<int>>dp(l1+1,vector<int>(l2+1));
	for(int i=0;i<l1+1;i++)
	{
		dp[i][0]=0;
	}
	
	for(int j=0;j<l2+1;j++)
	{
		dp[0][j]=0;
	}
	
	for(int i=1;i<l1+1;i++)
	{
		for(int j=1;j<l2+1;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	int ans=s1.length()-dp[l1][l2];
	return ans;
}
int main(int argc, char** argv) {
	string s="aebcbda";
	cout<<fun(s);
}
