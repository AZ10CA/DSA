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

        ListNode* prev = new ListNode(), *first = head, *second = head->next;
        ListNode* copy = prev;

        while(first && second){
            auto next = second->next;
            first->next = next;
            second->next = first;
            prev->next = second;

            prev = first;
            first = next;
            second = next ? next->next : nullptr;
        }


        return copy->next;
    }
};