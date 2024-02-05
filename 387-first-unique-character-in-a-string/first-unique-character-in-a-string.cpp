class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> fo(26);
        for(auto i:s){
            fo[i-'a']++;
        }
        int i=0;
        int n=s.size();
        while(i<n){
            if(fo[s[i]-'a']==1) return i;

            i++;
        }
        return -1;
    }
};
