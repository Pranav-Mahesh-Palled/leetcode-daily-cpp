/**
 * ============================================================================
 * Problem Name : Reverse Integer
 * Day Number   : Day 14
 * Topic        : Math
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(log 10∣x∣) — Always ≤10 loop iterations.
 *   - Space Complexity : O(1) — Zero extra allocations.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Strict 32-Bit Limit Handling:
 *   - Simplified Boundary Logic Insight:
 *   - Key Takeaway: You solved this using the gold-standard 32-bit boundary
 *     technique! Avoiding 64-bit casts (long long) proves to interviewers
 *     that you can manage strict hardware and memory constraints cleanly.
 * ============================================================================
 */
#include <climits>
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        // Fast I/O optimization for LeetCode performance
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int rev = 0;

        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Check positive overflow boundary
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            // Check negative overflow boundary
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) {
                return 0;
            }

            rev = rev * 10 + pop;
        }

        return rev;
    }
};
