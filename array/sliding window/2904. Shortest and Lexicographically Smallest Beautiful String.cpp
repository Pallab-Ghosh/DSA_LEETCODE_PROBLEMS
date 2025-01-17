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
                  string temp = s.substr(start , end - start + 1);
                  cout<<temp<<endl;

                  if(temp.size() < mini_length)
                  {
                     mini_length = temp.size();
                     ans = temp;
                  }
                  else if(temp.size() == mini_length)
                  {
                     ans = min(ans , temp);
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
