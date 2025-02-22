/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;

            if (fast == slow)
                break;
        }

        if (!fast || !fast -> next) return NULL;

        slow  = head;
        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }

        return slow;
    }
};
