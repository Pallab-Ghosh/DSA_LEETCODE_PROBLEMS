#include <iostream>
#include<string.h>
using namespace std;


int isPrefixOfWord(string sentense,string searchword)
{
	int c=1;
	bool f=false;
	
	if(sentense.substr(0,searchword.size())==searchword)
	  return c;
	  
	  for(int i=0;i<sentense.size();i++)
	  {
	  	 if(sentense[i]==' ')
	  	 {
	  	 	c++;
	  	 	if(sentense.substr(i+1,searchword.size())==searchword)
	  	 	{
	  	 		f=true;
	  	 		break;
			}
		 }
	  }
	  if(f==true && c>1)
	  return c;
	  
	  return -1;
}
int main(int argc, char** argv) {
	string sentense = "i love eating burger";
	string searchWord = "burg";
	cout<<isPrefixOfWord(sentense,searchWord);
}
