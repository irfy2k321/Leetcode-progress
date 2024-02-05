class Solution {
public:
#include <string>

int firstUniqChar(string& s) {
        int freq[26];
        int n=s.size();
        for(int i=0; i<n; i++){
            int idx=s[i]-'a';
            freq[idx]++;
        }
        for (int i=0; i<n; i++)
            if (freq[s[i]-'a']==1) 
                return i;
        return -1;
    }
};