#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        
        int start=0,end=0,res=0 , max_freq=INT_MIN;

         unordered_map<char,int>mp;

        while(end<s.size())
        {
            char ch_pos = s[end];
            mp[ch_pos]++;

            while(mp[ch_pos] == k)
            {
                cout<<ch_pos<<endl;
                 res = res + (s.size() - end);//substrings ended at end.cz from 
                                     //end to last there will be more subtring.
                 char del_ch = s[start]; 
                 mp[del_ch]--;
                 start++;

                 if(mp[del_ch]==0)mp.erase(del_ch);
            }
            end++;
        }
        return res;
    }
};

int main(int argc, char** argv) {
	return 0;
}
