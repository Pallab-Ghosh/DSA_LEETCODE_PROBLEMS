#include <iostream>
#include<unordered_map>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int numberOfSpecialSubstrings(string s)
{
	unordered_map<char,int>mp;
	int start=0 , end=0 , res=0;
	
	while(end < s.size())
	{
		char end_ele = s[end];
		mp[end_ele]++;
		
		while(mp[end_ele] > 2)
		{
			char delete_ch = s[start];
			mp[delete_ch]--;
			
			if(mp[delete_ch] == 0)
			  mp.erase(delete_ch);
			  
			  start++;
		}
		
		res = res + (end-start+1);
		end++;
	}
	return res;
	
}

int main(int argc, char** argv) {
	string s ="abcd";
	cout<<numberOfSpecialSubstrings(s);
	
	
}
