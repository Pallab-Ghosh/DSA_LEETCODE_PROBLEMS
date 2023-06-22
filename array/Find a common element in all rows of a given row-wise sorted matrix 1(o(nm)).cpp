 #include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int find_ele(vector<vector<int>>arr)
{
      int n=arr.size();
      int m=arr[0].size();
    
      int ele=0;
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++)
      {
      	 mp[arr[i][0]]++;
      	  
      	  for(int j=1;j<m;j++)
      	  {
      	  	  if(arr[i][j]!=arr[i][j-1])
      	  	  {
      	  	  	 mp[arr[i][j]]++;
			  }
      	  }
		  
	  }
    
     unordered_map<int,int>::iterator it;
     for(auto it:mp)            // o(n*m)
     {
     	 if(it.second==n)
     	 {
     	 	ele=it.first;
     	 	return ele;
		 }
	 }
	return 0;
}
int main(int argc, char** argv) {
   vector<vector<int>>v{ 
                    {1, 2, 3, 4, 5},
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},
                  };
                  cout<<find_ele(v);
}
