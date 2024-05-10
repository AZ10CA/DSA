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
    int getDecimalValue(ListNode* head) {
        // Time: O(n), Space: O(1)
        if(!head)
            return 0;

        auto size = size_of(head);
        int power = size - 1;
        int result = 0;
        while(head){
            result += (1 << power) * head->val;
            head = head->next;
            power--;
        }

        return result;
    }

    int size_of(ListNode* head){
        auto size = 0;

        while(head){
            size++;
            head = head->next;
        }

        return size;
    }
};