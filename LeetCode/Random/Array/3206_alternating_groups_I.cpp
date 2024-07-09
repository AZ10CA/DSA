class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        // Time: O(n), Space: O(1)
        int count = 0;
        auto sz = colors.size();
        for(int i = 0; i < sz; i++){
            auto primary_color = colors[i];
            auto secondary_color = colors[(i + 1) % sz];
            if(primary_color != secondary_color && colors[(i + 2) % sz] == primary_color)
                count++;
        }

        return count;
    }
};