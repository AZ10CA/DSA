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
    void deleteNode(ListNode* node) {
        // Time: O(n), Space: O(1)
        auto prev = node;
        while(node->next){
            auto next = node->next;
            node->val = next->val;
            prev = node;
            node = next;
        }

        prev->next = nullptr;
    }
};