//
// Created by liangke on 2022/10/24.
//
#include <iostream>
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode(3);
    ListNode* node = addTwoNumbers(l1,l2);
    cout << node->val << " " << node->next->val << " " << node->next->next->val <<endl;
    return 0;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head;
    ListNode* node = new ListNode();
    head = node;
    int key =0;
    while(l1 != NULL || l2 != NULL) {
        int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val);
        node->next = new ListNode((sum + key) % 10);
        node=node->next;//移动链表
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        key=(sum+key)/10;//更新是否需要进位
    }
    if(key!=0){
        node->next = new ListNode(key);

    }
    return head->next;
}