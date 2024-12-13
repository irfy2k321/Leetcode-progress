class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
        }
        long long score = 0;
        while (!pq.empty()) {
            auto [value, index] = pq.top();
            pq.pop();
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
