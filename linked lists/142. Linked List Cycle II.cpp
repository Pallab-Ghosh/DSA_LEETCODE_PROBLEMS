#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head ;
        ListNode* fast=head ;
        ListNode* position_ptr = head;

        if(head == 0 || head->next==0) // head is null or only 1 node
           return 0;

        while(fast != 0 && fast->next != 0)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) //break if find cycle
              break;
        }

       if(slow == fast) // check if slow == fast then again run loop
       {
           while(position_ptr != slow)
           {
             position_ptr = position_ptr->next;
             slow = slow->next;
           }

           return position_ptr;
       }
       else // else return null that no cycle found 
       {
         return 0;
       }
       

    }
};

int main(int argc, char** argv) {
	return 0;
}
