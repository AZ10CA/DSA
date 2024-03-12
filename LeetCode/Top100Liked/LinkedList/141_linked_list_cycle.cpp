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
    bool hasCycle(ListNode *head) {
        // Time: O(n), Space: O(1)
        if (!head || !head->next)
            return false;

        auto fast = head->next, slow = head;
        while (fast->next && fast->next->next) {
            if (fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};