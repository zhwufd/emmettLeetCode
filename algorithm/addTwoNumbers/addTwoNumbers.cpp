#include "stddef.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* itr1 = l1;
            ListNode* itr2 = l2;
            if(itr1 == NULL && itr2 == NULL)
                return NULL;
            int a1 = 0;
            int a2 = 0;
            int sum = 0;
            int res = 0;
            if(itr1 != NULL) {
                a1 = itr1 -> val;
                itr1 = itr1 -> next;
            }
            if(itr2 != NULL) {
                a2 = itr2 -> val;
                itr2 = itr2 -> next;
            }
            sum = a1 + a2;
            if(sum > 9) {
                sum = sum%10;
                ++res;
            }
            ListNode* head = new ListNode(sum);
            ListNode* end = head;
            while(itr1 != NULL || itr2 != NULL) {
                a1 = 0;
                a2 = 0;
                if(itr1 != NULL) {
                    a1 = itr1 -> val;
                    itr1 = itr1 -> next;
                }
                if(itr2 != NULL) {
                    a2 = itr2 -> val;
                    itr2 = itr2 -> next;
                }
                sum = a1 + a2 + res;
                res = 0;
                if(sum > 9) {
                    sum = sum%10;
                    ++res;
                }
                end -> next = new ListNode(sum);
                end = end -> next;
            }
            if(res > 0 ){
                end -> next = new ListNode(res);
            }
            return head;
        }
};
