class Solution {
public:
#include <string>

int firstUniqChar(std::string s) {
    int frequency[26] = {0};
    int indexes[26];

    for (int i = 0; i < 26; i++) {
        indexes[i] = -1;
    }

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        frequency[c - 'a']++;
        if (indexes[c - 'a'] == -1) {
            indexes[c - 'a'] = i;
        }
    }

    int firstIndex = -1;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] == 1) {
            if (firstIndex == -1 || indexes[i] < firstIndex) {
                firstIndex = indexes[i];
            }
        }
    }

    return firstIndex;
}
};