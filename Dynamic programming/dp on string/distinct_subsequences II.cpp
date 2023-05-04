#include <iostream>
#include<string.h>
#include<vector>
using namespace std;

int dp[2001];
    int mod = 1e9+7;
    int fn(string &s, int i)
    {
        if(i==s.length())
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        vector<int> vis(26,0);
        int  ans = 0;

        for(int j=i;j<s.length();j++)
        {
            if(vis[s[j]-'a'])
                continue;

            vis[s[j]-'a'] = 1;
            ans = (ans + 1 + fn(s,j+1))%mod;
        }

        return dp[i] = ans;
    }
    
int main(int argc, char** argv) {
	 string s="abc";
	 memset(dp,-1,sizeof(dp));
	 cout<<fn(s,0);
}
