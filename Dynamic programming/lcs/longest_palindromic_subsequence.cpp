#include <iostream>
#include<string.h>

using namespace std;
int lps(string s1,string s2,int l1,int l2)
{
	int dp[l1+1][l2+1];
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
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	return dp[l1][l2];
}



int main(int argc, char** argv)
   {
	
	string s1="pallab";
	string s2;
	for(int i=s1.length()-1;i>=0;i--)
	{
		s2.push_back(s1[i]);
	}
	cout<<lps(s1,s2,s1.length(),s2.length());
}
