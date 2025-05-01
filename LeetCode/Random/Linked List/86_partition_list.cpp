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
    ListNode* partition(ListNode* head, int x) {
        // Time: O(n), Space: O(1)
        auto left_head = new ListNode();
        auto right_head = new ListNode();
        auto left_copy = left_head;
        auto right_copy = right_head;

        auto ptr = head;
        while(ptr){
            if(ptr->val < x){
                left_head->next = ptr;
                left_head = left_head->next;
            } else {
                right_head->next = ptr;
                right_head = right_head->next;
            }

            ptr = ptr->next;
        }

        right_head->next = nullptr;
        left_head->next = right_copy->next;

        return left_copy->next;
    }
};