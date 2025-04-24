class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                int count = i;
                j = 0;

                while (i < haystack.size() && j < needle.size() && haystack[i] == needle[j]) {
                    j++;
                    i++;
                }

                if (j == needle.size())
                    return count;

                i = count;
            }
        }
        return -1;
    }
};
