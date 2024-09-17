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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Time: O(n), Space: O(1)
        ListNode* dummy = new ListNode(), *left = head, *right = head;
        dummy->next = left;

        for(int i = 0; i < n - 1; i++)
            right = right->next;

        // we are removing the first element
        if(!right->next)
            return head->next;

        while(right->next){
            dummy = dummy->next;
            left = left->next;
            right = right->next;
        }

        dummy->next = left->next;


        return head;
    }
};