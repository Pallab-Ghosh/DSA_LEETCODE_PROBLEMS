#include <iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;
class node{
	public:
		int data;
		node* left=0;
		node* right=0;
};

node* getnode(int x)
{
	node* newnode=new node();
	newnode->data=x;
	return newnode;
}

void find_parent(node* root,unordered_map<node*,node*>&parent_node)
{
	if(root==0)return;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node* p=q.front();
		q.pop();
		if(p->left)
		{
			parent_node[p->left]=p;
			q.push(p->left);
		}
		
		if(p->right)
		{
			parent_node[p->right]=p;
			q.push(p->right);
		}
	}
}

 vector<int> distanceK(node* root, node* target, int k) 
    {
        unordered_map<node*,node*>parent_node;
        find_parent(root,parent_node);
        queue<node*>q;
        unordered_map<node*,bool>visited;
        int count=0;
        q.push(target);
        visited[target]=true;
        
        while(!q.empty())
        {
        	int size=q.size();
        	if(count==k)break;
        	 
        	 count++;
        	 
        	for(int i=0;i<size;i++)
        	{
        		node* current=q.front();
        		q.pop();
        		if(current->left && !visited[current->left])
        		{
        			visited[current->left]=true;
        			q.push(current->left);
				}
        		
        		if(current->right && !visited[current->right])
        		{
        			visited[current->right]=true;
        			q.push(current->right);
				}
				
				if(parent_node[current] && !visited[parent_node[current]])
        		{
        			visited[parent_node[current]]=true;
        			q.push(parent_node[current]);
				}
			}
		}
		
		vector<int>res;
		while(!q.empty())
		{
		    node* p=q.front();
		    q.pop();
		    res.push_back(p->data);
		}
		return res;
    }

int main(int argc, char** argv) {
       node* root=0;
       
       root=getnode(3);
       root->left=getnode(5);
       root->right=getnode(1);
       
       root->left->left=getnode(6);
       root->left->right=getnode(2);
       
       root->left->right->left=getnode(7);
       root->left->right->right=getnode(4);
       
        root->right=getnode(0);
        root->right->right=getnode(8);
        
        vector<int>ans=distanceK(root, root->left, 2); 
        for(int i=0;i>ans.size();i++)
        {
        	cout<<ans[i]<<" ";
		}
      
}
