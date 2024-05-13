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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Time: O(n), Space: O(n)
        auto ptr = head;
        while(ptr && ptr->next){
            auto next = ptr->next;
            auto gcd = std::gcd(ptr->val, next->val);
            insert_after(ptr, gcd);
            ptr = next;
        }

        return head;
    }

    void insert_after(ListNode* node, int value){
        auto new_node = new ListNode(value);
        auto next = node->next;
        node->next = new_node;
        new_node->next = next;
    }
};