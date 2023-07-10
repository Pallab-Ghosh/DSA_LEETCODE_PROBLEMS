#include <iostream>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<int> rows(m), cols(n);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) 
                res += (rows[i] == 1 and cols[j] == 1 and mat[i][j]);
        }
        return res;
    }

int main(int argc, char** argv) {
   vector<vector<int>>mat = {{1,0,0},{0,0,1},{1,0,0}};
   cout<<numSpecial(mat);
}
