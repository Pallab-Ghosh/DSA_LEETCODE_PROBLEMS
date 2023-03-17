#include <iostream>
#include<string.h>
using namespace std;

bool is_subsequence(string s,string t)
{
	string temp;
	int l1=s.length();
	int l2=t.length();
	int i=0;
	int j=0;
	while(i<l1 and j<l2)
	{
		if(s[i]==t[j])
		{
			temp.push_back(s[i]);
			i++;
		}
		
		j++;
	}
	
	if(temp==s)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char** argv) {
	
	string s1="abc";
	string s2="ahbgdc";
	 if(is_subsequence(s1,s2))
	 {
	 	cout<<"is subsequence";
	 }
	 else
	 {
	 	cout<<"not";
	 }
}
