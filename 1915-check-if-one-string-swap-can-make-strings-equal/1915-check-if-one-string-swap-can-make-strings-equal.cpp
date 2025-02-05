class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // Check if strings have the same length
        if (s1.size() != s2.size())
        {
            return false;
        }
        
        // If strings are identical, return true
        if (s1 == s2)
        {
            return true;
        }
        
        // Count and store mismatched characters
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                diff.push_back(i);
                
                // If more than 2 characters differ, return false
                if (diff.size() > 2)
                {
                    return false;
                }
            }
        }
        
        // Check if swapping the different characters makes strings equal
        return (diff.size() == 2 && 
                s1[diff[0]] == s2[diff[1]] && 
                s1[diff[1]] == s2[diff[0]]);
    }
};