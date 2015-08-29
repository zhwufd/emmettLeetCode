#include "addTwoNumbers.cpp"
int main() {
    ListNode n1 = ListNode(0);
    ListNode* l1 = &n1;
    ListNode n2 = ListNode(0);
    ListNode* l2 = &n2;
    Solution s;
    ListNode* l3 = s.addTwoNumbers(l1, l2);
    int v = l3 -> val;
    return 0;
}
