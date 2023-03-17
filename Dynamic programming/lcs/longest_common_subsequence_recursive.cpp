#include <iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int lcs(string s1,string s2,int l1,int l2)
{
	if(l1==0 || l2==0)return 0;
	
	if(s1[l1-1]==s2[l2-1])
	{
		return 1+lcs(s1,s2,l1-1,l2-1);
	}
	else
	{
		return max(lcs(s1,s2,l1,l2-1),lcs(s1,s2,l1-1,l2));
	}
}


int main(int argc, char** argv) {
  string s1="pallab";
  string s2= "alb";
  cout<<lcs(s1,s2,s1.length(),s2.length());
}
