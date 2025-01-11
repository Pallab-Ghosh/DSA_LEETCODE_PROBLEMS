 class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int start = 0 , end = 0 , oddcount = 0 , prevcount = 0 , ans =0;

        while(end < nums.size())
        {
            int odd_or_not = nums[end]%2;

            if(odd_or_not == 1)
            {
                oddcount++;
                prevcount = 0 ;
            }

            while(oddcount == k)
            {
                prevcount++;
                if(nums[start] %2 == 1)
                 {
                    oddcount--;
                 }
                 start++;
            }
            ans = ans + prevcount;
            end++;
        }
        return ans;
    }
};

int main(int argc, char** argv) {
	return 0;
}
