#include <iostream>
#include<vector>
using namespace std;

  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
         string s1="";
        string s2="";

        for(auto x: word1)
        {
            s1+=x;
        }
        for(auto y: word2)
        {
            s2+=y;
        }
        if(s1==s2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

int main(int argc, char** argv) {
	vector<string>word1={"ab","c"};
	vector<string>word2={"a","bc"};
	if(arrayStringsAreEqual(word1,word2))
	{
		cout<<"equal";
	}
	else
	{
		cout<<"not equal";
	}
}
