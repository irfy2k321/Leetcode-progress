class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && prices[st.top()] > prices[i]) {
                st.pop();
            }
            if (!st.empty()) {
                answer[i] = prices[i] - prices[st.top()];
            } else {
                answer[i] = prices[i];
            }
            st.push(i);
        }

        return answer;
    }
};