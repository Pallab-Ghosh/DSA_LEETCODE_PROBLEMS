class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        if(s.size() < words[0].size())
          return {};
          
        vector<int>ans;
        unordered_map<string ,int>req ;
        
        int count_word = 0 , len = words[0].size();


        for(int i=0;i<words.size();i++)
        {
            req[words[i]]++;
        }

        for(int end =0 ; end < len ;end++)
        {
            int left = end;
            count_word=0;
            unordered_map<string ,int>mp;
            
            for(int start = end; start <= s.size()-len ; start += len)
            {
                string temp = s.substr(start,len);

                if(req.find(temp)!= req.end())    //found in req map
                {
                        mp[temp]++;
                        count_word++;

                        while(mp[temp] > req[temp])
                        {
                            string del_temp = s.substr(left , len);
                            mp[del_temp]--;
                            count_word--;
                            left=left+len;   //first index 0, then 0+3=3, 3+3=6;
                        }

                    //found perfect window str so push to ans.
                        if(count_word == words.size())
                            ans.push_back(left);
                }

               //means invalid string so no longer needed prev mp calcs.reset mp->
                else
                {
                    mp.clear();//reset mp cz from here new calc done;
                    count_word = 0;
                    left = start + len;//new start point out after start + 3 pos;
                }

            }
        }
        return ans;
    }
};
