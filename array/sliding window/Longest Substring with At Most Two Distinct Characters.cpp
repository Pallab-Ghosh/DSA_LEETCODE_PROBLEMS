#include <iostream>
#include<unordered_map>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int lengthOfLongestSubstringTwoDistinct(string s)
{
	int ans=0;
	unordered_map<char,int>mp;
	int start=0 ;
	int end =0 ;
	int n = s.size();
	
	
	
	while(end < n)
	{
		
		char ch = s[end];
		mp[ch]++;
		
		
		while(mp.size()>2)
		{
			char del_char = s[start];
		 
			mp[del_char]--;
			
			  if (mp[del_char] == 0)
			   {  // Remove character completely if its frequency is 0.
                mp.erase(del_char);
              }
			start++;
		}
		
		ans = max(ans , end-start+1);
		end++;
		
	}
	return ans;
}


int main(int argc, char** argv) {
	string s="ccaabbb";
	int res = lengthOfLongestSubstringTwoDistinct(s);
	cout<<res;
}
