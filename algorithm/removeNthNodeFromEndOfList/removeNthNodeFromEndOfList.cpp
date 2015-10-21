/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode* itr1 = head;
        ListNode* itr2 = head;
        while(itr1 != NULL && i <= n){
            i++;
            itr1 = itr1 -> next;
        }
        if(itr1 == NULL && i == n){
            //remove first element
            ListNode* tmp = head;
            head = head -> next;
            delete tmp;
            return head;
        }
        while(itr1 != NULL){
            itr1 = itr1 -> next;
            itr2 = itr2 -> next;
        }
        ListNode* tmp = itr2 -> next;
        itr2->next = tmp ->next;
        delete tmp;
        return head;
    }
};
