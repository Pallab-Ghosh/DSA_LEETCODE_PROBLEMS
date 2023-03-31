#include <iostream>
#include<string.h>
#include<vector>
using namespace std;


int func(int i,string s, vector<int>&dp)
{
 if(i==s.length())
          return 1;

        if(i==s.length()-1)
        {
            if(s[i]>='1' && s[i]<='9')
            return 1;

            return 0;
        }

        if(s[i]=='0')
          return 0;

        if(dp[i]!=-1)
            return dp[i];

        int p1=0,p2=0;

        if(s[i]>='1' && s[i]<='9')
            p1 = func(i+1,s,dp);

        int x=0;

        x = (s[i]-'0')*10 + (s[i+1]-'0');

        if(x>=1 && x<=26)
            p2 = func(i+2,s,dp);

        return dp[i]=p1+p2;
}


int main(int argc, char** argv) {
     string s="226";
     vector<int>dp(s.size(),-1);
     cout<<func(0,s,dp);
}
