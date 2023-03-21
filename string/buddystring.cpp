#include <iostream>
#include<string.h>
#include<vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool buddyStrings(string s,string goal)
{
	int n=s.length();
	int m=goal.length();
	vector<int>v1(26,0);
	vector<int>v2(26,0);
	if(n!=m)return false;
	int diff=0;
	bool unichar=true;
	for(int i=0;i<n;i++)
	{
		if(s[i]!=goal[i])
		   diff++;
		
		v1[s[i]-'a']++;
		v2[goal[i]-'a']++;
	}
	
	for(int i=0;i<v1.size();i++)
	{
		if(v1[i]!=v2[i])
		return false;
		
		if(v1[i]>1)
        unichar=false;
	}
	
	return diff==2|| (diff==0 && !unichar);
}
int main(int argc, char** argv) {
	string s="ab",t="ab";
	if(buddyStrings(s,t))
	{
		cout<<"they are buddy string";
	}
	else
	{
		cout<<"not buddy string";
	}
}
