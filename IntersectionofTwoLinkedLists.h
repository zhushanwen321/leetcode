/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Listnode.h"
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(headA == nullptr || headB == nullptr) return nullptr;
    	auto pA = headA, pB = headB;
    	int n_len = 0;
    	while(pA->next != nullptr) {pA = pA->next; ++n_len;}
    	while(pB->next != nullptr) {pB = pB->next; --n_len;}
    	if(pA != pB) return nullptr;
    	pA = headA, pB = headB;
    	while(n_len > 0) {pA = pA->next; --n_len;}
    	while(0 > n_len) {pB = pB->next; ++n_len;}
    	while(pA != pB){
    		pA = pA->next;
    		pB = pB->next;
    	}
    	return pA;
    }
};