#include <iostream>
#include<queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
  long long minCost(long long a[], long long n) {
      if(n == 1) return 0;
        priority_queue<long long,vector<long long>,greater<long long> > pq;
        for(int i=0;i<n;i++) pq.push(a[i]);
        long long ans = 0;
        while(pq.size()>1){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            ans += (x + y);
            pq.push(x+y);
        }
        return ans;
    }

int main(int argc, char** argv) {
 long long arr[]={4,2,6,7,9};
	long long n=5;
	cout<<minCost(arr,5);
}
