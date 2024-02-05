class Solution {
public:
    int firstUniqChar(string s) {
         for (int i = 0; i < s.size(); i++) {
        bool found = false;
        for (int j = 0; j < s.size(); j++) {
            if (s[i] == s[j] && i != j) {
                found = true;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return -1;
    }
};