#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 Node* solve(Node* sourceNode)
    {
        queue<Node*> q;
        unordered_map<Node*, Node*> mp;
        mp[sourceNode] = new Node(sourceNode->val);
        q.push(sourceNode);

        while(!q.empty())
        {
            Node* parent= q.front();
            q.pop();

            for(auto child: parent->neighbors)
            {
                if(mp.find(child) == mp.end())
                {
                    Node* duplicate = new Node(child->val);
                    mp[child] = duplicate;
                    q.push(child);
                }

                mp[parent]->neighbors.push_back(mp[child]);
            }
        }

        return mp[sourceNode];
    }

class Solution {
public:
    Node* cloneGraph(Node* node) {
         if(node == NULL) return node;
          return solve(node);
    }
};

int main(int argc, char** argv) {
	return 0;
}
