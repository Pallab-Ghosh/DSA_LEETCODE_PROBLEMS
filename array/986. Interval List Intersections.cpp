#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<int>temp(2);
        int i=0, j=0;
        int length1=firstList.size();
        int length2=secondList.size();

        vector<vector<int>>ans;

        while(i<length1 && j<length2)
        {
            if(secondList[j][0] <= firstList[i][1] && firstList[i][0] <= secondList[j][1])
            {
                temp[0]=max(firstList[i][0] , secondList[j][0]);
                temp[1]=min(firstList[i][1] , secondList[j][1]);
                ans.push_back(temp);
            }
            
            if(firstList[i][1] < secondList[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }

int main(int argc, char** argv) {
	return 0;
}
