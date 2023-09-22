#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 bool BipartiteBFS(int src,vector<vector<int>>&adj,vector<int>&color)
    {
        queue<int>q;
        q.push(src);
        color[src] = 1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it : adj[node])   //check for every adjacent node
            {
                if(color[it] == -1)  //if it is not visited,marked by opposite color
                {
                    color[it] = 1-color[node];
                    q.push(it);  //and push into the queue
                }
                else if(color[it] == color[node])   //check no two adjacent element having same color
                {
                    return false;
                }
            }
        }
        return true; //Time complexity: O(N+E)
                     //Space complexity: O(N+E) + O(N) +O(N)
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
     
       
       vector<vector<int>>adj(n+1);

        for(auto it : dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>color(n+1,-1);  //color array for check

        for(int i=0;i<n;i++)
        {
            if(color[i] == -1)    
            {
                if(!BipartiteBFS(i,adj,color))
                {
                    return false;
                }
            }
        }
        return true;
    }

int main(int argc, char** argv) {
	return 0;
}
