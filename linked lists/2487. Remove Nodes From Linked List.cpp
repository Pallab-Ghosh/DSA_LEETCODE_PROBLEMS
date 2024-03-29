#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
ListNode* removeNodes(ListNode* head) {
          // traverse over the list and delete the nodes
        
        stack<ListNode*> st;
        
        ListNode* curr = head;
        
        while(curr)
        {
            // delete all the nodes which satisfy the condition
            
            while(st.empty() == false && curr -> val > st.top() -> val)
            {
                st.pop();
            }
            
            // push the curr node into the stack
          
            st.push(curr);
                
            curr = curr -> next;
        }
        
        // create new list after deletion
        
        ListNode* tail = NULL;
        
        ListNode* new_head = NULL;
        
        while(st.empty() == false)
        {
            if(st.size() == 1)
            {
                new_head = st.top();
            }
            
            st.top() -> next = tail;
            
            tail = st.top();
            
            st.pop();
        }
        
        return new_head;
    }

int main(int argc, char** argv) {
	return 0;
}
