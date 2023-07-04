#include <iostream>
#include<map>
#include<set>
using namespace std;

    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        int ans = 0;
        map<string,int>map;
        int i=0;
        for(i = 0;i<= n - minSize;i++)
		 {
            map[s.substr(i,minSize)]++;   //o(nlogn)
         }
        
        
        

        for(auto x:map) //abcde 2 3 3 
          {
          	string temp=x.first;
            set<char>substring(temp.begin(),temp.end());//for unique characters in the substring
            if(substring.size() <= maxLetters) {
                ans = max(ans,x.second);
            }
        }    
        return ans;
    }

int main(int argc, char** argv) {
	string s="aababcaab";
	int  maxLetters = 2, minSize = 3, maxSize = 4;
	cout<<maxFreq(s,maxLetters,minSize,maxSize);
}
