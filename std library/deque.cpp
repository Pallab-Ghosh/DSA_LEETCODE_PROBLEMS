#include <iostream>
#include<deque>

using namespace std;


int main(int argc, char** argv) {
	deque<int>dq;
	deque<int>dq2;
	
	//push_back
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
	dq.push_back(5);
	dq.push_back(6);
	dq.push_back(7);
	dq.push_back(8);
	
	cout<<"push_back"<<endl;
	for(auto it=dq.begin();it!=dq.end();it++)
	{
		cout<<*it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<"push_front()"<<endl;
	dq.push_front(100);
	for(auto it=dq.begin();it!=dq.end();it++)
	{
		cout<<*it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<"pop_front()"<<endl;
	dq.pop_front();
	for(auto it=dq.begin();it!=dq.end();it++)
	{
		cout<<*it<<" ";
	}
	
	
	cout<<endl;
	cout<<endl;
	
	cout<<"pop_back()"<<endl;
	dq.pop_back();
	for(auto it=dq.begin();it!=dq.end();it++)
	{
		cout<<*it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<"front"<<endl;
	cout<<dq.front();
	
	cout<<endl;
	cout<<endl;
	
	cout<<"back"<<endl;
	cout<<dq.back();
	
	cout<<endl;
	cout<<endl;
	//swap the deque
	//dq.swap(dq2);
	
	cout<<"swap the deque"<<endl;
	for(auto it=dq2.begin();it!=dq2.end();it++)
	{
		cout<<*it<<" ";
	}
	
	
	cout<<endl;
	cout<<endl;
	
	cout<<"reverse print of deque"<<endl;
	for(auto it=dq.crbegin();it!=dq.crend();it++)
	{
		cout<<*it<<" ";
	}
}
