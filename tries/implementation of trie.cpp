#include <iostream>

using namespace std;

//create node
class node{
	node* linked[26];
	bool flag=false;
	
	public:
		bool contain_key(char ch)
		{
			return linked[ch-'a']!=0;
		}
		
		void put_key(char ch)
		{
			node* newnode=new node();
			linked[ch-'a']=newnode;
		}
		
		node* get_key(char ch)
		{
			return linked[ch-'a'];
		}
		
		void set_key()
		{
			flag=true;
		}
		
		bool is_end()
		{
			return flag;
		}
};

//trie
class trie{
	node* root;
	public:
		trie(){
			root=new node();
		}
		
		//insert
		void insert(string word)
		{
			node* temp=root;
			for(int i=0;i<word.length();i++)
			{
				if(!temp->contain_key(word[i]))
				{
					temp->put_key(word[i]);
				}
				temp=temp->get_key(word[i]);
			}
			temp->set_key();
		}
		
		//search
		bool search(string word)
		{
			node* temp=root;
			for(int i=0;i<word.length();i++)
			{
				if(!temp->contain_key(word[i]))
				{
					return false;
				}
				temp=temp->get_key(word[i]);
			}
			return temp->is_end();
		}
		
		//startwith
		bool startwith(string prefix)
		{
			node* temp=root;
			for(int i=0;i<prefix.length();i++)
			{
				if(!temp->contain_key(prefix[i]))
				{
					return false;
				}
				temp=temp->get_key(prefix[i]);
			}
			return true;
		}
		
};



int main(int argc, char** argv) {
	trie tr;
	tr.insert("apple");
	tr.insert("apps");
	if(tr.startwith("apps"))
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
}
