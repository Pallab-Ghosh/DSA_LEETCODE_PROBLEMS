#include <iostream>
#include<stack>
using namespace std;

string remove_outer_most(string s)
{
	stack<int>s1;
	string ans;           
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			if(s1.empty())                //(()())(())
			{
				s1.push(s[i]);
			}
			else
			{
				ans+=s[i];
				s1.push(s[i]);
			}
		}
		
		else
		{
			if(s1.top()=='(')
			{
			    s1.pop();
			    if(s1.size()>0)
			    {
			    	ans+=s[i];
				}
			}
		}
	}
	return ans;
}


int main(int argc, char** argv) {
  
string s="(()())(())";
cout<<remove_outer_most(s);

}
