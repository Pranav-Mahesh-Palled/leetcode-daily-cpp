/**
 * ============================================================================
 * Problem Name : Maximum Subarray
 * Day Number   : Day 66
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass traversal across N elements.
 *   - Space Complexity : O(1) auxiliary space — Strict constant memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Type-Safe Indexing: Using size_t i = 1 matches the return type of
 *     nums.size(), avoiding signed/unsigned integer conversion warnings
 *     across strict compilers.
 *   - Standard Library Qualification: Explicitly qualifying std::max ensures
 *     compatibility across strict C++ standard headers.
 *   - Tech Interview Follow-Up: Divide & Conquer ( O(NlogN) Time, O(logN)
 *     Space) In technical interviews, interviewers frequently follow up
 *     Kadane's O(N) linear scan by asking for a Divide and Conquer
 *     implementation:
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int maxSoFar = nums[0];
        int currentSum = nums[0];

        const size_t n = nums.size();
        for (size_t i = 1; i < n; ++i) {
            // Either extend current running sum or start fresh at nums[i]
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSoFar = std::max(maxSoFar, currentSum);
        }

        return maxSoFar;
    }
};
