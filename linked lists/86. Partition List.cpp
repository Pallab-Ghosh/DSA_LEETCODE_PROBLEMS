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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* temp_node = new ListNode(-1);
        ListNode*  ans = temp_node;
        ListNode* newhead = head;
        queue<int>q;

        while(newhead!=0)
        {
            if(newhead->val < x)
            {
                temp_node->next = new ListNode(newhead->val);
                temp_node=temp_node->next;
            }
            else if(newhead->val >= x)
            {
                 q.push(newhead->val);
            }
            newhead = newhead->next;  
        }


        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            temp_node->next = new ListNode(top); 
            temp_node=temp_node->next;
        }
        return ans->next;
    }
};

int main(int argc, char** argv) {
	return 0;
}
