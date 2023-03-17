#include <iostream>
#include<string.h>
using namespace std;

int distinct_subsequence(string s,string t,int i,int j)
{
	if(j<0)return 1;
	if(i<0)return 0;
	
	if(s[i-1]==t[j-1])
	{
		return distinct_subsequence(s,t,i-1,j-1)+distinct_subsequence(s,t,i-1,j);
	}
	else
	{
		return distinct_subsequence(s,t,i-1,j);
	}
	
}

  int main(int argc, char** argv) {
	string s="rabbbit";
	string t="rabbit";
	cout<<distinct_subsequence(s,t,s.size(),t.size());
}
