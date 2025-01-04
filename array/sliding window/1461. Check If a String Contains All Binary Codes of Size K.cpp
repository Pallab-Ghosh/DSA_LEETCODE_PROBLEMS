#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        unordered_set<string>st;
        int n =  s.size();

        if(n<k)return false;

        for(int i = 0 ; i<=n-k ;i++)
        {
              string temp_str = s.substr(i , k);
              st.insert(temp_str);
        }
        
        int total_substrings = pow(2 , k);

        return total_substrings == st.size();

    }
};

int main(int argc, char** argv) {
	return 0;
}
