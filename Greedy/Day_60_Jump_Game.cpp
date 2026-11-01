/**
 * ============================================================================
 * Problem Name : Jump Game
 * Day Number   : Day 60
 * Topic        : Greedy
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass through the array.
 *   - Space Complexity : O(1) auxiliary space — Strict constant memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Optimal Greedy Tracking:
 *   - Early Exit Short-Circuit:
 *   - Impassable Barrier Detection:
 *   - Tech Interview Follow-Up: Jump Game II (Minimum Jumps) In technical
 *     interviews, the standard follow-up is Jump Game II (return the minimum
 *     number of jumps required to reach n - 1 assuming destination is always
 *     reachable):
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int maxReach = 0;
        const int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            // Unreachable index barrier reached
            if (i > maxReach) {
                return false;
            }

            maxReach = std::max(maxReach, i + nums[i]);

            // Early exit as soon as destination is reachable
            if (maxReach >= n - 1) {
                return true;
            }
        }

        return true;
    }
};
