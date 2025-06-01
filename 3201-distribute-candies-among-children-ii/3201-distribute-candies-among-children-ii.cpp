class Solution {
public:
    long long combinations(int k_val) {
        if (k_val < 2) {
            return 0;
        }
        return static_cast<long long>(k_val) * (k_val - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        long long ways0 = combinations(n + 2);

        long long ways1 = 3LL * combinations(n - (limit + 1) + 2);

        long long ways2 = 3LL * combinations(n - 2 * (limit + 1) + 2);

        long long ways3 = 1LL * combinations(n - 3 * (limit + 1) + 2);
        
        long long final_ans_long = ways0 - ways1 + ways2 - ways3;
        
        return final_ans_long;
    }
};