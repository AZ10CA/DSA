#include <vector>
#include <unordered_set>
using namespace std;

void generate_permutations(const vector<int>& numbers, int idx, vector<int>& curr_perm, unordered_set<int>& used, vector<vector<int>>& result){
    if(curr_perm.size() == numbers.size()){
        result.push_back(curr_perm);
        return;
    }

    for(int i = 0; i < numbers.size(); i++){
        if(used.find(i) != used.end())
            continue;
        used.insert(i);
        curr_perm.push_back(numbers[i]);
        generate_permutations(numbers, 0, curr_perm, used, result);
        used.erase(i);
        curr_perm.pop_back();
    }
}

vector<vector<int>> getPermutations(vector<int> array) {
    if(array.size() == 0)
        return {};
    vector<vector<int>> result;
    vector<int> curr_perm;
    unordered_set<int> used;

    generate_permutations(array, 0, curr_perm, used, result);

    return result;
}
