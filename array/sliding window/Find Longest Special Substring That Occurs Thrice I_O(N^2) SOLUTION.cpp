 int check_sim(string s)
 {
      for(int i=1;i<s.size();i++)
      {
         if(s[i] != s[i-1])
           return false;
      }
      return true;
 } 

    int maximumLength(string s) {
        
        unordered_map<string ,int>mp;
        int res = 0;
        string ans_str="";

        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                string t = s.substr(i , j-i+1);
                mp[t]++;
            }
        }

         unordered_map<string ,int>::iterator str;

        for(str = mp.begin();str!=mp.end();str++)
        {

            string temp = str->first;
            int length = temp.size();

            if(mp[temp] >= 3 && length > ans_str.size() && check_sim(temp) )
            {
                res = max(res , length);
                ans_str = temp;
            } 
            cout<<temp<<" "<<length<<endl;
            
            
        }
         
     return res > 0 ? res : -1 ;

    }
