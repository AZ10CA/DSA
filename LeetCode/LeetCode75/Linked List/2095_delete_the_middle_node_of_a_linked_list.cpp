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
    ListNode* deleteMiddle(ListNode* head) {
        // Time: O(n), Space: O(1)
        if(!head || !head->next)
            return nullptr;

        auto middle = getMiddleNode(head);
        auto before_middle = node_before(head, middle);
        before_middle->next = middle->next;
        return head;
    }

    ListNode* node_before(ListNode* start, ListNode* target){
        while(start->next != target)
            start = start->next;
        return start;
    }

    ListNode* getMiddleNode(ListNode* head){
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};