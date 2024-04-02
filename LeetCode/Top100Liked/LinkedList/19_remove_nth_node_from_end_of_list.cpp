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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Time: O(n), Space: O(1)
        auto size = size_of(head);
        auto from_beginning = size - n;

        if(from_beginning == 0)
            return head->next;

        ListNode* prev = nullptr, *ptr = head;
        while(from_beginning--){
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = ptr->next;
        ptr->next = nullptr;

        return head;
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