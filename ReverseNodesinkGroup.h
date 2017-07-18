#include <iostream>
#include <fstream>
#include "Listnode.h"

class Solution {
public:
    ListNode* reverseList(ListNode *head, ListNode *end) {
        if(head==end) return head;
        ListNode *h = new ListNode(0);
        ListNode *se = nullptr, *in = head;
        while(in!=end){
            h->next = in;
            in = in->next;
            h->next->next = se;
            se = h->next;
        }
        delete h;
        return se;
    }

	ListNode* reverseKGroup(ListNode* pHead, int n_k) {
	    if(pHead==nullptr) return pHead;
		ListNode *pH = new ListNode(0);
	    ListNode *pBegin = pHead, *pEnd = pHead->next, *tmp = pH;
	    int n_len = 1;
	    while(pEnd!=nullptr){
	    	if(n_len != n_k){
	    		pEnd = pEnd->next;
	    		++n_len;
	    	}else{
	    		tmp->next = reverseList(pBegin, pEnd);
	    		tmp = pBegin;
	    		pBegin = pEnd;
	    		pEnd = pEnd->next;
	    		n_len = 1;
	    	}
	    }
	    if(n_len == n_k){
	        tmp->next = reverseList(pBegin, pEnd);
    		tmp = pBegin;
	    }else{
	        tmp->next = pBegin;
	    }
	    tmp = pH->next;
	    delete pH;
	    return tmp;
	}
};

int main(){

}