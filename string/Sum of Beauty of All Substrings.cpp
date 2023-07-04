#include <iostream>
#include<string.h>
#include<unordered_map>

using namespace std;

int result(unordered_map<char,int>&mp)
{
	int mn=INT_MAX;
	int mx=-1;
	
	for(auto it:mp)
	{
		mx=max(mx,it.second);
		
			mn=min(mn,it.second);
		
	}
	return mx-mn;
}

int beautySum(string s)
{
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		unordered_map<char,int>mp;
		for(int j=i;j<s.size();j++)
		{
			mp[s[j]]++;
			ans+=result(mp);
		}
	}
	return ans;
}

int main(int argc, char** argv) {
	string s="aabcbaa";
	cout<<beautySum(s);
}
