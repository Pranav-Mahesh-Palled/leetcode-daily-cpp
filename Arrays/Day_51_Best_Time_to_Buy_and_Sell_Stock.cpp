/**
 * ============================================================================
 * Problem Name : Best Time to Buy and Sell Stock
 * Day Number   : Day 51
 * Topic        : Arrays
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass; each element is evaluated in O(1) time.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Out-of-Bounds Protection: Accessing prices[0] directly assumes the
 *     array is non-empty. Initializing minPrice = INT_MAX eliminates
 *     out-of-bounds risks if an empty array is passed.
 *   - Branching Optimization: In your loop, minPrice updates before
 *     maxProfit. When prices[i] sets a new minimum, prices[i] - minPrice
 *     equals 0, which can never beat maxProfit. Using an if-else block avoids
 *     evaluating std::max whenever a new lowest buy price is found.
 *   - Signed/Unsigned Mismatch: Comparing signed int i with unsigned
 *     prices.size() generates compiler warnings. Using a range-based for (int
 *     price : prices) loop makes the code cleaner and type-safe.
 *   - Key Takeaway: Switching from unconditional std::min and std::max calls
 *     to an if-else branch skips redundant subtraction operations on days
 *     when a new lowest purchase price is discovered.
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; // Update lowest buy price seen so far
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice; // Update peak profit
            }
        }

        return maxProfit;
    }
};
