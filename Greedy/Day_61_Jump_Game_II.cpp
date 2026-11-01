/**
 * ============================================================================
 * Problem Name : Jump Game II
 * Day Number   : Day 61
 * Topic        : Greedy
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass scan across the array with early break short-circuiting.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Implicit BFS Layer Transitions:
 *   - Loop Boundary Precision (n - 1):
 *   - Early Exit Optimization:
 *   - Key Takeaway: Unrolling a Breadth-First Search into a two-pointer
 *     window (currentEnd and maxReach) finds shortest path distances on 1D
 *     arrays in O(N) time while completely avoiding O(N) queue memory
 *     allocations.
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const int n = static_cast<int>(nums.size());

        // Base case: Already at the destination index
        if (n <= 1) {
            return 0;
        }

        int jumps = 0;
        int currentEnd = 0;
        int maxReach = 0;

        // Iterate up to n - 2 because reaching n - 1 means we're at the destination
        for (int i = 0; i < n - 1; ++i) {
            maxReach = std::max(maxReach, i + nums[i]);

            // Reached boundary of current jump level
            if (i == currentEnd) {
                jumps++;
                currentEnd = maxReach;

                // Early exit if the next layer covers the last index
                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};
