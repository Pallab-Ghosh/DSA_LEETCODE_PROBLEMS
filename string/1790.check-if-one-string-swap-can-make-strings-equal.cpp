#include <iostream>
#include<algorithm>
using namespace std;

bool solu(string s1,string s2)
{
	if(s1.length()!=s2.length())
	return false;
	
	int cnt=0;
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]!=s2[i])
		{
			cnt++;
		}
	}
	
	
	 
	 sort(s1.begin(),s1.end());
	 sort(s2.begin(),s2.end());
	 
	 if(s1!=s2)
	 {
	 	return false;
	 }
	 
	 if(cnt==0 || cnt==2)
	 {
	 	return true;
	 }
	 return false;
}

bool areAlmostEqual(string s1,string s2)
{
	return solu(s1,s2);
}


int main(int argc, char** argv) {
	string s1="aab";
	string s2="baa";
	if(areAlmostEqual(s1,s2))
	{
		cout<<"equal";
	}
	else
	{
		cout<<"not equal";
	}
}
