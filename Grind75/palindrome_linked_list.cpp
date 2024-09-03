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
    bool isPalindrome(ListNode* head) {
        // Time: O(n), Space: O(1)
        // handle basic edge cases
        auto size = get_size(head);
        if(size < 2)
            return true;

        // phase 1: find the middle node
        auto middle_node = find_middle(head);

        // phase 2: reverse the second half
        auto right = reverse(middle_node->next);
        auto left = head;
        middle_node->next = nullptr;

        // phase 3: compare the two halves
        while(left && right){
            if(left->val != right->val)
                return false;

            left = left->next;
            right = right->next;
        }

        return true;
    }

    int get_size(ListNode* head){
        // Time: O(n), Space: O(1)
        int cnt = 0;

        while(head){
            cnt++;
            head = head->next;
        }

        return cnt;
    }

    ListNode* find_middle(ListNode* head){
        // Time: O(n), Space: O(1)
        auto slow = head;
        auto fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        // Time: O(n), Space: O(1)
        ListNode* dummy = nullptr;
        ListNode* ptr = head;

        while(ptr){
            auto next_node = ptr->next;
            ptr->next = dummy;
            dummy = ptr;
            ptr = next_node;
        }

        return dummy;
    }
};