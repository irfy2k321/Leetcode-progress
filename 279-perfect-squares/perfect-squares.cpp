class Solution {
public:
    int numSquares(int n) {
    int dp[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = i;  // maximum is i because 1 is a perfect square
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j*j <= i; ++j) {
            if (dp[i - j*j] + 1 < dp[i]) {
                dp[i] = dp[i - j*j] + 1;
            }
        }
    }
    return dp[n];
}
};