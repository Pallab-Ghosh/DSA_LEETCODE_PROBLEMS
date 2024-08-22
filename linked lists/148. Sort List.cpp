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

  ListNode* mid_of_list(ListNode* head)
  {
      if(head==0 || head->next==0)
         return head;

      ListNode* slow=head;
      ListNode* fast=head->next; //only here we get fast=head->next;
                                // 4->2 here mid will be 4 not 2 that's why

      while(fast!=0 && fast->next!=0)
      {
        slow=slow->next;
        fast=fast->next->next;
      }

      return slow;

  }

  ListNode* merge_list(ListNode* lefthead , ListNode* righthead)
  {
      ListNode* newhead = new ListNode(-1);
      ListNode* temp_head = newhead;

      while(lefthead !=0 && righthead!=0)
      {
         if(lefthead->val <= righthead->val)
         {
            temp_head->next=lefthead;
            lefthead=lefthead->next;
         }
         else
         {
            temp_head->next=righthead;
            righthead=righthead->next;
         }
         temp_head=temp_head->next;
      }

     if(lefthead!=0)
     {
        temp_head->next=lefthead;
     }
     else
     {
        temp_head->next=righthead;
     }

      return newhead->next;
  }

    ListNode* merge_and_sort(ListNode* head)
    {
        if(head==0 || head->next==0)
          return head;
        
        ListNode* mid = mid_of_list(head);

        ListNode* lefthead=head;
        ListNode* righthead= mid->next;
        mid->next=0;

        lefthead=merge_and_sort(lefthead);
        righthead=merge_and_sort(righthead);

        return merge_list(lefthead,righthead);

    }

    ListNode* sortList(ListNode* head) {
        
        ListNode* newhead= merge_and_sort(head);
        return newhead;
    }
};

int main(int argc, char** argv) {
	return 0;
}
