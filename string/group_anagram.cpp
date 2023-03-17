#include <iostream>
#include<string.h>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

 vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	unordered_map<string,vector<string>>mp;
	vector<vector<string>>ans;
	if(strs.size()==0)
	     return {};
	
	for(int i=0;i<strs.size();i++)
	{
		string temp=strs[i];
	    sort(temp.begin(),temp.end());
	    mp[temp].push_back(strs[i]);
	}

    for(auto it:mp)
    {
    	ans.push_back(it.second);
	}
	return ans;
}

int main(int argc, char** argv) 
{
  vector<string> strs {"eat","tea","tan","ate","nat","bat"};
  vector<vector<string>>s1=groupAnagrams(strs);
  
  for(int i=0;i<s1.size();i++)
  {
  	for(int j=0;j<s1[i].size();j++)
  	{
  	  	cout<<s1[i][j]<<" ";
	}
	cout<<endl;
  }
}
