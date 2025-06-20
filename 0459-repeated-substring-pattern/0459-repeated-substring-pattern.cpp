class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        string t_trimmed = t.substr(1, t.size() - 2);
        return t_trimmed.find(s) != string::npos;   
    }
};