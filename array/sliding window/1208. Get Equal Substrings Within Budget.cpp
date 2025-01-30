class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        
        int start = 0 , end = 0 , res = 0 , sum_diff = 0;

        while(end < s.size())
        {
            sum_diff += abs(s[end] - t[end]);

            while(sum_diff > maxCost)
            {
                
                sum_diff = sum_diff - abs(s[start] - t[start]);
                start++;
            }

          res = max(res , end-start+1);
          end++;
        }
        return res  ;
    }
};
