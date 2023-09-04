#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr,int low,int mid,int high)
{

	int n1=mid-low+1;
	int n2=high-mid;
	
	vector<int>temp1(n1);
	vector<int>temp2(n2);
	
	for(int i=0;i<n1;i++)
	{
		temp1[i]=arr[low+i];
	}
	
	
	for(int j=0;j<n2;j++)
	{
		temp2[j]=arr[mid+1+j];
	}
	
	
	int i=0,j=0,k=low;
		
	while(i<n1 && j<n2)
	{
		if(temp1[i]<=temp2[j])
		{
			arr[k]=temp1[i];
			i++;
		}
		else
		{
			arr[k]=temp2[j];
			j++;
		}
		k++;
	}
	                 //o(n*logn)  space=o(n)
	
	while(i<n1)
	{
		arr[k]=temp1[i];
		i++;
		k++;
	}
	
	while(j<n2)
	{
		arr[k]=temp2[j];
		j++;
		k++;
	}
}
 

void mergeSort(vector<int>&array, int  begin, int  end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main(int argc, char** argv) {
 vector<int>v={ 12, 11, 13, 5, 6, 7 };
 mergeSort(v,0,v.size());
 
 for(int i=0;i<v.size();i++)
 {
 	cout<<v[i]<<" ";
 }
 
}
