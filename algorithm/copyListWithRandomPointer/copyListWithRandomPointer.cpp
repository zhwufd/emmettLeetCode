/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        int cnt = 0;
        RandomListNode* itr1 = head;
        while(itr1 != NULL){
            cnt++;
            itr1 = itr1 -> next;
        }
        vector<int> val(cnt,0);
        itr1 = head;
        int i = 0;
        while(itr1 != NULL){
            val[i] = itr1 -> label;
            itr1 -> label = i;
            i++;
            itr1 = itr1 -> next;
        }
        vector<int> mp(cnt,-1);
        itr1 = head;
        i = 0;
        while(itr1 != NULL){
            if(itr1 -> random != NULL)
                mp[i] = itr1 -> random -> label;
            i++;
            itr1 = itr1 -> next;
        }
        itr1 = head;
        RandomListNode* hd = NULL;
        i = 0;
        RandomListNode* itr2 = NULL;
        vector<RandomListNode*> mptr(cnt,NULL);
        if(itr1 != NULL){
            hd = new RandomListNode(i);
            mptr[i] = hd;
            i++;
            itr1 = itr1 -> next;
            itr2 = hd;
        }
        while(itr1 != NULL){
            itr2 -> next = new RandomListNode(i);
            mptr[i] = itr2 -> next;
            i++;
            itr2 = itr2 -> next;
            itr1 = itr1 -> next;
        }
        itr2 = hd;
        while(itr2 != NULL){
            if(mp[itr2 -> label] != -1)
                itr2 -> random = mptr[mp[itr2 -> label]];
            itr2 = itr2 -> next;
        }
        itr2 = hd;
        i = 0;
        while(itr2 != NULL){
            itr2 -> label = val[i];
            i++;
            itr2 = itr2 -> next;
        }
        itr1 = head;
        i = 0;
        while(itr1 != NULL){
            itr1 -> label = val[i];
            i++;
            itr1 = itr1 -> next;
        }
        return hd;
    }
};
