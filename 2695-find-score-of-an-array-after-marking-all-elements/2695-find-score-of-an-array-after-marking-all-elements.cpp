class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);
        vector<pair<int, int>> sorted;
        for (int i = 0; i < n; ++i) {
            sorted.push_back({nums[i], i});
        }
        sort(sorted.begin(), sorted.end());
        long long score = 0;
        for (auto& [value, index] : sorted) {
            if (!marked[index]) {
                score += value;
                marked[index] = true;
                if (index > 0) marked[index - 1] = true;
                if (index < n - 1) marked[index + 1] = true;
            }
        }
        return score;
    }
};
