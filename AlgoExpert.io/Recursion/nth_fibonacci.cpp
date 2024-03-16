#include <vector>

using namespace std;

int getNthFib(int n) {
    vector<int> lastTwo = {0, 1};

    for (int i = 3; i <= n; i++) {
        auto nextFib = lastTwo[0] + lastTwo[1];
        lastTwo[0] = lastTwo[1];
        lastTwo[1] = nextFib;
    }

    return lastTwo[n > 1];
}
