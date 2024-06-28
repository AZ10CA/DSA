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
    ListNode* deleteDuplicates(ListNode* head) {
        // Time: O(n), Space: O(1)
        if(not head)
            return nullptr;

        if(not head->next)
            return head;

        auto start = head;
        auto current = head->next;
        auto copy = head;

        while(current){
            if(current->val == start->val){
                current = current->next;
            } else {
                start->next = current;
                start = current;
                current = current->next;
            }

        }

        start->next = nullptr;

        return copy;
    }
};