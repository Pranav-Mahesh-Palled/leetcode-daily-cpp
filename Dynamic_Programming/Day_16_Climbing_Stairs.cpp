/**
 * ============================================================================
 * Problem Name : Climbing Stairs
 * Day Number   : Day 16
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(n) — We perform n−2 additions.
 *   - Space Complexity : O(1) auxiliary space — Only constant memory needed.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Top-Tier Space Optimization:
 *   - Minor Refactoring (Eliminating current):
 *   - You can simplify the loop slightly by calculating the next value
 *     directly and eliminating the temporary current variable initialized
 *     outside the loop:
 *   - Key Takeaway: When a Dynamic Programming problem's state transition
 *     only looks back a fixed number of steps (e.g., dp[i]=dp[i−1]+dp[i−2]),
 *     you can replace the entire DP array with scalar variables to achieve
 *     O(1) space complexity!
 * ============================================================================
 */
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        // Fast I/O for optimal execution time
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Base cases
        if (n <= 2) {
            return n;
        }

        int prev2 = 1; // ways to reach step 1
        int prev1 = 2; // ways to reach step 2

        for (int i = 3; i <= n; ++i) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
