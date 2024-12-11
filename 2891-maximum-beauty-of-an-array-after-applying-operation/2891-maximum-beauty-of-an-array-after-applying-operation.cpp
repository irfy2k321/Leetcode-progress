class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int maxBeauty = 0;
        int left = 0; // Left pointer of the sliding window
        
        for (int right = 0; right < nums.size(); ++right) {
            // Ensure the range [nums[left], nums[right]] is valid
            while (nums[right] - nums[left] > 2 * k) {
                ++left;
            }
            // Calculate the size of the window
            maxBeauty = max(maxBeauty, right - left + 1);
        }
        
        return maxBeauty;
    }
};