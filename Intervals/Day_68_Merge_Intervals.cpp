/**
 * ============================================================================
 * Problem Name : Merge Intervals
 * Day Number   : Day 68
 * Topic        : Intervals
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(NlogN) — Sorting step takes O(NlogN) time; linear merge pass takes O(N) time.
 *   - Space Complexity : O(1) auxiliary space — Excludes memory required for the returned merged array.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Sorting as the Foundation: Sorting by start time guarantees that for
 *     any interval being evaluated, all preceding intervals start at or
 *     before its start time.
 *   - Leveraging C++ Lexicographical Comparison: In C++, std::vector<int>
 *     defines operator< lexicographically. Calling
 *     std::sort(intervals.begin(), intervals.end()) automatically sorts by
 *     intervals[i][0] first (and intervals[i][1] second as a tie-breaker).
 *     This eliminates the need for a custom lambda comparator entirely!
 *   - Optimal Boundary Extension: Updating merged.back()[1] = max(...)
 *     directly inside the result vector avoids temporary object allocations
 *     or intermediate re-wrapping.
 *   - Capacity Pre-allocation: Using merged.reserve(intervals.size())
 *     pre-allocates maximum required capacity, preventing vector
 *     re-allocation overhead as merged intervals are inserted.
 *   - Tech Interview Variation: In-Place Output Modification ( O(1) Memory)
 *     If an interviewer asks you to optimize space further by modifying the
 *     input intervals vector in-place without allocating a separate merged
 *     vector:
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (intervals.empty()) {
            return {};
        }

        // Lexicographical sort automatically sorts by start time (and end time on ties)
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;
        merged.reserve(intervals.size());

        for (const auto& interval : intervals) {
            // Non-overlapping interval -> push new disjoint block
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Overlapping interval -> extend right boundary in-place
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
