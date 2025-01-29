#include <iostream>
#include<map>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

  int maximumLength(string s) {
        
      
        int n = s.size();
        vector<vector<int>>v(26, vector<int>(n+1, 0));

        char prev_ch = s[0];
        int len =0;

        for(int i=0;i<s.size();i++)
        {
            if(prev_ch == s[i])
            {
                len++;
                v[s[i] -'a'][len] += 1;
            }


            else
            {
                  len=1;
                  v[s[i] -'a'][len]= v[s[i]-'a'][len] + 1;
                  prev_ch = s[i];
            }
        }

        int cum_sum = 0;
        int res=0;

        for(int row = 0; row < 26 ; row++)
        {
            cum_sum=0;

            for(int col=n; col>=1 ; col--)
            {
                cum_sum += v[row][col];

                if(cum_sum >=3)
                {
                    res = max(res, col);
                    break;
                }
            }
        }
        return res == 0 ? -1 : res;
       

    }
