#include <iostream>
#include<unordered_map>
#include<vector>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int func(vector<int>&arr , int k ) {

	unordered_map<int,int>mp;
	int start = 0 , end=0 , res=0, max_one=0;
	
	while(end < arr.size())
	{
		int no = arr[end];
		mp[no]++;
		
		max_one = max(max_one , mp[1]);
		
		if((end - start + 1) - max_one > k)
		{
			int del_no = arr[start];
			mp[del_no]--;
			start++;
			
			if(mp[del_no] ==0)
			  mp.erase(del_no);
			
		}
		
		res = max(res , end-start+1);
		end++;
	}
	return res;
}

int main(int argc, char** argv) {
	vector<int>arr={1,0,1,1,0};
	int k =1; //no of times flip of 0;
	
	cout<<func(arr , k);
}
