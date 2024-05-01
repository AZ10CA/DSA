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
        if(!head)
            return head;
        auto size = size_of(head);
        k %= size;

        if(size <= 1 || k == 0)
            return head;

        auto new_last_node = nth_from_last(head, k + 1);
        auto last_node = get_last_node(head);
        auto new_start = new_last_node->next;

        new_last_node->next = nullptr;

        last_node->next = head;
        return new_start;
    }

    ListNode* get_last_node(ListNode* head){
        while(head->next)
            head = head->next;
        return head;
    }

    int size_of(ListNode* head){
        int size = 0;

        while(head){
            size++;
            head = head->next;
        }

        return size;
    }

    ListNode* nth_from_last(ListNode* head, int nth){
        auto fp = head, sp = head;
        nth--;
        while(nth--)
            sp = sp->next;

        while(sp->next){
            fp = fp->next;
            sp = sp->next;
        }

        return fp;

    }
};