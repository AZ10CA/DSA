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
        // Time: O(n + m), Space: O(n + m)
        auto fp = l1, sp = l2;
        auto add_one = false;
        auto builder = new ListNode();
        auto cp = builder;

        while(fp || sp){
            auto first_digit = fp ? fp->val : 0;
            auto second_digit = sp ? sp->val : 0;
            auto sum = first_digit + second_digit + add_one;
            add_one = false;
            if(sum >= 10){
                sum -= 10;
                add_one = true;
            }
            builder->next = new ListNode(sum);
            builder = builder->next;
            fp = fp ? fp->next : nullptr;
            sp = sp ? sp->next : nullptr;
        }

        if(add_one)
            builder->next = new ListNode(1);

        return cp->next;
    }
};