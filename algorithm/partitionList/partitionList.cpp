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
    void insertNode(ListNode*& itr1, ListNode*& itr3, ListNode*& itr4){
            if(itr3 != itr1){
                itr3 -> next = itr4 -> next;
                itr4 -> next = itr1 -> next;
                itr1 -> next = itr4;
                itr1 = itr4;
                itr4 = itr3 -> next;
            }
            else{
                itr3 = itr4;
                itr1 = itr4;
                itr4 = itr4 -> next;
            }
    }
    ListNode* partition(ListNode* head, int x) {
        if(head != NULL && head -> next != NULL){
            ListNode* itr1 = head;
            ListNode* itr3 = head;
            ListNode* itr4 = head;
            while(itr4 != NULL){
                if(itr4 -> val >= x){
                    itr3 = itr4;
                    itr4 = itr4 -> next;
                }
                else{
                    if(itr4 != head){
                        if(itr3 == head){
                            int tmp = itr3 -> val;
                            itr3 -> val = itr4 -> val;
                            itr4 -> val = tmp;
                            itr3 = itr4;
                            itr4 = itr4 -> next;
                        }
                        else{
                            itr3 -> next = itr4 -> next;
                            itr4 -> next = head;
                            head = itr4;
                            itr1 = itr4;
                            itr4 = itr3 -> next;
                        }
                    }
                    else{
                        itr3 = itr4;
                        itr4 = itr4 -> next;
                    }
                    break;
                }
            }
            while(itr4 != NULL){
                if(itr4 -> val < x){
                    insertNode(itr1,itr3,itr4);
                }
                else{
                    itr3 = itr4;
                    itr4 = itr4 -> next;
                }
            }
        }
        return head;
    }
};
