#include <iostream>
#include<vector>
using namespace std;


void solu(vector<int>arr,vector<int>&ans){
	
	int a=1,b=1;
	int n=arr.size();
	for(int i=0;i<n;i++){
		ans[i]=a;
		a*=arr[i];
	}
	
	for(int i=n-1;i>=0;i--)
	{
		ans[i]*=b;
		b*=arr[i];
	}
	
	
}
int main(int argc, char** argv) {
	vector<int>v{1,2,3,4};
	vector<int>ans(v.size(),1);
	solu(v,ans);
	
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
