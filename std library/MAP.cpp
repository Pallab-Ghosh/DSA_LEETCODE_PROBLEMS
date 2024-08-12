#include <iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<list>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	map<string,int>mp;
	
	mp["pallab"]=21;
	mp["abc"]=291;
	mp["fre"]=23;
	mp["ghi"]=212;
	mp["xhu"]=2123;
	mp["mno"]=765;
	
	for(auto it : mp)
	{
		cout<<it.first<<" "<<it.second<<" ";
		cout<<endl;
	}
	mp.insert({"sts",1111});
	cout<<endl;
	for(auto it : mp)
	{
		cout<<it.first<<" "<<it.second<<" ";
		cout<<endl;
	}
	
	map<int,int>m1;
	m1[2]=100;
	m1[-1]=900;
	m1[0]=5135;
	m1[2]=78;
	m1[1]=656;
	m1[0]=535;
	
	
	
	for(auto it : m1)
	{
		cout<<it.first<<" "<<it.second<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	map<int,int>m5(m1);
	
	for(auto it : m5)
	{
		cout<<it.first<<" "<<it.second<<" ";
		cout<<endl;
	}
	
    if(	m1.find(12)!=m1.end())
    {
    	cout<<"found";
	}
	else
	{
	  cout<<"not found";
	}
	cout<<endl;
	cout<<endl;
	
	map<int , list<vector<int>>> mp1;
	
	mp1[1].push_front({543,78,564});
	mp1[1].push_front({1543,178,1564});
	
	mp1[0].push_front({76,32,12});
	mp1[0].push_front({176,132,112});
	
	mp1[-1].push_front({12,56,90});
	mp1[-1].push_front({112,156,190});
	
	for(auto it : mp1)
	{
		list<vector<int>>list_item = it.second;
		 for(auto arr= list_item.begin(); arr!=list_item.end();arr++)
		 {
		 	vector<int>temp=*arr;
		 	
		 	cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<" ";
		 }
		 cout<<endl;
	}
}
