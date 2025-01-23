#include <iostream>
#include<unordered_map>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;

int numKLenSubstrNoRepeats(string s , int k)
{
	if(k < s.size())
	  return 0;
	  
	unordered_map<char,int>mp;
	int start=0,end=0,res=0;
	
	while(end<s.size())
	{
		char ch = s[end];
		mp[ch]++;
		
		while(mp.size() > k || mp[ch] > 1)
		{
			char del_ch = s[start];
			mp[del_ch]--;
			
			if(mp[del_ch] == 0)
			  mp.erase(del_ch);
			  
			start++;
		}
		if(mp.size() == k)
		 res++;
		 
		end++;
	}
	return res;
}

int main(int argc, char** argv) {
	string s ="havefunonleetcode";
	int k=5;
	cout<<numKLenSubstrNoRepeats(s,k);
}