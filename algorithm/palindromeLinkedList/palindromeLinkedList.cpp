bool isPalindrome(ListNode* head){
    int cnt = 0;
    ListNode* itr = head;
    while(itr != NULL){
        cnt++;
        itr = itr -> next;
    }
    if(cnt <= 1)
        return true;
    else if(cnt <= 6){
        vector<int> tmp(6,0);
        int i = 0;
        itr = head;
        while( itr != NULL){
            tmp[i] = itr -> val;
            i++;
            itr = itr -> next;
        }
        int j = 0;
        int k = i - 1;
        while( k > j){
            if(tmp[k] != tmp[j])
                return false;
            k--;
            j++;
        }
        return true;
    }
    else{
        ListNode* itr1 = head;
        for(int i = 0; i < (cnt + 1)/2; i++){
            itr1 = itr1 -> next;
        }
        //inverse first part of linked list
        ListNode* itra = head;
        ListNode* itrb = head -> next;
        ListNode* itrc = head -> next -> next;
        head -> next = NULL;
        for(int j = 1; j < cnt / 2 ; j++){
            itrb -> next = itra;
            itra = itrb;
            itrb = itrc;
            itrc = itrc -> next;
        }
        for(int j = 0; j< cnt/2; j++){
            if(itr1 -> val != itra -> val){
                return false;
            }
            itr1 = itr1 -> next;
            itra = itra -> next;
        }
        return true;
    }
}

