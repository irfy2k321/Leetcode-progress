class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> totalSet(nums.begin(), nums.end());
        int totalDistinct = totalSet.size();
        int count = 0;

        for (int start = 0; start < n; ++start) {
            unordered_set<int> current;
            for (int end = start; end < n; ++end) {
                current.insert(nums[end]);
                if (current.size() == totalDistinct)
                    ++count;
            }
        }

        return count;
    }
};
