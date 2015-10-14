#include "sortList.cpp"
#include <iostream>
using namespace std;

void printList(ListNode* head){
    while(head != NULL){
        cout<< head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

int main() {
    //create Linked List
    int a[10] = {1,5,-1,1,2,1,4,3,2,3};
    ListNode* head = new ListNode(a[0]);
    ListNode* tail = head;
    for(int i = 1; i < 10; i++){
        tail -> next = new ListNode(a[i]);
        tail = tail -> next;
    }
    //sort Linked List
    cout << " before sort :"<< endl;
    printList(head);
    Solution sol;
    sol.sortList(head);
    cout <<" after sort :"<<endl;
    printList(head);
    // delete Linked List
    ListNode* itr = head;
    while(head != NULL){
        head = itr -> next;
        delete itr;
        itr = head;
    }
    return 0;
}
