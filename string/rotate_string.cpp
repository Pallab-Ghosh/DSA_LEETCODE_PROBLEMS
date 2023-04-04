#include <iostream>
#include<string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



bool rotateString(string s,string goal)
{
	bool ans=false;
	string temp;
	if(s==goal)
	{
		return ans=true;
	}
	
	
	for(int i=0;i<s.size();i++)
	{
		temp=s[0];
		s=s.substr(1,s.size())+temp;
		if(s==goal)
		{
		ans=true;
		break;
		}
	}
	return ans;
}
int main(int argc, char** argv) {
  string  s = "abcde"; 
  string goal = "cdeab";
  if(rotateString(s,goal))
  {
  	cout<<"yess";
  }
  else
  {
  	cout<<"false";
  }
}
