class Solution {
public:
#include <string>

int firstUniqChar(std::string s) {
    int frequency[26] = {0};

    for (char c : s) {
        frequency[c - 'a']++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (frequency[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}
};
