// wuzehui
// Accepted
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		int n = 0;
		for(ListNode* itr = head; itr != NULL; itr = itr -> next){
			++n;
		}
		if( n > 1 ){
			k = k % n;
			if(k != 0){
				int i = 0;
				ListNode* itr1 = NULL;
                ListNode* itr3 = NULL;
				for(ListNode* itr = head; itr != NULL; itr = itr -> next){
					++i;
					if(i == n - k)
						itr1 = itr;
					else if(i == n)
						itr3 = itr;
				}
				ListNode* itr2 = head;
				head = itr1 -> next;
				itr3 -> next = itr2;
				itr1 -> next = NULL;
			}
		}
		return head;
	}
};
