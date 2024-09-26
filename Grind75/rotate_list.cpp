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
    ListNode* rotateRight(ListNode* head, int k) {
        // Time: O(n), Space: O(1)
        if(!head || !head->next)
            return head;
        k %= size_of(head);

        if(k == 0)
            return head;
        // separate the last k elments from the other elements
        auto pointers = find_kth(head, k);
        ListNode *left_head = head, *left_tail = pointers[0],
                *right_head = pointers[1], *right_tail = pointers[2];

        // disconnect the two lists and connect the right list to the left
        left_tail->next = nullptr;
        right_tail->next = left_head;

        // the new head will be the right_head pointer
        return right_head;
    }

    int size_of(ListNode* head){
        int cnt = 0;

        while(head){
            cnt++;
            head = head->next;
        }

        return cnt;
    }

    vector<ListNode*> find_kth(ListNode* head, int k){
        ListNode* dummy = new ListNode();
        ListNode* slow = head, *fast = head;

        k--;
        dummy->next = slow;

        while(k--)
            fast = fast->next;

        while(fast->next){
            slow = slow->next;
            dummy = dummy->next;
            fast = fast->next;
        }


        return {dummy, slow, fast};
    }
};