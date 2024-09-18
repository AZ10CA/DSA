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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Time: O(n + m), Space: O(n)
        ListNode* result = new ListNode();
        ListNode* copy = result;

        bool carry = false;
        while(l1 || l2){
            auto first = l1 ? l1->val : 0;
            auto second = l2 ? l2->val : 0;
            auto sum = first + second + carry;

            carry = sum > 9;
            sum %= 10;

            result->val = sum;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;

            if(l1 || l2){
                result->next = new ListNode();
                result = result->next;
            }
        }

        if(carry)
            result->next = new ListNode(1);

        return copy;
    }
};