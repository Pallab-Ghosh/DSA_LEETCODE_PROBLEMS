class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
    	
    	if(head==0)return;
    	
    	printLinkedListInReverse(head->getNext());
    	head->printValue();
  }
}
