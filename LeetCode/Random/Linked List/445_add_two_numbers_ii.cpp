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
        l1 = iterative_reverse(l1);
        l2 = iterative_reverse(l2);

        auto writer = new ListNode();
        auto writer_cpy = writer;

        bool has_carry = false;
        while(l1 || l2){
            auto first_digit = l1 ? l1->val : 0;
            auto second_digit = l2 ? l2->val : 0;

            auto sum = first_digit + second_digit + has_carry;
            has_carry = sum > 9;
            sum = sum % 10;

            writer->next = new ListNode(sum);

            writer = writer->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        if(has_carry){
            writer->next = new ListNode(1);
            writer = writer->next;
        }

        writer_cpy = writer_cpy->next;

        auto head = iterative_reverse(writer_cpy);
        return head;
    }

    ListNode* recursive_reverse(ListNode* list, ListNode* parent){
        // Time: O(n), Space: O(n)
        if(list == nullptr)
            return parent;

        auto last_node = recursive_reverse(list->next, list);

        list->next = parent;

        return last_node;
    }

    ListNode* iterative_reverse(ListNode* list){
        // Time: O(n), Space: O(1)
        ListNode* dummy = nullptr;
        auto ptr = list;

        while(ptr){
            auto next_node = ptr->next;
            ptr->next = dummy;
            dummy = ptr;

            ptr = next_node;
        }

        return dummy;
    }
};