#include <iostream>
#include<string.h>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
      static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

int longeststringchain(vector<string>s)
{
	int n=s.size();
	int res=0;
	sort(s.begin(),s.end(),compare);
	unordered_map<string,int>mp;
	
	for(string w:s)
	{
		for(int i=0;i<w.length();i++)
		{
			string temp=w.substr(0,i)+w.substr(i+1);
			mp[w]=max(mp[w],mp.find(temp)==mp.end()?1:mp[temp]+1);
		}
		res=max(res,mp[w]);
	}
	return res;
}
int Main(int argc, char** argv) {
	vector<string>s={"xbc","pcxbcf","xb","cxbc","pcxbc"};
	cout<<longeststringchain(s);
}