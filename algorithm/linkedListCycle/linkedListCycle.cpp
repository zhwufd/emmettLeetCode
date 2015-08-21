class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = head;
		if(fast == NULL)
			return false;
		while(fast = fast -> next){
			fast = fast -> next;
			if(fast == NULL)
				return false;
			slow = slow -> next;
			if(fast == slow)
				return true;
		}
		return false;
	}
};
			

