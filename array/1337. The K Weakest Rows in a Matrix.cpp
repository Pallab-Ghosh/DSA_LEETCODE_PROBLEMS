#include <iostream>
#include<set>
#include<vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */




int get_i(vector<int>row)
{
	int start=0,end=row.size();
	
	while(start<end)
	{
		int mid=(start+end)/2;
		
		if(row[mid]==1)
		  start=mid+1;
		  
		else
		 end=mid;
	}
	return start;
}

 vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
    	int n=mat.size() , m=mat[0].size();
    	multiset<pair<int,int>>mt;
    	
    	
    	for(int i=0;i<n;i++)
    	{
    		int number_of_i=get_i(mat[i]);
    		mt.insert({number_of_i,i}); 
		}
		
		int i=0;
		vector<int>ans(k);
		for(auto it:mt)
		{
			int ind=it.second;
			ans[i]=ind;
			k--;
			i++;
			if(k==0)
			 break;
		}
    	return ans;
	}
	
int main(int argc, char** argv)
   {
  
   	  vector<vector<int>>grid={{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
   	  int k=3;
   	 vector<int>ans= kWeakestRows(grid,k);
   	  for(int i=0;i<ans.size();i++)
   	  {
   	  	cout<<ans[i]<<" ";
	  }
   	  
    
}
