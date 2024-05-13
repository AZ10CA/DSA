class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Time: O(nlogn), Space: O(1)
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());

        auto sum = 0;
        for(int i = 0; i < seats.size(); i++)
            sum += std::abs(students[i] - seats[i]);


        return sum;
    }
};