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
    ListNode* sortList(ListNode* head) {
        // Time: O(nlogn), Space: O(1)
        if(!head || !head->next)
            return head;

        // find the middle node
        auto middle = find_middle(head);
        auto temp = middle->next;
        middle->next = nullptr;
        auto left_side = sortList(head);
        auto right_side = sortList(temp);

        return merge(left_side, right_side);
    }

    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* result = new ListNode();
        auto head_cpy = result;
        while(first && second){
            if(first->val < second->val){
                result->next = first;
                first = first->next;
            } else {
                result->next = second;
                second = second->next;
            }
            result = result->next;
        }

        result->next = first ? first : second;
        return head_cpy->next;
    }

    ListNode* find_middle(ListNode* node){
        ListNode* slow = node, *fast = node;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};