class Solution{
	public:
		ListNode* removeElements(ListNode* head, int val) {
			ListNode* itr = head;
			ListNode* preitr = head;
			for(;itr != NULL;){
				if( itr -> val == val ) {
					if( itr == head ){
						head = itr -> next;
						delete itr;
						itr = head;
						preitr = head;
					}
					else{
						preitr -> next = itr -> next;
						delete itr;
						itr = preitr -> next;
					}
				}
				else{
					preitr = itr;
					itr = itr -> next;
				}
			}
			return head;
		}
};

