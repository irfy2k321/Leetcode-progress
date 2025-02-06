class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> prodc;
        int size = nums.size();
        int result = 0;

        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                int prod = nums[i] * nums[j];
                prodc[prod]++;
            }
        }

        for (auto& pair : prodc)
        {
            if (pair.second > 1)
            {
                result += (pair.second * (pair.second - 1))/2 * 8;
            }
        }
        return result;
    }
};