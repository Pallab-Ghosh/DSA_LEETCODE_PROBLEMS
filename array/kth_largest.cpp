#include <iostream>
#include<vector>
#include<queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int kth_largest_element(vector<int>nums,int k)
{
	 priority_queue<int,vector<int>,greater<int>>s;
        for(int i=0;i<nums.size();i++)
        {
           if(s.size()<k)
           {
               s.push(nums[i]);
           }
           else
           {
               if(nums[i]>s.top())
               {
                   s.pop();
                   s.push(nums[i]);
               }
           }
        }
        
        return s.top();
}
int main(int argc, char** argv) {

vector<int>arr={3,2,3,1,2,4,5,5,6};
int k=2;
cout<<kth_largest_element(arr,k);	
}
