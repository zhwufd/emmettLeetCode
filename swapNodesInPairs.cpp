// Wuzehui
// Accepted
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if(head != NULL) {
			if (head -> next != NULL ) {
				ListNode* miditr = head -> next;
				head -> next = miditr -> next;
				miditr -> next = head;
				head = miditr;
				ListNode* itr = head -> next;
				while(itr != NULL){
					if(itr -> next != NULL) {
						ListNode* itr1 = itr -> next;
						if (itr1 -> next != NULL) {
							ListNode* itr2 = itr1 -> next;
							ListNode* itr3 = itr2 -> next;
							itr1 -> next = itr3;
							itr2 -> next = itr1;
							itr -> next = itr2;
							itr = itr1;
						}
						else
							break;
					}
					else
						break;
				}
			}
		}
        return head;
	}
};

