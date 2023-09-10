#include <iostream>
#include<vector>
using namespace std;
//vector implmentation

int main(int argc, char** argv) {
	
	int n=10;
	
	//vector initialize
	vector<int>v(n,8);
	vector<int>v2;
	
	cout<<"print vector"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	
	//insert at begin
	v.insert(v.begin(),100);
	
	cout<<"after insert 100 at begining "<<endl;
	for(auto i=v.begin();i!=v.end();i++)
	{
		cout<<*i<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	
	//push element
	for(int i=0;i<12;i++)
	{
		v.push_back(i);
	}
	
	cout<<"after push 0 to 12 with cbegin() and c.end() same as begin() and end()"<<endl;
	for(auto i=v.cbegin();i!=v.cend();i++)
	{
		cout<<*i<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	
	cout<<"reverse print with cr.begin() and cr.end()"<<endl;
	for(auto i=v.crbegin();i!=v.crend();i++)
	{
		cout<<*i<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	//front and back
	cout<<"front "<<v.front()<<endl;;
	cout<<"back "<<v.back();
	
	cout<<endl;
	cout<<endl;
	
	//pop_back
	v.pop_back();
	
	cout<<"after pop_back"<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	
   //emplace && emplace back
    v.emplace(v.begin(),200);
    
    cout<<"after emplace at begining "<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	//emplace bak (added in end)
	
	v.emplace_back(654);
	
	cout<<"after emplace_back() 654"<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	//resize the vector
	v.resize(5);
	cout<<"after resize the vector 5 "<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	//erase -delete element of a special position or range
	v.erase(v.begin()+1);
	
	cout<<"after delete the 2nd elment of vector  "<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	
	
	//swap the vector
	v.swap(v2);
	
	cout<<"swap the vector with v1 and v2";
	for(int i=0;i<v2.size();i++)
	{
		cout<<v2[i]<<" ";
	}
	
	
}
