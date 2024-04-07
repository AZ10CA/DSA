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
    int pairSum(ListNode* head) {
        // Time: O(n), Space: O(1)
        if(!head)
            return 0;
        auto max_sum = 0;
        // find the middle node
        auto middle = getMiddleNode(head);
        // disconnect it from the second half
        auto left_half = head, right_half = middle->next;
        middle->next = nullptr;
        // reverse the second half
        auto new_right_half = reverseList(right_half);
        // find the max twin sum
        auto left = left_half, right = new_right_half;
        while(left){
            auto sum = left->val + right->val;
            right = right->next;
            left = left->next;
            max_sum = std::max(max_sum, sum);
        }

        return max_sum;
    }

    ListNode* reverseList(ListNode* node){
        ListNode* prev = nullptr;
        auto result = node;
        while(node){
            auto next = node->next;
            node->next = prev;
            prev = node;
            result = node;
            node = next;
        }

        return result;
    }

    ListNode* getMiddleNode(ListNode* node){
        auto slow = node, fast = node;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};