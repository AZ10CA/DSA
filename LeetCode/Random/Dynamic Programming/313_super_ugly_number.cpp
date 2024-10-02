typedef unsigned long long ull;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Time: O(n), Space: O(n)
        vector<ull> ugly_numbers = {1};

        vector<ull> prime_indices(primes.size(), 0);
        vector<ull> next_multiples(primes.size(), 0);

        // initialize next multiples for each prime
        for(int i = 0; i < next_multiples.size(); i++)
            next_multiples[i] = primes[i];

        while(ugly_numbers.size() < n){
            int idx = find_min(next_multiples);
            ugly_numbers.push_back(next_multiples[idx]);

            for(int i = 0; i < next_multiples.size(); i++){
                if(next_multiples[i] == ugly_numbers.back()){
                    prime_indices[i]++;
                    next_multiples[i] = ugly_numbers[prime_indices[i]] * primes[i];
                }
            }
        }

        return ugly_numbers.back();
    }

    int find_min(const vector<ull>& vec){
        auto ptr = std::min_element(vec.begin(), vec.end());
        auto idx = std::distance(vec.begin(), ptr);
        return idx;
    }
};