#include <iostream>
#include<string.h>
using namespace std;


string right_rotation(string s,int d)
{
	int n=s.length();
	string temp1;
     temp1=s.substr(n-d,d); //o(n)
	
	s.resize(n-d); //o(n)
	
	for(int i=0;i<s.length();i++)
	  temp1.push_back(s[i]); //o(n)
	
	return temp1;
}


string left_rotation(string s,int d)
{
	int n=s.length();
	string temp1;
	for(int i=d;i<n;i++)
	{
		temp1.push_back(s[i]);
	}
	
	
      for(int i=0;i<d;i++)
      {
      	temp1.push_back(s[i]);
	  }
      
      
  return temp1;
}

int main(int argc, char** argv) {
	 string s="GeeksforGeeks";
	 int d=2;
	 string ans1=right_rotation(s,d);
	 cout<<ans1;
	 
	 cout<<endl;
	 
	 ans1=left_rotation(s,d);
	 cout<<ans1;
	 
}
