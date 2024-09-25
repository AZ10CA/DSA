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
    void reorderList(ListNode* head) {
        // Time: O(n), Space: O(1)
        // divide into two halves
        if(!head || !head->next)
            return;

        auto middle_node = find_middle(head);
        auto right_head = middle_node->next;
        auto left_head = head;

        // disconnect the two linked lists
        middle_node->next = nullptr;

        // reverse the right half
        right_head = reverse(right_head);

        // select elements from both lists alternatively
        bool take_first = true;
        ListNode* dummy = new ListNode();
        auto result = dummy;

        while(left_head || right_head){
            if(take_first){
                dummy->next = left_head;
                left_head = left_head->next;
            } else {
                dummy->next = right_head;
                right_head = right_head->next;
            }

            take_first = !take_first;
            dummy = dummy->next;
        }

        head = result->next;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        auto ptr = head;
        while(ptr){
            auto next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }

        return prev;
    }

    ListNode* find_middle(ListNode* head){
        auto *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};