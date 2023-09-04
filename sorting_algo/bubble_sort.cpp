#include <iostream>
#include<vector>
using namespace std;


int sort(vector<int>&arr)
{
	bool pass;
	int n=arr.size();
	cout<<n<<endl;
	
	
//Time Complexity: O(N2)    Auxiliary Space: O(1)

   for(int i=0;i<n-1;i++)
   {
   	   pass=false;
   	   
   	   for(int j=0;j<n-i-1;j++)
   	   {
   	   	 if(arr[j]>arr[j+1])
   	   	 {
   	   	 	swap(arr[j],arr[j+1]);
   	   	 	pass=true;
		 }
	   }
	   
	   if(pass==false)
	   {
	   	 break;
	   }
	  
   }
   
    
	 
}

int main(int argc, char** argv) {
     vector<int>v={64, 34, 25, 12, 22, 11, 90 };
     sort(v);
     for(int i=0;i<v.size();i++)
     {
     	cout<<v[i]<<" ";
	 }
}
