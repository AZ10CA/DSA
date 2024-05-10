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
    ListNode* removeElements(ListNode* head, int val) {
        // Time: O(n), Space: O(1)
        auto prev = new ListNode(0);
        prev->next = head;
        auto current = head;
        auto head_cpy = prev;
        while(current){
            if(current->val == val){
                prev->next = nullptr;
                current = current->next;
            } else {
                prev->next = current;
                prev = current;
                current = current->next;
            }
        }

        return head_cpy->next;
    }
};