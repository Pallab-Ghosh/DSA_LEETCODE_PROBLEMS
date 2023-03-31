#include <iostream>
#include<vector>
using namespace std;

int climbing_stairs(int n)
{
		 if(n<=2)
         return n;
         
        vector<int> dp(n+1);
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
         dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
}
int main(int argc, char** argv) {
	int n=3;
       cout<<climbing_stairs(n);
}
