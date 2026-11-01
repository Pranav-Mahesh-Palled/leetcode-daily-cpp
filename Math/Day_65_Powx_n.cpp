/**
 * ============================================================================
 * Problem Name : Pow(x, n)
 * Day Number   : Day 65
 * Topic        : Math
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(logN) — Processes 32 or 64 bit-shift operations in the worst case.
 *   - Space Complexity : O(1) auxiliary space — Strict constant memory usage without recursion stack overhead.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Signed Integer Overflow Defense:
 *   - Iterative Refactoring Opportunity:
 *   - Key Takeaway: Converting recursive binary exponentiation into an
 *     iterative bitwise loop (N & 1 for odd powers, N >>= 1 for halving)
 *     preserves O(logN) runtime while dropping auxiliary stack memory down to
 *     true O(1) space.
 * ============================================================================
 */
#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Cast to long long to prevent INT_MIN overflow when negating
        long long N = n;
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        double result = 1.0;
        double currentProduct = x;

        // Iterative Binary Exponentiation
        while (N > 0) {
            // If lowest bit is set (odd exponent component), multiply into result
            if (N & 1) {
                result *= currentProduct;
            }
            // Square the base for the next bit position
            currentProduct *= currentProduct;
            // Shift exponent right by 1 bit (divide by 2)
            N >>= 1;
        }

        return result;
    }
};
