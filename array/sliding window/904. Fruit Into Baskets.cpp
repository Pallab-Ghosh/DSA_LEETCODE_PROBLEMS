class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        if(fruits.size() < 2)
          return 1;

          int s = 0 , e = 0 , res = 0;
          unordered_map<int,int>mp;

          while(e < fruits.size())
          {
             mp[fruits[e]]++;

             while( mp.size() > 2 )
             {
                 mp[fruits[s]]--;
                 

                 if(mp[fruits[s]] == 0)
                   mp.erase(fruits[s]);

                   s++;
             }

             res = max(res , e-s+1);
             e++;
          }
          return res;
    }
};
