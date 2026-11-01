/**
 * ============================================================================
 * Problem Name : Insert Interval
 * Day Number   : Day 69
 * Topic        : Intervals
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Evaluates each interval in O(1) time in a single linear pass.
 *   - Space Complexity : O(1) auxiliary space — Strict constant memory usage (excluding the required output buffer).
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Three-Phase Linear Sweep: Partitioning the problem into three distinct
 *     non-overlapping stages (left disjoint intervals, overlapping merged
 *     intervals, and right disjoint intervals) makes the logic completely
 *     deterministic and free of edge-case bugs.
 *   - In-Place Merging: Updating newInterval[0] and newInterval[1]
 *     dynamically across overlapping intervals absorbs all overlapping bounds
 *     without needing extra dynamic data structures.
 *   - Memory Pre-allocation: Calling result.reserve(intervals.size() + 1)
 *     guarantees that at most one dynamic reallocation occurs, keeping heap
 *     management overhead minimal.
 *   - Type Consistency: Using size_t for the index pointer i avoids
 *     signed/unsigned integer comparison compiler warnings when interacting
 *     with intervals.size().
 *   - Tech Interview Alternative: Binary Search Optimization ( O(logN)
 *     Search) In technical interviews, follow-up questions often ask: "Can we
 *     use Binary Search since intervals is already sorted?"
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const size_t n = intervals.size();
        std::vector<std::vector<int>> result;
        result.reserve(n + 1);

        size_t i = 0;

        // Phase 1: Push all intervals coming strictly before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            ++i;
        }

        // Phase 2: Merge all overlapping intervals into newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            ++i;
        }
        result.push_back(newInterval);

        // Phase 3: Push all remaining intervals coming strictly after newInterval
        while (i < n) {
            result.push_back(intervals[i]);
            ++i;
        }

        return result;
    }
};
