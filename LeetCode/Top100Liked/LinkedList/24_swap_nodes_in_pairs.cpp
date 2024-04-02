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
    ListNode* swapPairs(ListNode* head) {
        // Time: O(n), Space: O(1)
        if(!head || !head->next)
            return head;

        auto first = head, second = head->next;
        auto result = head->next;

        ListNode* prev_tail = nullptr;
        while(first && second){
            auto next = second->next;
            second->next = first;
            first->next = next;
            if(prev_tail)
                prev_tail->next = second;
            prev_tail = first;
            first = next;
            second = next ? next->next : nullptr;
        }

        return result;
    }
};