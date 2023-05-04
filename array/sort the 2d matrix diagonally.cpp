#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

 vector<vector<int>> diagonalSort(vector<vector<int>>& v) 
 {
 	  int n=v.size();
 	  int m=v[0].size();
 	  
 	  for(int i=0;i<n;i++)
 	   {
 	  	  int k=i;
 	  	  int j=0;
 	  	  vector<int>v1;
 	  	  while(k<n and j<m)
 	  	  {
 	  	  	v1.push_back(v[k][j]);
 	  	  	k++;
 	  	  	j++;
		  }
		  sort(v1.begin(),v1.end());
		  
		     k=i;
 	  	     j=0;
 	  	     int l=0;
 	  	  while(k<n and j<m and l<v1.size())
 	  	  {
 	  	  	v[k][j]=v1[l];
 	  	  	l++;
 	  	  	k++;
 	  	  	j++;
		  }
	   }
	   
	   
	   
	    for(int j=1;j<m;j++)
 	   {
 	  	  int k=j;
 	  	  int i=0;
 	  	  vector<int>v1;
 	  	  while(k<m and i<n)
 	  	  {
 	  	  	v1.push_back(v[i][k]);
 	  	  	i++;
 	  	  	k++;
		  }
		  sort(v1.begin(),v1.end());
		  
		   k=j;
 	  	   i=0;
 	  	    int l=0;
 	  	  while(k<m and j<n and l<v1.size())
 	  	  {
 	  	  	v[i][k]=v1[l];
 	  	  	l++;
 	  	  	k++;
 	  	  	i++;
		  }
	   }
	   return v;
 }
 
 
 
int main(int argc, char** argv) {
	vector<vector<int>>v = {
	{3,3,1,1},
	{2,2,1,2},
	{1,1,1,2}
	};
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	
	 v=diagonalSort(v);
	 
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	 
}
