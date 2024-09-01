#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* newnode = new Node(-1);
        Node* trav = newnode;
        Node* temp = head;

        while(temp!=0)
        {
            trav->next = new Node(temp->val);
            trav=trav->next;
            temp = temp->next;  
        }

        Node* newhead = newnode->next;
        Node* old_list_h = head;

        Node* trav_old = old_list_h;
        Node* trav_new = newhead;

        unordered_map<Node*,Node*>mp;
         while(trav_old!=0)
         {
            mp[trav_old]=trav_new;
            trav_old = trav_old->next;
            trav_new= trav_new->next;
         }

         trav_old = newhead;
         for(auto it : mp)
         {
            Node* old_list_ptr = it.first; //get old ptr
            Node* new_list_ptr = it.second; //get new ptr

            Node* random_ptr = old_list_ptr->random;//get the random ptr 
                                                  //from old list ptr

            if(random_ptr!=0) //check if valid node address
            {
            Node* get_duplicate = mp[random_ptr]; //get the corresponding
                                                 // node of new list

                new_list_ptr->random = get_duplicate;//add it to newlist
                                                     //random
            }
           

         }
         
       return newhead;
    }
};

int main(int argc, char** argv) {
	return 0;
}
