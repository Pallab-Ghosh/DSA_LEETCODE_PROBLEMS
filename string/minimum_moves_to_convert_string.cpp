#include <iostream>
#include<string.h>
using namespace std;


int min_moves(string s)
{
	int c=0;
	int i=0;
	while(i<s.length())
	{
		if(s[i]=='X')
		{
			c++;
			i+=3;
		}
		else
		{
			i++;
		}
	}
	return c;
}
int main(int argc, char** argv) {
	string s="XX0X";
	cout<<min_moves(s);
}
