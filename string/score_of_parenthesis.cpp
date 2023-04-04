#include <iostream>
#include<string.h>
#include<Math.h>
using namespace std;

int count_string(string s)
{
	char prev='(';
	int res=0;
	int depth=0;
	for(char temp:s)
	{
		if(temp=='(')
		  depth++;
		  
		  else 
		     depth--;
		     if(temp==prev)
		     {
		     	res+=pow(2,depth);
			 }
			 prev=temp;
	}
	return res;
}

int main(int argc, char** argv) {
	 string s="()()";
	 cout<<count_string(s);
}
