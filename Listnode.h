#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

	static ListNode* initLN(const vector<int> &num){
		if(num.size()==0) return nullptr;
		ListNode *head = new ListNode(num[0]), *p = head;
		for(auto iter=num.cbegin()+1;iter!=num.cend();++iter){
			p->next = new ListNode(*iter);
			p = p->next;
		}
		return head;
	}
};

#endif