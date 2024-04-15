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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto result = mergeSort(lists, 0, lists.size() - 1);
        return result;
    }

    ListNode* mergeSort(const vector<ListNode*>& lists, int start, int end){
        // Time: O(nlogk), Space: O(logk)
        if(start > end)
            return nullptr;
        if(start == end)
            return lists[start];
        auto middle = start + (end - start) / 2;
        auto left_side = mergeSort(lists, start, middle);
        auto right_side = mergeSort(lists, middle + 1, end);

        return merge(left_side, right_side);
    }
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* result = new ListNode();
        auto head_copy = result;
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
        return head_copy->next;
    }
};