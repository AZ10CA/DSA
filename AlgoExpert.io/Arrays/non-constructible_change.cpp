#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
    // Time: O(nlogn), Space: O(1)
    std::sort(coins.begin(), coins.end());
    int last_constructed = 0;

    for(auto coin: coins){
        if(coin - last_constructed > 1)
            return last_constructed + 1;
        last_constructed += coin;
    }

    return last_constructed + 1;
}
