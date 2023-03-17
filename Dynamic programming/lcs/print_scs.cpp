#include <iostream>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
string scs(string s,string t)
{
	 int m = s.size() , n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 ||j==0) dp[i][j] = 0;
                else if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max( dp[i-1][j] , dp[i][j-1] );
                }
            }

        }
        string ans = "";
        int i = m , j = n;
        while(i>0 && j>0){
            if( s[i-1] == t[j-1] ){
                ans += s[i-1];
                i--;
                j--;
            }
            else if( dp[i-1][j] > dp[i][j-1] ){
                ans += s[i-1];
                i--;
            }
            else{
                ans += t[j-1];
                j--;
            }
        }
        while(i>0){
            ans += s[i-1];
            i--;
        }
        while(j>0){
            ans += t[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
}

int main(int argc, char** argv) {
	string temp=scs("acbcf","abcdaf");
	cout<<temp;
}
