class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;                 
    if (n == 1) return nums[0];

    int twoBack = nums[0];
    int oneBack = max(nums[0], nums[1]);  

    for (int i = 2; i < n; ++i) {
        int cur = max(oneBack, nums[i] + twoBack);
        twoBack = oneBack;  
        oneBack = cur;
    }

    return oneBack;
    }
};