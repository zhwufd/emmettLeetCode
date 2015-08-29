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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        else if( head -> next == NULL)
            return head;
        else{
            ListNode* itr2 = head -> next;
            ListNode* itr1 = head;
            while(itr2 != NULL){
                if(itr2 -> val == itr1 -> val){
                    itr1 -> next = itr2 -> next;
                    delete itr2;
                    itr2 = itr1 -> next;
                }
                else{
                    itr1 = itr2;
                    itr2 = itr2 -> next;
                }
            }
            return head;
        }
    }
};
