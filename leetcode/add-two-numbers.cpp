//
// https://leetcode.com/problems/add-two-numbers/
//

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* traversal_node = new ListNode(0);
        ListNode* return_HEADER = traversal_node;

        int carry = 0;
        int sum = 0;

        while (l1 || l2 || carry) {
            sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = sum / 10;

            traversal_node->next = new ListNode(sum % 10);
            traversal_node = traversal_node->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return return_HEADER->next;
    }
};

void print(ListNode* v) {
    while (v) {
        std::cout << v->val << " ";
        v = v->next;
    }
}

int main() {
    Solution s;

    ListNode* a = new ListNode(9);
    a->next = new ListNode(4);
    a->next->next = new ListNode(3);

    ListNode* b = new ListNode(9);
    b->next = new ListNode(9);
    b->next->next = new ListNode(9);

    ListNode* result = s.addTwoNumbers(a,b);

    print(result);
    return 0;
}