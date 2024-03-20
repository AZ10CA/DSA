using namespace std;

int majorityElement(vector<int> array) {
    // Time: O(n), Space: O(1)
    int majority_element = array[0];
    int cnt = 0;

    for (auto num: array)
        if (num == majority_element)
            cnt++;
        else {
            cnt--;
            if (cnt == -1) {
                cnt = 1;
                majority_element = num;
            }
        }

    return majority_element;
}
