/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        return solution_2(head);
    }

    bool solution_1(ListNode* head){
        // Time: O(n), Space: O(n)
        // Using Hash Set
        unordered_set<ListNode*> addresses;
        while(head){
            if(addresses.find(head) != addresses.end())
                return true;
            addresses.insert(head);
            head = head->next;
        }

        return false;
    }

    bool solution_2(ListNode* head){
        // Time: O(n), Space: O(1)
        auto slow = head;
        auto fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }

        return false;
    }
};