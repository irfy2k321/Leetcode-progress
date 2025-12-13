class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) 
    {
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<pair<int, string>, string>> valid;

        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i]) continue;

            if (priority.find(businessLine[i]) == priority.end())
                continue;

            if (code[i].empty()) continue;

            bool ok = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            valid.push_back({{priority[businessLine[i]], code[i]}, code[i]});
        }

        sort(valid.begin(), valid.end(),
             [](auto& a, auto& b) {
                 if (a.first.first != b.first.first)
                     return a.first.first < b.first.first;
                 return a.first.second < b.first.second;
             });

        vector<string> result;
        for (auto& v : valid)
            result.push_back(v.second);

        return result;
    }
};
