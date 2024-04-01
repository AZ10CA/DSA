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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Time: O(n + m), Space: O(1)
        if(!list1 && !list2)
            return nullptr;

        auto fp = list1, sp = list2;
        ListNode* ptr = new ListNode();
        auto copy = ptr;

        while(fp && sp){
            if(fp->val < sp->val){
                ptr->next = fp;
                fp = fp->next;
            } else {
                ptr->next = sp;
                sp = sp->next;
            }
            ptr = ptr->next;
        }

        if(!fp)
            ptr->next = sp;

        if(!sp)
            ptr->next = fp;

        return copy->next;
    }
};