#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* reverseBetween(ListNode* head, int m, int n){
    ListNode* fake = new ListNode(0);
    fake -> next = head;
    head = fake;
    if(m < n){
        int i = 1;
        ListNode* itr1 = head;
        while( i < m){
            itr1 = itr1 -> next;
            i++;
        }
        i = 0;
        ListNode* itr2 = head;
        while(i < n){
            itr2 = itr2 -> next;
            i++;
        }
        ListNode* itr3 = itr1 -> next;
        ListNode* itr4 = itr2 -> next;
        while(itr3 != itr2){
            // move element
            itr1 -> next = itr3 -> next;
            itr3 -> next = itr4;
            itr2 -> next = itr3;
            // update itr
            itr3 = itr1 -> next;
            itr4 = itr2 -> next;
        }
    }
    //delete fake head
    head = fake -> next;
    delete fake;
    return head;
}

void printLinkedList(ListNode* head){
    for(ListNode* itr = head; itr != NULL; itr = itr -> next){
        cout << itr -> val <<"-";
    }
    cout << endl;
}

int main(){
    int m = 2;
    int n = 3;
    ListNode ln(3);
    ListNode* head = &ln;
    ListNode ln1(5);
    ln.next = &ln1;
    ListNode ln2(10);
    ln1.next = &ln2;
    printLinkedList(head);
    head = reverseBetween(head, m, n);
    printLinkedList(head);
    return 0;
}
