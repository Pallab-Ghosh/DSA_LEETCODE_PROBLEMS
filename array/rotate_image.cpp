#include <iostream>
#include<set>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include<vector>
#include<algorithm>
using namespace std;

  void rotate(vector<vector<int>>& matrix) {
         int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);

            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
    
int main(int argc, char** argv) {
   vector<vector<int>>v{
      {1,2,3},
	  {4,5,6},
	  {7,8,9}
	  };
	  
	  rotate(v);
       for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                cout<<v[i][j];
            }
            cout<<endl;
        }
}
