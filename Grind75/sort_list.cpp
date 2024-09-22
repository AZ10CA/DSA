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
    ListNode* sortList(ListNode* head) {
        // Time: O(nlogn), Space: O(logn)
        if(!head || !head->next)
            return head;

        auto middle_node = find_middle(head);
        auto right_head = middle_node->next;
        middle_node->next = nullptr;

        // divide to two halves
        auto left = sortList(head);
        auto right = sortList(right_head);

        // merge the halves
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* new_head = dummy;

        while(left && right){
            if(left->val < right->val){
                dummy->next = left;
                left = left->next;
            } else {
                dummy->next = right;
                right = right->next;
            }

            dummy = dummy->next;
        }

        if(left || right)
            dummy->next = left ? left : right;

        return new_head->next;
    }

    ListNode* find_middle(ListNode* head){
        if(!head || !head->next)
            return head;

        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};