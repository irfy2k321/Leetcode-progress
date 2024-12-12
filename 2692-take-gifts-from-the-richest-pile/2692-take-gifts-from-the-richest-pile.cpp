class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while(k != 0)
        {
            auto iterator = max_element(gifts.begin(), gifts.end());
            long long max = *iterator;
            long long index = distance(gifts.begin(), iterator);
            max = static_cast<long long>(sqrt(max));
            gifts[index] = max;
            k--;
        }
        long long sum = accumulate(gifts.begin(), gifts.end(), 0LL);
        return sum;
    }
};