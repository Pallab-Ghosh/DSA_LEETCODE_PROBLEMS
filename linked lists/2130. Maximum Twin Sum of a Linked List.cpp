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

   ListNode* get_mid(ListNode* head)
   {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev= 0;

        while(fast!=0 && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast= fast->next->next;
        }

        return prev;
   }

   ListNode* reverse_list( ListNode* head)
   {
       ListNode* prev = 0;
        ListNode* next=0;
         ListNode* current = head;

         while(current!=0)
         {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
         }
         return prev;
   }

    int pairSum(ListNode* head) {
        
        ListNode* mid = get_mid(head);
        ListNode* next_half_head = mid->next;

        mid->next = 0;
        
        
        next_half_head = reverse_list(next_half_head);
          

        ListNode* newhead = head;

      
         
        int ans = INT_MIN;

        while(newhead !=0 && next_half_head!=0)
        {
            int temp_ans =0;
            temp_ans = temp_ans + newhead->val + next_half_head->val;
            ans = max(temp_ans , ans);
            newhead = newhead->next;
            next_half_head = next_half_head->next;
        } 

        return ans;
    }
};

int main(int argc, char** argv) {
	return 0;
}
