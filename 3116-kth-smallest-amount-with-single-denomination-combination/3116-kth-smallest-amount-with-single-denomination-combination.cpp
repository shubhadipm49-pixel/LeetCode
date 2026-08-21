class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countNumbers(long long x, vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        // Inclusion-exclusion
        for (int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, coins[i]);

                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long ways = x / L;

            if (bits % 2 == 1)
                count += ways;
            else
                count -= ways;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {
        long long left = 1;
        long long right = 1e18;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (countNumbers(mid, coins) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};