class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // Initialize with base index to calculate lengths
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);  // Push the index of '('
            } else {
                st.pop();  // Pop the top of the stack
                if (st.empty()) {
                    st.push(i);  // Push the current index as a new base
                } else {
                    maxLength = max(maxLength, i - st.top());  // Calculate the length of the valid substring
                }
            }
        }
        return maxLength;
    }
};