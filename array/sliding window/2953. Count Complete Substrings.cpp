class Solution {
public:
    int sliding_win(int start , int end ,string &word ,int k)
    {

          int  res = 0;
          
          for(int uniq_ch = 1 ; uniq_ch <= 26 && uniq_ch * k <= end-start+1; uniq_ch++)
          {
              int window_len = uniq_ch * k;
              int good_ch = 0 ;
              int right = start , left = start ;
              vector<int>mp(26 , 0);

              while(right <= end)
              {
                 int ch = word[right] - 'a';
                  mp[ch]++;

                  if(mp[ch] == k)
                    good_ch++;

                  else if(mp[ch] == k+1)
                    good_ch--;

                  if(right - left + 1 > window_len)
                  {
                     int del_ch = word[left] - 'a';

                     if(mp[del_ch] == k)
                        good_ch--;

                      else if(mp[del_ch] == k+1)
                        good_ch++;

                        mp[del_ch]--;
                        left++;
                  }

                  if(uniq_ch == good_ch)
                    res = res + 1;

                  right++;
              }
          }
          return res;
    }

    int countCompleteSubstrings(string word, int k) {
        
        int start = 0 ;
        int ans = 0;

        for(int i = 1 ; i <= word.size();i++)
        {
           if( i == word.size() || abs( word[i] - word[i-1] ) > 2 ) 
           {
              ans = ans + sliding_win(start , i-1 , word , k);
              start = i;
           }
        }
        
        return ans;
    }
}; 
 

     
  

