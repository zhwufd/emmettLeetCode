Struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head){
    if(head != NULL){
        ListNode* itr1 = head -> next;
        if(itr1 != NULL){
            ListNode* itr2 = itr1 -> next;
            head -> next = NULL;
            itr1 -> next = head;
            head = itr1;
            while(itr2 != NULL) {
                itr1 = itr2;
                itr2 = itr2 -> next;
                itr1 -> next = head;
                head = itr1;
            }
        }
    }
    return head;
}
