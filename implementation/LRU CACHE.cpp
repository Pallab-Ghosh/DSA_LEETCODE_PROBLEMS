#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 class LRUCache {
public:
    class node {
        public:
            int key; int val;
            node* next =0 ;node* prev =0;

        node(int _key, int _val) {
            key = _key;  val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*>m;
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode)
     {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;

        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {

        if (m.find(key_) != m.end())
         {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);

            deletenode(resnode);
            addnode(resnode);

            m[key_] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) 
    {
        if(m.find(key_) != m.end())
         {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }

        else if(m.size() == cap) 
        {
          m.erase(tail->prev->key);
          node* lastnode = tail->prev;
          deletenode(lastnode);
        }
        
        node* newnode = new node(key_, value);
        addnode(newnode);
        m[key_] = newnode; 
    }
};
 

int main(int argc, char** argv) {
	return 0;
}
