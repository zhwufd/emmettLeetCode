#include <cstdlib>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};
class Solution {
    public:
        void swap( ListNode* itr1, ListNode* itr2){
            if(itr1 != itr2){
                int tmp = itr1 -> val;
                itr1 -> val = itr2 -> val;
                itr2 -> val = tmp;
            }
        }
        void mySort(ListNode* itr1, ListNode* itr2){
            if(itr1 -> next == itr2){
                if(itr1 -> val > itr2 -> val)
                    swap(itr1,itr2);
            }
            else{
                ListNode* itra = itr1;
                ListNode* itrb = itr1;
                ListNode* itrc = itr1;
                int k = itr2 -> val;
                while( itrb != itr2 ){
                    if(itrb -> val < k ){
                        swap(itrb,itra);
                        itrc = itra;
                        itra = itra -> next;
                    }
                    itrb = itrb -> next;
                }
                itrb = itra;
                while(itrb != itr2 ){
                    if(itrb -> val == k){
                        swap(itrb,itra);
                        itra = itra -> next;
                    }
                    itrb = itrb -> next;
                }
                swap(itra, itr2);
                if(itr1 != itrc){
                    mySort(itr1, itrc);
                }
                if(itra != itr2){
                    if(itra -> next != itr2)
                        mySort(itra -> next, itr2);
                }
            }
        }
        ListNode* sortList(ListNode* head){
            if(head != NULL){
                ListNode* itr1 = head;
                ListNode* itr2 = head;
                while(itr2 -> next != NULL){
                    itr2 = itr2 -> next;
                }
                if(itr1 != itr2)
                    mySort(itr1, itr2);
            }
            return head;
        }
};
