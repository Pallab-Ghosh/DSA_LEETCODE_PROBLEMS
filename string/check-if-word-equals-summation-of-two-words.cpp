#include <iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

bool solu(string firstWord,string secondWord,string targetWord)
{
     string firstVal = ""; 
        string secondVal = "", targetVal= "";

        for(auto x : firstWord)
            firstVal += to_string(x - 'a');

        for(auto x : secondWord)
            secondVal += to_string(x - 'a');

        for(auto x : targetWord)
            targetVal += to_string(x - 'a');
            
        //converting string to integer using stoi()
        if(stoi(firstVal) + stoi(secondVal) == stoi(targetVal))
            return true;
        return false;
}

bool isSumEqual(string s1,string s2,string targetWord)
{
	return solu(s1,s2,targetWord);
}


int main(int argc, char** argv) {
	string s1="acb",s2="cba",target="cdb";
    if(isSumEqual(s1,s2,target))
    {
    	cout<<"it is equal";
	}
	else
	{
		cout<<"not equal";
	}
}
