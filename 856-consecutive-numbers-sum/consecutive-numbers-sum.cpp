class Solution {
public:
    int consecutiveNumbersSum(int N) {
    int count = 0;
    for (long long l = 1; l * (l + 1) / 2 <= N; ++l) {
        double a = (1.0 * N - (l * (l - 1)) / 2) / l;
        if (a - (int)a == 0.0 && a > 0) {
            ++count;
        }
    }
    return count;
}
};