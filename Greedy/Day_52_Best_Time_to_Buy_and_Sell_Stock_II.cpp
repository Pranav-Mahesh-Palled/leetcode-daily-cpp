/**
 * ============================================================================
 * Problem Name : Best Time to Buy and Sell Stock II
 * Day Number   : Day 52
 * Topic        : Greedy
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass; performs N−1 constant-time comparisons.
 *   - Space Complexity : O(1) auxiliary space — Operates using zero extra dynamic memory.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Optimal Greedy Property: Because unlimited non-overlapping transactions
 *     are allowed without fees, taking advantage of every positive price diff
 *     is mathematically equivalent to buying at every local valley and
 *     selling at every local peak.
 *   - Implicit Boundary Safety: Loop condition size_t i = 1; i <
 *     prices.size() safely handles empty or single-element prices arrays
 *     without throwing out-of-bounds exceptions.
 *   - Unsigned Index Type: Using size_t matches prices.size() return type and
 *     avoids signed/unsigned integer comparison compiler warnings.
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int totalProfit = 0;
        const size_t n = prices.size();

        for (size_t i = 1; i < n; ++i) {
            // Accumulate profit on every positive price slope
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }

        return totalProfit;
    }
};
