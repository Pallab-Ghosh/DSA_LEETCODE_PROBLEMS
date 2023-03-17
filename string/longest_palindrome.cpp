#include <iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

int longest_palindrome_length(string s)
{
	int count=0;
	unordered_map<char,int>m;
	for(int i=0;i<s.length();i++)
	{
		m[s[i]]++;
	}
	
	for(auto it:m)
	{
		if(it.second %2==0)
		{
			count++;
		}
	}
	
	return (count>1)?s.length()-count+1:s.length();
}
int main(int argc, char** argv) {
	string s="abccccdd";
	cout<<longest_palindrome_length(s);
}
