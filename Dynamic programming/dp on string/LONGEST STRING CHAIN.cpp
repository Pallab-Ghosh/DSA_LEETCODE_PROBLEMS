#include <iostream>
#include<string.h>
#include<vector>
#include<map>
#include<ALGORITHM>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
  static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
int main(int argc, char** argv) {
	
	
	 vector<string>words {"a","b","ba","bca","bda","bdca"};
	 
	  sort(words.begin(), words.end(), compare);
	  
       map<string, int> dp;
        int res = 0;
        
        for (string w : words)
         {
            for (int i = 0; i < w.length(); i++) 
            {
                string pre = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
                cout<<w<<" "<<pre<<endl;
            }
            res = max(res, dp[w]);
        }
        
        cout<<endl;
        for(auto it:dp)
        {
        	cout<<it.first<<" "<<it.second<<endl;
        	
		}
}
