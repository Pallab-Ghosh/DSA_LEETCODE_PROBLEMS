class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int max_freq_of_ltr = 0 , result = 0 , end = 0 , start = 0;
        unordered_map<char,int>mp;

        while(end < answerKey.size() )
        {
            char ch = answerKey[end];
            mp[ch]++;

            max_freq_of_ltr = max (max_freq_of_ltr , mp[ch]);

            while((end-start+1) - max_freq_of_ltr > k)
            {
                char delete_ch = answerKey[start];
                mp[delete_ch]--;
                start++;
                if(mp[delete_ch] == 0)
                  mp.erase(delete_ch);
            }

            result = max(result , end-start+1);
            end++;

        }
        return result;
    }
};
