class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        int v1 = l1 -> val;
        int v2 = l2 -> val;
        ListNode* head;
        if( v1 > v2){
            head = new ListNode(v2);
            l2 = l2 -> next;
        }
        else{
            head = new ListNode(v1);
            l1 = l1 -> next;
        }
        ListNode* end = head;
        while(l1 != NULL && l2 != NULL){
            v1 = l1 -> val;
            v2 = l2 -> val;
            if(v1 > v2){
                end -> next = new ListNode(v2);
                l2 = l2 -> next;
            }
            else{
                end -> next = new ListNode(v1);
                l1 = l1 -> next;
            }
            end = end -> next;
        }
        if(l2 == NULL){
            while(l1 != NULL){
                v1 = l1 -> val;
                end -> next = new ListNode(v1);
                l1 = l1 -> next;
                end = end -> next;
            }
        }
        else {
            while(l2 != NULL){
                v2 = l2 -> val;
                end -> next = new ListNode(v2);
                l2 = l2 -> next;
                end = end -> next;
            }
        }
        return head;
    }
};
