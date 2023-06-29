 #include <iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;
class Node{
	public:
		int data;
		Node* left=0;
		Node* right=0;
};


Node* getnode(int x)
{
	Node* newnode=new Node();
	newnode->data=x;
	return newnode;
}

vector<int>diagonal(Node* root)
{
	if(root==0)
	return {};
	vector<int>ans;
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		int size=q.size();
		while(size--)
		{
			Node* p=q.front();
			q.pop();
			while(p)
			{
				ans.push_back(p->data);
				if(p->left)
				{
					q.push(p->left);
				}
				
				p=p->right;
			}
		}
	}
	return ans;
}

int main(int argc, char** argv) {
	Node* root=0;
	root=getnode(8);
	root->left=getnode(3);
	root->right=getnode(10);
	root->left->left=getnode(1);
	root->right->left=getnode(6);
	root->right->left->left=getnode(4);
	root->right->left->right=getnode(7);
	root->right->right=getnode(14);
	root->right->right->left=getnode(13);
	vector<int>ans=diagonal(root);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
