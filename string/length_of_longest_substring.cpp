#include <iostream>
#include<unordered_map>
#include<string.h>
using namespace std;

int length_of_longest_substring(string s,int len)
{
	int i=0,j=0;
	int res=0;
	int temp=0;
	unordered_map<char,int>m;
	
	while(i<len)
	{
		char j_char=s[j];
		m[j_char]++;
		while(m[j_char]>1)
		{
			char temp_char=s[i];
			m[temp_char]--;
			i++;
		}
		temp=j-i+1;
		res=max(res,temp);
		j++;
	}
	return res;
}

int main(int argc, char** argv) {
	string s="abcabcbb";
	cout<<length_of_longest_substring(s,s.length());
}
