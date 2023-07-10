#include <iostream>
#include<vector>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            for(int j=m-1;j>=0;j--)
            {
                temp.push_back(image[i][j]);
            }
            ans.push_back(temp);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j]==0)
                  ans[i][j]=1;

               else if(ans[i][j]==1)
                  ans[i][j]=0;
            }
        }
        return ans;
    }

int main(int argc, char** argv) {
  vector<vector<int>>v={{1,1,0},{1,0,1},{0,0,0}};
  vector<vector<int>>ans=flipAndInvertImage(v);
  for(int i=0;i<ans.size();i++)
  {
  	for(int j=0;j<ans[0].size();j++)
  	{
  		cout<<ans[i][j]<<" ";
	}
	cout<<endl;
  }
}
