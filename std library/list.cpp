#include <iostream>
#include<list>

using namespace std;



int main(int argc, char** argv) {
	list<int>l1({1,2,3});
	
	
	l1.push_back(4);
	
	cout<<"after push_back"<<endl;
	for(int it:l1)
	{
		cout<<it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	l1.push_front(100);
	cout<<"after push_front"<<endl;
	for(int it:l1)
	{
		cout<<it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	list<int>::iterator it;
	
	
	it=l1.begin();
	it=l1.insert(it,200);
		
	cout<<"insert at begining "<<endl;
	 for(int it:l1)
	{
		cout<<it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<"insert at 2 position"<<endl; 
   advance(it,2);//advance(iterator, position)
	
	 l1.insert(it,876);
	 for(int it:l1)
	{
		cout<<it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<"insert 3 times 126 where it point the position "<<endl;
	l1.insert(it,3,126);//position occurences element_value
	 for(int it:l1)
	{
		cout<<it<<" ";
	}            
}
