class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2)
        {
            return n;
        }

        int two_steps_reach = 1;
        int one_step_reach = 2;

        for (int i = 3; i <= n; i++)
        {
            int current_ways = two_steps_reach + one_step_reach;

            two_steps_reach = one_step_reach;
            one_step_reach = current_ways;
        }

        return one_step_reach;
    }
};