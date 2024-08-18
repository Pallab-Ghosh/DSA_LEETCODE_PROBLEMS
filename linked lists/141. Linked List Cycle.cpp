#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
            ListNode* slow = head ;
            ListNode* fast=head ;

            if(head==0)return false;

            if( slow!=0 && slow->next==0 && fast!=0   && fast->next==0)
              return false;

        while(fast!=0 && fast->next!=0)
        {
            slow = slow->next;
            fast = fast->next->next;

               if(fast == slow)
                 return true;
        }

        
          return false;
    }
};

int main(int argc, char** argv) {
	return 0;
}
