#include <iostream>
#include<vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 bool canJump(vector<int>& nums) {
        int reachable=0;
        for(int i=0;i<nums.size();i++)
        {
            if(reachable <i)
            return false;
            
            reachable=max(reachable,nums[i]+i);
        }
        return true;
    }
int main(int argc, char** argv) {
	vector<int>nums= {2,3,1,1,4};
	cout<<canJump(nums);
}
