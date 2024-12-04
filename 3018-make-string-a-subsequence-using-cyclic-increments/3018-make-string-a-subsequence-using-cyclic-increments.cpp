class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int i = 0, j = 0;
        int len1 = s1.size(), len2 = s2.size();

        for (; i < len1 && j < len2; ++i) {
            if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j]) {
                j++;
            }
        }
        
        return j == len2;
    }
};
