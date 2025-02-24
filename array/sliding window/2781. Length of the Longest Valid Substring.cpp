class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        
        int start = 0 , end = 0 , res = INT_MIN , max_str_len =0 ;

        unordered_map<string,int>mp;

        for(string str: forbidden  )
        {
            mp[str]++;
            max_str_len = max(max_str_len ,(int)str.size());
        }

        while(end < word.size())
        {
            string temp;
            int right = end;
        
            while( right >= start && right > end - max_str_len)
            {
               temp = word[right] + temp; 
               if(mp.count(temp))
               {
                 start = right+1;
                 break;
               }
                
                right--;
            }

            res = max(res , end-start+1);
            end++;
        }
        return res;

    }
};w
