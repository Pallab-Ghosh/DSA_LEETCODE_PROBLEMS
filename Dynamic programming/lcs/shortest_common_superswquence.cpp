#include <iostream>
#include<string.h>
using namespace std;

int shortest_common_supersequence(string s1,string s2,int l1,int l2)
{
	int dp[l1+1][l2+1];
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
	return l1+l2-dp[l1][l2];
}
int main(int argc, char** argv) {
	string  str1 = "AGGTAB",  str2 = "GXTXAYB";
	cout<<shortest_common_supersequence(str1,str2,str1.length(),str2.length());
}
