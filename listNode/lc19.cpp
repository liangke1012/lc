//
// Created by liangke on 2022/11/30.
//
#include <iostream>
#include "listNode.h"
using namespace std;
ListNode* removeNthFromEnd(ListNode* head, int n);
ListNode* removeNthFromEnd(ListNode* head, int n){
     ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* slow = dummyHead;
    ListNode* fast = dummyHead;
    while(n-- & fast != nullptr){
        fast = fast->next;
    }
    fast = fast->next;
    while(fast!= nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next = slow->next->next;
    return dummyHead->next;
}