 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */   //ans = __gcd(a,b) function
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head ==0 || head->next ==0)
            return head;

        ListNode* prev = head;
        ListNode* next = head->next;

        while(next!=0)
        {
            int a = prev->val;
            int b = next->val; 

            int ans = __gcd(a,b);

            ListNode* res = new ListNode(ans);
             
            prev->next = res;
            res->next = next;

            prev = next;
            next = next->next;
            
        }
        return head;
    }
};
