#include <iostream>
#include<list>
#include<queue>
#include<vector>

using namespace std;


    vector<int>findOrder(int numCourses, vector<vector<int>>& prerequisites)
     {

        list<int>l1[numCourses];
        vector<int>ind(numCourses,0);

        for(int i=0;i<prerequisites.size();i++)
        {
            int x=prerequisites[i][1];
            int y=prerequisites[i][0];

            l1[x].push_back(y);
            ind[y]++;
        }

        vector<int>ans;
      
       queue<int>q;

       for(int i=0;i<numCourses;i++)
       {
           if(ind[i]==0)
           {
               q.push(i);
           }
       }

      int n=0;
       while(!q.empty())
       {
           int start=q.front();
           q.pop();
           ans.push_back(start);
           n++;
           for(auto it:l1[start])
           {
               ind[it]--;
               if(ind[it]==0)
               {
                   q.push(it);
               }
           }
       }

         if(n==numCourses)
         {
             return ans;
         }
         else
         {
             return {};
         }
    }


int main()
{
	vector<vector<int>>v={{1,0},{2,0},{3,1},{3,2}};
	int n=4;
	vector<int>ans=findOrder(n,v);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
