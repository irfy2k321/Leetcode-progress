class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> key_indexes;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == key)
            {
                key_indexes.push_back(i);
            }
        }

        if (key_indexes.empty())
        {
            return {};
        }

        vector<int> result;
        int start = 0;

        for (int index : key_indexes)
        {
            int range_s = max(0, index - k);
            int range_e = min(n - 1, index + k);

            int start_point = max(start, range_s);

            for (int i = start_point; i <= range_e; i++)
            {
                result.push_back(i);
            }

            start = range_e + 1;

            if (start >= n)
            {
                break;
            }
        }
        return result;
   }
};