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
    ListNode* reverseList(ListNode* head) {
        // Time: O(n), Space: O(1)
        if(not head)
            return nullptr;

        ListNode* dummy = nullptr;

        while(head){
            auto next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
        }


        return dummy;
    }
};