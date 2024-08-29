#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 
    ListNode* reverse(ListNode* head)
    {
          ListNode* next = 0;
           ListNode* current = head;
            ListNode* prev =0;

            while(current != 0 )
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head ==0 || head->next ==0)
          return head;

        ListNode* dummy = new ListNode(-1);//create dummy node
        dummy->next = head; //attach it to first of list
                            //   -1->1->2->3->4->5 not headnode = dummy;

        ListNode* prev_left =dummy ;
        ListNode* rightnode = dummy;

        int i = 0;
        
        while(i<left-1)
        {
            prev_left = prev_left->next;//set the pointer to previous node
                                       //from which node reverse will start
            i++;
        }
         
        i=0;

        while(i<right)
        {
           rightnode = rightnode->next;//set the pointer to last node
                                      //upto here reverse will be done.
           i++;
        }
    
     ListNode* next_right = rightnode->next;//store next value of right
     rightnode->next = 0; //set next node address null to break list;
//
    ListNode* newhead = reverse(prev_left->next);//reverse function

    ListNode* tail = newhead;

    while(tail->next!=0)
    {
        tail=tail->next;//set the pointer to last node of reverse tailnode
    }

    prev_left->next = newhead;//assign the reverse headnode ;

    if(next_right!=0)
    {
      tail->next = next_right;//assign the remaining half to the tailnode.
    }
    
    if(left==1) //check if left=1 return newhead, cz reverse is done from -
                  //first node so the newhead will be the head now;
    {
      return newhead ;
    }

    else
    {
        return head;//cz reverse is done in between nodes from first 
            //to last somewhere not from head, thats why head remain same
    }
}
};

int main(int argc, char** argv) {
	return 0;
}
