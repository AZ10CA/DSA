using namespace std;

bool hasSingleCycle(vector<int> array) {
    // Time: O(n), Space: O(1)
    int current_idx = 0;
    for(int i = 0; i < array.size(); i++){
        if(i > 0 && current_idx == 0)
            return false;
        current_idx += array[current_idx];
        current_idx %= (int)array.size();
        current_idx = (current_idx + array.size()) % array.size();
    }

    return current_idx == 0;
}
