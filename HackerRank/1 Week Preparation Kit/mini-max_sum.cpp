#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<unsigned long long> nums(5);
    unsigned long long sum = 0;

    for(auto& num: nums){
        cin >> num;
        sum += num;
    }

    std::sort(nums.begin(), nums.end());

    cout << sum - nums[nums.size() - 1] << " " << sum - nums[0] << endl;

    return 0;
}