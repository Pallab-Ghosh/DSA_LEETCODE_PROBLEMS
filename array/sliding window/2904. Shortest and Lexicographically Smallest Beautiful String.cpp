#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string shortestBeautifulSubstring(string s, int k) {
        string ans ="";
        int mini_length = INT_MAX , start = 0 , end = 0 , count_one = 0;
        
        while(end < s.size())
        {
             if(s[end] == '1')
             {
                count_one++;
             }

            while(s[start] == '0')
               start++;
            
             if(count_one == k)
              {
                  int window_length = end - start + 1;
                
       // Update result if this window is shorter or lexicographically smaller
      if(window_length < mini_length ||(window_length == mini_length && s.substr(start, window_length) < ans))
               {
                    mini_length = window_length;
                    ans = s.substr(start, window_length);  // Update the result substring
                }

                  if(s[start] == '1')
                  {
                        start++;
                        count_one--;
                  }
                     
              }
             
             end++;
        }
        return ans ;
        
    }

int main(int argc, char** argv) {
	return 0;
}
