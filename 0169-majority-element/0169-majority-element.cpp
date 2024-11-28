class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0, maxVal = 0;
        for (int num : nums)
        {
            if (count == 0)
            {
                count = 1;
                maxVal = num;
            }
            else if (num == maxVal)
            {
                count++;
            }
            else
                count--;
        }
        count = 0;
        for (int num : nums)
        {
            if (num == maxVal)
                count++;
        }

        if (count > nums.size()/2)
        {
            return maxVal;
        }
        return -1;
    }
};