#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
 typedef pair<int,int>P;

  int minMST(vector<vector<P>>& adj, int V) {
        priority_queue<P, vector<P>, greater<P>> pq; //minheap
        pq.push({0, 0}); //{weight, vertex}
        
        vector<bool> inMST(V, false);
        int sum = 0;
 
        while(!pq.empty()) {
            
            auto p = pq.top();
            pq.pop();
            
            int wt     = p.first;
            int node   = p.second;
            
            if(inMST[node] == true)
                continue;
            
            inMST[node] = true; //added to mst
            sum += wt;
            
            for(auto &tmp : adj[node]) {
                
                int neighbor      = tmp.first;
                int neighbor_wt   = tmp.second;
                
                if(inMST[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
 
            }
        }
        
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n=points.size();
        vector<vector<P>> v(n);

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int dist=abs(x1-x2)+abs(y1-y2);
							

                v[i].push_back({j,dist});
                v[j].push_back({i,dist});
            }
        }

        return minMST(v,n);
       \
    }
};

int main(int argc, char** argv) {
	return 0;
}
