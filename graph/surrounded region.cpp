#include <iostream>
#include<vector>
using namespace std;

  void dfs(vector<vector<char>>& v ,int i,int j,int m,int n)
  {
  	if(v[i][j]!='0'|| i<0 || j<0 || i>=m || j>=n)
  	{
  		return;
	}
	
	v[i][j]='#';
	dfs(v,i+1,j,m,n);
	dfs(v,i,j+1,m,n);
	dfs(v,i-1,j,m,n);
	dfs(v,i,j-1,m,n);
  }
 void solve(vector<vector<char>>& v)
    {
        int m=v.size();
        int n=v[0].size();
        if(m==0)return;
        
        for(int i=0;i<m;i++)
        {
        	if(v[i][0]=='0')
        	{
        		dfs(v,i,0,m,n);
			}
			
			if(v[i][n-1]=='0')
			{
				dfs(v,i,n-1,m,n);
			}
		}
		
		  for(int i=0;i<n;i++)
         {
        	if(v[0][i]=='0')
        	{
        		dfs(v,0,i,m,n);
			}
			
			if(v[m-1][i]=='0')
			{
				dfs(v,m-1,i,m,n);
			}
		 }
		 
		 for(int i=0;i<m;i++)
		 {
		 	for(int j=0;j<n;j++)
		 	{
		 		if(v[i][j]=='0')
		 		{
		 			v[i][j]='x';
				}
				
				if(v[i][j]=='#')
				{
					v[i][j]='0';
				}
			}
		 }
    }
int main(int argc, char** argv) {
	vector<vector<char>>v={
	  {'x','x','x','x','x'},
	  {'x','0','0','0','x'},
	  {'x','0','x','x','x'},
	  {'x','x','x','x','x'}
	};
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[0].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	solve(v);
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[0].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
