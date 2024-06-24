class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        // Time: O(n), Space: O(n)
        list<int> li;
        for(int i = 0; i < nums.size(); i++)
            insertAt(index[i], nums[i], li);

        return vector<int>(li.begin(), li.end());
    }

    void insertAt(int idx, int val, list<int>& li){
        auto ptr = li.begin();
        while(idx--)
            ptr++;

        li.insert(ptr, val);
    }
};