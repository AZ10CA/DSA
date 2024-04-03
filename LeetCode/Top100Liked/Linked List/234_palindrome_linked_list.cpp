/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;

        auto middle = findMiddleNode(head);
        auto tail = findTailNode(head);

        reverseList(middle->next);

        while (tail != nullptr) {
            if (head->val != tail->val)
                return false;
            head = head->next;
            tail = tail->next;
        }

        return true;
    }

    ListNode *findTailNode(ListNode *node) {
        while (node && node->next)
            node = node->next;
        return node;
    }

    ListNode *findMiddleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        while (head) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev; // New head of the reversed list
    }
};
