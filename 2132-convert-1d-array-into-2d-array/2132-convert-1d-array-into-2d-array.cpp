class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;

        if(n * m != original.size()) return ans;

        int cnt = 0;
        vector<int> temp;

        for(int val : original)
        {
            temp.push_back(val);
            cnt++;

            if(cnt == n)
            {
                cnt = 0;
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};