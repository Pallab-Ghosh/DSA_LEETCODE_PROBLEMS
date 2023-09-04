#include <iostream>
using namespace std;

  bool isValidSerialization(string s) 
  {
  	int node=1;
  	s+=',';
  	for(int i=0;i<s.length();i++)
  	{
  		if(s[i]!=',')
  		{
  			continue;//comma seperated values of nodes
		}
		
		node--;//after taking each node decrease value of left nodes
		if(node<0)
		 return false;
		 
		if(s[i-1]!='#')
		{
			node+=2;//if current node is not null means it will 2 childs si increase by 2;
		}
	}
	return node==0;
  }
int main(int argc, char** argv) {
	string s="9,3,4,#,#,1,#,#,2,#,6,#,#";
	if(isValidSerialization(s))
	{
		cout<<"it is preorder";
	}
	else
	{
		cout<<"not";
	}
}
