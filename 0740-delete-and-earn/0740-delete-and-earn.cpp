class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }

        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> points(max_num + 1, 0);

        for(int num: nums)
        {
            points[num] += num;
        }

        int one_back = 0;
        int two_back = 0;

        for (int p : points)
        {
            int curr_max = max(one_back, p + two_back);

            two_back = one_back;
            one_back = curr_max;
        }
        return one_back;
    }
};