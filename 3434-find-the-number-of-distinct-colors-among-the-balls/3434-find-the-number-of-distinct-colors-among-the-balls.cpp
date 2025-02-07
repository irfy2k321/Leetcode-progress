class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int,int> mp;
        unordered_set<int> st;
        
        for (const auto& q : queries) {
            if (mp.count(q[0])) {
                int old = mp[q[0]];
                bool found = false;
                for (auto& p : mp) {
                    if (p.first != q[0] && p.second == old) {
                        found = true;
                        break;
                    }
                }
                if (!found) st.erase(old);
            }
            mp[q[0]] = q[1];
            st.insert(q[1]);
            ans.push_back(st.size());
        }
        
        return ans;
    }
};