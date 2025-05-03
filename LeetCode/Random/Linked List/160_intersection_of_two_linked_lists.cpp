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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Time: O(n + m), Space: O(1)
        int a_size = size_of(headA), b_size = size_of(headB);
        int deficit = std::abs(a_size - b_size);

        if(a_size > b_size){
            for(int i = 0; i < deficit; i++)
                headA = headA->next;
        } else {
            for(int i = 0; i < deficit; i++)
                headB = headB->next;
        }

        while(headA){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }

    int size_of(ListNode* node){
        int size = 0;

        while(node){
            size++;
            node = node->next;
        }

        return size;
    }
};