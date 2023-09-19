#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
    int maxDepth(Node* root) {
           if (!root) return 0;

        int levels = 0;
        queue<Node*> Q; Q.push(root);

        while (!Q.empty()) {
            size_t size = Q.size();
            levels++;
            for (int _ = 0; _ < size; _++) {
                Node* curr = Q.front(); Q.pop();
                for (Node*& child : curr->children) Q.push(child);
            }
        }

        return levels;
    }

int main(int argc, char** argv) {
	return 0;
}
