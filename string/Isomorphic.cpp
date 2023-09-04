#include <iostream>
#include<string.h>
#include<unordered_map>
using namespace std;


  bool isIsomorphic(string s, string t) {
      unordered_map <char,int> mp1,mp2;
        int n=s.size();
        for(int i=0;i<n;i++)
		{
            if(mp1[s[i]]!=mp2[t[i]]) 
                return false;
                
            mp1[s[i]]=i+1;
            mp2[t[i]]=i+1;
        }
        return true;
    }
int main(int argc, char** argv) {
	string s="foo";
	string t="bar";
	if(isIsomorphic(s,t))
	{
		cout<<"yess";
	}
	else
	{
		cout<<"not";
	}
	

}
