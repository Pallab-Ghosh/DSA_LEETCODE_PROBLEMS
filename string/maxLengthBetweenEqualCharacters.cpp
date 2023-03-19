#include <iostream>
#include<string.h>
#include<unordered_map>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


 int maxLengthBetweenEqualCharacters(string s)
  {
 	int b=-1;
 	unordered_map<char,vector<int>>m;
 	
 	for(int i=0;i<s.length();i++)
 	{
 		m[s[i]].push_back(i);
	 }
	 
 	for(auto i:m)
 	{
 		vector<int>v=i.second;
 		int n=v.size();
 		
 		if(n>1)
 		{
 			b=max(b,v[n-1]-v[0]-1);
		}
	}
	return b;
  }
int main(int argc, char** argv) {
	string s="abca";
	cout<<maxLengthBetweenEqualCharacters(s);
}
