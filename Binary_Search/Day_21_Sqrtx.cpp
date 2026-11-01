/**
 * ============================================================================
 * Problem Name : Sqrt(x)
 * Day Number   : Day 21
 * Topic        : Binary_Search
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(logx) — Halves the search space of size x/2 at each step.
 *   - Space Complexity : O(1) auxiliary space — Operates using constant extra space.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Integer Overflow Prevention:
 *   - Search Range Optimization:
 *   - Tech Interview Alternative: Newton-Raphson Method In system design or
 *     numerical computing interviews, interviewers often ask for Newton's
 *     Method (Newton-Raphson), which converges even faster than binary search
 *     using iterative approximation:
 * ============================================================================
 */
#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Base cases
        if (x < 2) {
            return x;
        }

        // For x >= 2, sqrt(x) is always <= x / 2
        int low = 1;
        int high = x / 2;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Equivalent to mid * mid <= x, avoiding overflow
            if (mid <= x / mid) {
                ans = mid;
                low = mid + 1; // Try to find a larger valid integer
            } else {
                high = mid - 1; // mid is too large
            }
        }

        return ans;
    }
};
