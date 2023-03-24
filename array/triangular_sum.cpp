#include <iostream>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int triangular_sum(vector<int>&v)
{
	int i;
	while(v.size()!=1)
	{
		vector<int>temp;
		for(int i=0;i<v.size()-1;i++)
		{
			temp.push_back((v[i]+v[i+1])%10);
		}
		v=temp;
	}
	return v[0];
	
}

int main(int argc, char** argv) {
	vector<int>v={1,2,3,4,5};
	cout<<triangular_sum(v);
}
