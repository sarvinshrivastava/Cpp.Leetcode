#include <iostream>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *head_rev = nullptr, *temp = head;

        while (temp != nullptr) {
            ListNode* newNode = new ListNode(temp->val);
            newNode->next = head_rev;
            head_rev = newNode;
            temp = temp->next;
        }

        while (head != nullptr && head_rev != nullptr) {
            if (head->val != head_rev->val) {
                return false;
            }
            head = head->next;
            head_rev = head_rev->next;
        }

        return true;
    }
};
