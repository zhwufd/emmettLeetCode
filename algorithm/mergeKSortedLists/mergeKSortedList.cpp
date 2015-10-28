struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class mycomp {
    public:
        bool operator()(const ListNode* lhs, const ListNode* rhs) const{
            return (lhs!=NULL && rhs!=NULL)?(lhs -> val) > (rhs -> val):false;
        }
};
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode* head = NULL;
            ListNode* tail = NULL;
            priority_queue<ListNode*,vector<ListNode*>,mycomp> pq;
            int n = lists.size();
            for(int i = 0; i < n; i++){
                if(lists[i] != NULL)
                    pq.push(lists[i]);
            }
            while(!pq.empty()){
                ListNode* t = pq.top();
                if(head == NULL){
                    head = new ListNode(t -> val);
                    tail = head;
                }
                else{
                    tail -> next = new ListNode(t -> val);
                    tail = tail -> next;
                }
                pq.pop();
                if(t -> next != NULL)
                    pq.push(t -> next);
            }
            return head;
        }
};
