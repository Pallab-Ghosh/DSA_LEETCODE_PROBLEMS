#include <iostream>
#include<vector>
using namespace std;


vector<int> intersection_of_array(vector<int>a1, vector<int>a2, vector<int>a3)
{
	int n1=a1.size(),n2=a2.size(),n3=a3.size(),i=0,j=0,k=0;
	vector<int>ans;
	while(i<n1 && j<n2 && k<n3)
	{
		if(a1[i]==a2[j] && a2[j]==a3[k])
		{
			ans.push_back(a1[i]);
			i++;j++;k++;
		}
		
		if(a1[i]<a2[j])
		i++;
		
		 if(a2[j]<a3[k])
		j++;
		
	    if(a3[k]<a2[j])
		k++;
	}
	return ans;
}

int main(int argc, char** argv) {
    vector<int>a1={2,4,8,10,12,20,25};vector<int>a2={1,3,4,10,12,25};vector<int>a3={4,5,10,12,20,25};
    
   vector<int>ans=intersection_of_array(a1,a2,a3);
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i]<<" ";
	}
    
}
