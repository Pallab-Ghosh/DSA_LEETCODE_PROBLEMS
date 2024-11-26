#include <iostream>
#include<unordered_map>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int get_longest_string_with_k(string s , int k)
{
	int ans = 0 , n =s.size() , start=0 , end =0;
	unordered_map<char,int>mp;
	
	
	while(end < n)
	{
		char ch =s[end];
		mp[ch]++;
		
		while(mp.size() > k)
		{
			char del_char = s[start];
			mp[del_char]--;
			 
			if(mp[del_char] == 0)
			   mp.erase(del_char);
			   
			start++;
		}
		ans = max(ans , end - start + 1);
		end++;
	}
	return ans;
}


int main(int argc, char** argv) {
	
	string s="aabbcc" ; int k =2;
	int res = get_longest_string_with_k(s,k);
	cout<<res;
	
}
