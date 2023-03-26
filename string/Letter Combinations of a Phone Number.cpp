#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void sol(int i,	string &digits,string& temp,vector<string>&ans,unordered_map<char,string>&mp)
{
	if(i==digits.size())
	{
		ans.push_back(temp);
		return;
	}
	
	string str=mp[digits[i]];
	for(int j=0;j<str.size();j++)
	{
		temp.push_back(str[j]);
		sol(i+1,digits,temp,ans,mp);
		temp.pop_back();
	}
}
int main(int argc, char** argv) {
	string digits="23";
    string temp;
    vector<string>ans;
    
	if(digits.size()>0)
	{
		unordered_map<char,string>m;
		m['2']="abc";
		m['3']="def";
		m['4']="ghi";
		m['5']="jkl";
		m['6']="mno";
		m['7']="pqrs";
		m['8']="tuv";
		m['9']="wxyz";
		sol(0,digits,temp,ans,m);
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
		//return ans;
	}
	//return ans;
}
