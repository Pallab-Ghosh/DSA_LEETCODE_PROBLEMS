#include <iostream>
#include<string.h>
#include<unordered_map>
using namespace std;
 int longestSubstring(string s, int k) {
        if(s.length()==0 || s.length()<k)
          return 0;

        if(k<=1)
        {
            return s.length();
        }
        unordered_map<char,int>mp;

       for(char c:s)
         mp[c]++;

       int l=0;
       while(l<s.length() && mp[s[l]]>=k)
          l++;

        if(l>=s.length()-1)
          return l;

        int left=longestSubstring(s.substr(0,l),k);
        while(l<s.length() && mp[s[l]]<k)
          l++;
         
          int right=l<s.length()?longestSubstring(s.substr(l),k):0;
         
        return max(left,right);
    }
int main(int argc, char** argv) {
	string s="aaabb";
	cout<<longestSubstring(s,3);
}
