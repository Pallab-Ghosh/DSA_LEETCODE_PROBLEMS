class Solution {
public:
    string minWindow(string s, string t)
    {
        string ans="";

        unordered_map<char,int>mp;
        unordered_map<char,int>t_mp;

        int start = 0 , right = 0 , left = 0 , count=0;
        int ans_len = INT_MAX;

        for(char ch : t)
        {
            t_mp[ch]++;
        }

        int t_size = t_mp.size();

        while(right < s.size())
        {
            char ch=s[right];
            mp[ch]++;

            if(t_mp.count(ch) && mp[ch] == t_mp[ch])
             {
                count++;
             }

             while(count == t_size)
             {
                 if(right-left+1 < ans_len)
                 {
                    ans_len = right-left+1;
                    start = left;
                 }

                 char del_ch = s[left];
                 mp[del_ch]--;

                 if(mp.count(del_ch) && mp[del_ch] < t_mp[del_ch])
                   {
                     count--;
                   }
                   left++;
             }
             right++;
        }
           
           ans = s.substr(start , ans_len);

           return ans_len == INT_MAX ? "" : ans;

    }
};
