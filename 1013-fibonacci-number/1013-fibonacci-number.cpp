class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
        {
            return n;
        }
        if (n == 2)
        {
            return 1;
        }

        int previous = 2;
        int previous2 = 1;

        for (int i = 3; i <= n; i++)
        {
            int current = previous + previous2;

            previous2 = previous;
            previous = current;
        }
        return previous2;
    }
};