#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
  int deleteGreatestValue(vector<vector<int>>& grid) {
           int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        
        for(auto &v:grid){
            sort(v.begin(), v.end());
        }
       // sort(grid.begin(), grid.end());
        
        for(int j=m-1;j>=0;j--){
            int maxi=0;
            for(int i=n-1;i>=0;i--){
                maxi=max(maxi, grid[i][j]);
            }
            ans+=maxi;
        }
        return ans;
    }
int main(int argc, char** argv) {
   vector<vector<int>>v={{1,2,4},{3,3,1}};
   cout<<deleteGreatestValue(v);
}
