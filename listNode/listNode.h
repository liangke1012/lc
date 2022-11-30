//
// Created by liangke on 2022/11/30.
//

#ifndef LC_LISTNODE_H
#define LC_LISTNODE_H
struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif //LC_LISTNODE_H
