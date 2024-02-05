class Solution {
public:
    #include <string>
#include <limits>

int firstUniqChar(std::string s) {
    int frequency[26] = {0};
    int indexes[26];

    for (int i = 0; i < 26; i++) {
        indexes[i] = s.size();
    }

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        frequency[c - 'a']++;
        indexes[c - 'a'] = std::min(indexes[c - 'a'], i);
    }

    int firstIndex = s.size();
    for (int i = 0; i < 26; i++) {
        if (frequency[i] == 1) {
            firstIndex = std::min(firstIndex, indexes[i]);
        }
    }

    return (firstIndex == s.size()) ? -1 : firstIndex;
}
};