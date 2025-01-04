#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        int end = 0 , start = 0 , res = 0 ;

        unordered_map<char,int>ch_map;
        unordered_map<string,int>str_map;

        while(end < s.size())
        {
             char ch = s[end];
             ch_map[ch]++;


             while(end - start + 1 > minSize || ch_map.size() > maxLetters )
             {
                  char del_ch = s[start];
                  ch_map[del_ch]--;
                  start++;

                  if(ch_map[del_ch] == 0)
                    ch_map.erase(del_ch);
                
             }

             if(end-start+1 == minSize )
             {
                string ans_string = s.substr(start , minSize);
                str_map[ans_string]++;
                res = max ( res , str_map[ans_string]);
             }
             end++;
        }
        return res;

    }
};

int main(int argc, char** argv) {
	return 0;
}
