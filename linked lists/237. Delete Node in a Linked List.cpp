#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p=node;
        swap(p->val,p->next->val);
        p->next=p->next->next;
    }
};

int main(int argc, char** argv) {
	return 0;
}
