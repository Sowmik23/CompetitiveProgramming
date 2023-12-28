class Solution {
public:
    bool isUgly(int n) {
        // A non-positive integer cannot be ugly
        if (n <= 0) {
            return false;
        }

        // Factorize by dividing with permitted factors.
        for (auto factor : {2, 3, 5}) {
            n = keepDividingWhenDivisible(n, factor);
        }

        return n == 1;
    }

    // Keep dividing dividend by divisor when division is possible.
    int keepDividingWhenDivisible(int dividend, int divisor) {
        while (dividend % divisor == 0) {
            dividend /= divisor;;
        }
        return dividend;
    }
};
