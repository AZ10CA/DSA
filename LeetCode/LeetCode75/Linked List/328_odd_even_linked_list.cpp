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
        if(!head)
            return nullptr;
        if(!head->next)
            return head;

        auto odd_start = head, even_start = head->next;
        auto even_start_cpy = even_start;
        while(even_start && even_start->next){
            odd_start->next = even_start->next;
            odd_start = odd_start->next;
            even_start->next = odd_start->next;
            even_start = even_start->next;
        }

        odd_start->next = even_start_cpy;

        return head;
    }
};