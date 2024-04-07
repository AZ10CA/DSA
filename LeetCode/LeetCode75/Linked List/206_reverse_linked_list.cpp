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
    ListNode* reverseList(ListNode* head) {
        // Time: O(n), Space: O(1)
        if(!head)
            return nullptr;

        if(!head->next)
            return head;

        ListNode* prev = nullptr;
        auto ptr = head;
        auto result = ptr;
        while(ptr){
            auto next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            result = ptr;
            ptr = next;
        }

        return result;
    }
};