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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        // Time: O(n), Space: O(n)
        unordered_map<int, int> ft;

        auto ptr = head;
        while(ptr){
            auto number = ptr->val;
            ft[number]++;
            ptr = ptr->next;
        }

        ptr = head;
        auto writer = new ListNode();
        auto result = writer;

        while(ptr){
            auto number = ptr->val;
            if(ft[number] == 1){
                writer->next = ptr;
                writer = writer->next;
            }

            ptr = ptr->next;
        }

        writer->next = nullptr;

        return result->next;
    }
};