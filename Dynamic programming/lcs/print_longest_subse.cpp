#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;

string lcs(string s1,string s2,int l1,int l2)
{
	int dp[l1+1][l2+1];
	string ans;
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
			if(s1[l1-1]==s2[l2-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	int i=l1;
	int j=l2;
	while(i>0 and j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			ans.push_back(s1[i-1]);
			i--;
			j--;
		}
		
		else if(dp[i-1][j]>dp[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	cout<<ans<<endl;
	reverse(ans.begin(),ans.end());
	return ans;
}


int main(int argc, char** argv) {
	string s1="pallab";
	string s2="pab";
	string temp=lcs(s1,s2,s1.length(),s2.length());
	cout<<temp;
}
