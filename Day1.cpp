// Solution for 2807
class Solution {
public:
    int gcd(int a, int b) {
        int m = (a > b) ? b : a;
        while (m > 0) {
            if (a % m == 0 && b % m == 0) {
                return m;
            }
            m--;
        }
        return 1;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head -> next == NULL) {
            return head;
        }
        else {
            ListNode * pre = head, * nex = head -> next;

            while (nex != NULL) {
                int e = gcd(pre -> val, nex -> val);

                ListNode* element = new ListNode(e);
                element -> next = nex;
                pre -> next = element;

                pre = nex;
                nex = nex -> next;
            }

            return head;
        }
    }
};
