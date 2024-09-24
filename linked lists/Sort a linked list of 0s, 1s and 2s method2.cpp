#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    
    
    
    
    Node* segregate(Node* head) {

        // Add code her
        if(head == 0 || head->next == 0 )return head;
        Node* temp = head;
        
       
         Node* zero_list = new Node(-1);
         Node* head_zero = zero_list;
         
         Node* one_list = new Node(-1);
         Node* head_one = one_list;
         
         Node* two_list = new Node(-1);
         Node* head_two = two_list;
         
          
         
         while(temp!=0)
         {
             if(temp->data==0)
             {
                 zero_list->next =temp;
                 zero_list = zero_list->next;
             }
             else if(temp->data==1)
             {
                  one_list->next =temp;
                  one_list = one_list->next;
             }
             else
             {
                  two_list->next = temp;
                  two_list = two_list->next;
             }
             
             temp = temp->next;
         }
         
        
         
         
          zero_list->next = (head_one->next ? head_one->next : head_two->next);
          one_list->next = head_two->next;
          
          two_list->next = 0;
        
        Node* new_head = head_zero->next;
         
         return new_head;
    }
};

int main(int argc, char** argv) {
	return 0;
}
