#include <iostream>
#include<map>
#include<string.h>
#include<unordered_map>
using namespace std;
bool valid_anagram(string s,string t)
{
	 int count_s[26]={0};
        int count_t[26]={0};
        int index_s=0, index_t=0;
        int ls= s.length(), lt= t.length();

        for(char ch : s)
        {
            index_s= ch - 'a'; // character to integer.
            cout<<index_s<<endl;
            count_s[index_s]++;
        }
        
        cout<<endl;
        cout<<endl;
        
        for(char ch : t)
        {
            index_t = ch - 'a'; // it convert numeric character in to integer 
            cout<<index_t<<endl;
            count_t[index_t]++;
        }
        
        for(int i=0;i<26;i++)
        {
        	cout<<count_s[i]<<" "<<count_t<<endl;
		}
        
        // checking equality of arrays
        for(int i=0; i<26; i++)
        {
            if(count_s[i] != count_t[i])
            return false;
        }
        return true;
  

}

int main(int argc, char** argv) {
	string s1="rat";
	string s2="atr";
	if(valid_anagram(s1,s2))
	{
		cout<<"yes";
	}
	else
	{
		cout<<"not anagram";
	}
}
