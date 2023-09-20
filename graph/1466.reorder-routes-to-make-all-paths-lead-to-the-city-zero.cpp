#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int minReorder(int n, vector<vector<int>>& connections) {
         unordered_map<int,vector<pair<int,int>>> mp;
        for(auto it:connections)
        {
            mp[it[0]].push_back({it[1],1});
            mp[it[1]].push_back({it[0],0});
        }
        
        int ans=0;
      vector<bool>vis(n,false);
        vis[0]=true;
       queue<int>q;
     
       q.push(0);

    
       while(!q.empty())
       {
          int start=q.front();
          q.pop();
          for(auto it:mp[start])
          {
              int v=it.first;
              int check=it.second;

              if(!vis[v])
              {
                  if(check==1)
                  {
                       ans++;
                  }
                  vis[v]=true;
                  
                  q.push(v);
              }
          }
       }

       

        return ans;
    }

int main(int argc, char** argv) {
	return 0;
}
