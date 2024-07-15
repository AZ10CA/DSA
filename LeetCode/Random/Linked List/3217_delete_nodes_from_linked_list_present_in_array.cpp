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
    ListNode* modifiedList(vector<int>& n, ListNode* head) {
        // Time: O(n), Space: O(n)
        unordered_set<int> nums(n.begin(), n.end());
        auto ptr = head;
        ListNode* prev = nullptr;
        ListNode* head_cpy = nullptr;

        while(ptr){
            auto exists = nums.find(ptr->val) != nums.end();
            if(exists){
                ptr = ptr->next;
                if(prev)
                    prev->next = nullptr;
            }
            else {
                if(not prev){
                    prev = ptr;
                    head_cpy = prev;
                } else {
                    prev->next = ptr;
                    prev = prev->next;
                }
                ptr = ptr->next;
            }
        }

        return head_cpy;
    }
};