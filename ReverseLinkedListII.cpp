#include <iostream>
#include <fstream>
#include "Listnode.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        head=dummy;
        for (int i=0; i<m-1; ++i) head=head->next;
        ListNode *tail(head->next), *cur(head->next->next);
        for (int i=m; i<n; ++i) {
            tail->next=cur->next;
            cur->next=head->next;
            head->next=cur;
            cur=tail->next;
        }
        return dummy->next;
    }
};