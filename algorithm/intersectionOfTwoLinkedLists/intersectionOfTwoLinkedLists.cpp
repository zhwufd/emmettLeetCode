ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    int lenA =0, lenB = 0;
    ListNode *itr = headA;
    for(;itr != NULL; itr = itr -> next)
        lenA++;
    itr = headB;
    for(;itr != NULL; itr = itr -> next)
        lenB++;
    bool flagA = false;
    int lenDif = lenB - lenA;
    if(lenA > lenB){
        flagA = true;
        lenDif = -lenDif;
    }
    ListNode *itrA = headA;
    ListNode *itrB = headB;
    if(flagA){
        for(int i = 0; i < lenDif; i++)
            itrA = itrA -> next;
    }
    else{
        for(int i = 0; i < lenDif; i++)
            itrB = itrB -> next;
    }
    while(itrA != NULL && itrB != NULL && itrA != itrB){
        itrA = itrA -> next;
        itrB = itrB -> next;
    }
    return itrA;
}
