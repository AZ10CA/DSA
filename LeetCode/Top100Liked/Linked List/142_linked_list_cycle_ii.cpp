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
    ListNode *detectCycle(ListNode *head) {
        // Time: O(n), Space: O(1)
        if(!head || !head->next)
            return nullptr;
        ListNode* slow = head, *fast = head->next->next;
        while(fast && fast->next){
            if(fast == slow){
                // determine the size of the cycle
                auto ptr = fast->next;
                auto size = 1;
                while(ptr != slow){
                    ptr = ptr->next;
                    size++;
                }

                slow = head, fast = head;
                for(int i = 0; i < size; i++)
                    fast = fast->next;

                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return nullptr;
    }
};