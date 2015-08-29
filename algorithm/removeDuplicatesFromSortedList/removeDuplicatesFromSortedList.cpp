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
            map<int,bool> m;
            m.insert( pair<int,bool>(head -> val, true) );
            while(itr2 != NULL){
                if(m.find(itr2 -> val) != m.end()){
                    itr1 -> next = itr2 -> next;
                    delete itr2;
                    itr2 = itr1 -> next;
                }
                else{
                    m.insert(pair<int,bool>(itr2 -> val, true));
                    itr1 = itr2;
                    itr2 = itr2 -> next;
                }
            }
            return head;
        }
    }
};
