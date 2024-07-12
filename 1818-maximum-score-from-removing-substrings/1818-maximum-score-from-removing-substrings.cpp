class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x >= y) {
            return removeSubstrings(s, 'a', 'b', x) + removeSubstrings(s, 'b', 'a', y);
        } else {
            return removeSubstrings(s, 'b', 'a', y) + removeSubstrings(s, 'a', 'b', x);
        }
    }

private:
    int removeSubstrings(string& s, char first, char second, int points) {
        string result;
        int score = 0;

        for (char c : s) {
            if (!result.empty() && result.back() == first && c == second) {
                result.pop_back(); // Remove the matching pair
                score += points;   // Gain points
            } else {
                result.push_back(c); // Push current character onto result
            }
        }

        s = result; // Update s to the remaining characters after removals
        return score;
    }
};