#include <iostream>
#include<string.h>
#include<vector>
#include<set>
using namespace std;

vector<string>stringMatching(vector<string>words)
{
	vector<string>ans;
	set<string>s;
	for(int i=0;i<words.size();i++)
	{
		for(int j=0;j<words.size();j++)
		{
			if(i!=j and words[i].find(words[j]) !=-1)
			{
				ans.push_back(words[j]);
			}
		}
	}
	
	for(int i=0;i<ans.size();i++)
	{
		s.insert(ans[i]);
	}
	
	ans.clear();
	
	for(auto it:s)
	{
		ans.push_back(it);
	}
	return ans;
}


int main(int argc, char** argv) {
	vector<string>words {"mass","as","hero","superhero"};
	vector<string>temp=stringMatching(words);
	for(int i=0;i<temp.size();i++)
	{
		cout<<temp[i]<<" ";
	}
}
