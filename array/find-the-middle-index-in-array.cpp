#include <iostream>


int findMiddleIndex(vector<int>& nums) 
{
        int n=nums.size(),sum=0,lefts=0;
        for(auto i:nums)
        sum+=i;
        for(int i=0;i<n;i++)
        {
            if(lefts==sum-nums[i])
            return i;
            lefts+=nums[i];
            sum-=nums[i];
        }
        return -1;
    }
};

int main(int argc, char** argv) {
	return 0;
}
