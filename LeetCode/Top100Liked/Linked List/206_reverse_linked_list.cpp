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
    ListNode *reverseList(ListNode *head) {
        // Time & Space: O(n)
        vector<int> array;
        auto ptr = head;

        while (ptr) {
            array.push_back(ptr->val);
            ptr = ptr->next;
        }

        std::reverse(array.begin(), array.end());
        if (array.empty())
            return nullptr;

        ptr = new ListNode(array[0]);
        auto head_copy = ptr;

        for (int i = 1; i < array.size(); i++) {
            ptr->next = new ListNode(array[i]);
            ptr = ptr->next;
        }

        return head_copy;
    }
};