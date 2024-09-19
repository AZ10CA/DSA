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
    ListNode* oddEvenList(ListNode* head) {
        // Time: O(n), Space: O(1)
        if(!head || !head->next)
            return head;

        ListNode *odd_pointer = head, *even_pointer = head->next;
        auto even_pointer_head = even_pointer;
        auto odd_pointer_head = odd_pointer;

        while(even_pointer && even_pointer->next){
            odd_pointer->next = even_pointer->next;
            even_pointer->next = even_pointer->next->next;
            even_pointer = even_pointer->next;
            odd_pointer = odd_pointer->next;
        }

        odd_pointer->next = even_pointer_head;

        return odd_pointer_head;
    }
};