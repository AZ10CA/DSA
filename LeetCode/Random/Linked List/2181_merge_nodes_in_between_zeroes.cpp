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
    ListNode* mergeNodes(ListNode* head) {
        // Time: O(n), Space: O(n)
        auto ptr = head;
        auto new_head = new ListNode();
        auto cpy = new_head;
        while(ptr){
            auto sum = 0;
            while(ptr->val != 0){
                sum += ptr->val;
                ptr = ptr->next;
            }
            new_head->next = new ListNode(sum);
            new_head = new_head->next;
            ptr = ptr->next;
        }

        return cpy->next->next;
    }
};