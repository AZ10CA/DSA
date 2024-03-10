/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_set>

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Time: O(m + n), Space: O(m)
        unordered_set<ListNode *> pointers;
        auto ptr = headA;
        while (ptr) {
            pointers.insert(ptr);
            ptr = ptr->next;
        }

        ptr = headB;
        while (ptr) {
            auto pos = pointers.find(ptr);
            if (pos != pointers.end())
                return ptr;
            ptr = ptr->next;
        }

        return nullptr;
    }
};