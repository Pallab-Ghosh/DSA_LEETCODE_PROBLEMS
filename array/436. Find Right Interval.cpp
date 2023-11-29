#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
     int binary_search(vector<pair<pair<int,int>,int>>&temp, int x)
         {
             int n=temp.size();
             if(temp[n-1].first.first < x)
             {
                 return -1;
             }

            int l=0,r=n-1;

            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(temp[mid].first.first >= x)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            return temp[l].second;
         }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<pair<pair<int,int>,int>>temp;
        
        for(int i=0;i<intervals.size();i++)
        {
           
            temp.push_back({{intervals[i][0],intervals[i][1]},i});
        }

        sort(temp.begin(),temp.end());

        int n=intervals.size();
        vector<int>ans(n,-1);

        for(int i=0;i<n;i++)
        {
            ans[i]=binary_search(temp,intervals[i][1]);
        }
        return ans;
    }

int main(int argc, char** argv) {
	return 0;
}
