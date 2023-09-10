#include <iostream>
#include <forward_list>

using namespace std;



int main(int argc, char** argv) {
	forward_list<int>list1({1,2,3,4,5,6});
	forward_list<int>list2(5,100);
	forward_list<int>list3(list1.begin(),list1.end());
	
	cout<<"list1"<<endl;
	for(int it:list1)
	{
		cout<<it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<"list2"<<endl;
	for(int it:list2)
	{
		cout<<it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<"list3"<<endl;
	for(int it:list3)
	{
		cout<<it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	list1.push_front(21);
	list1.push_front(27);
	cout<<"list1 after push front 21 27"<<endl;
	for(int it:list1)
	{
		cout<<it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	list1.pop_front();
	cout<<"list1 after pop front"<<endl;
	for(int it:list1)
	{
		cout<<it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	forward_list<int>::iterator it;
	it=list1.insert_after(list1.begin(),{400,200});
	cout<<"list1 after push 2nd position {400,200}"<<endl;
	for(int it:list1)
	{
		cout<<it<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
    it= list1.emplace_after(it,987);
     cout<<"after 987 push where it points "<<endl;
   	for(int temp:list1)
	{
		cout<<temp<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	
	list1.reverse();
	cout<<"after reverse "<<endl;
	for(int temp:list1)
	{
		cout<<temp<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
    list1.sort();
	cout<<"after sorting "<<endl;
	for(int temp:list1)
	{
		cout<<temp<<" ";
	}
	
	cout<<endl;
	cout<<endl;
	
	list1.remove(5);
	cout<<"after delete 5  "<<endl;
	for(int temp:list1)
	{
		cout<<temp<<" ";
	}
}
