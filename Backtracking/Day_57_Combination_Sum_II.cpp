/**
 * ============================================================================
 * Problem Name : Combination Sum II
 * Day Number   : Day 57
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(2^N) worst-case — Each candidate can either be included or excluded, but runs significantly faster in practice due to level pruning.
 *   - Space Complexity : O(N) auxiliary space — Maximum call stack depth and path vector memory bounded by array size N.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Precision Duplicate Skipping: The check i > start && candidates[i] ==
 *     candidates[i - 1] is mathematically exact. It permits duplicate values
 *     to be selected deeper down vertical recursion branches (where i ==
 *     start), but skips duplicate values horizontally across the same
 *     decision level.
 *   - Single-Use Index Tracking: Recursing with i + 1 guarantees that each
 *     element in candidates is consumed at most once per path.
 *   - Sorted Array Early Pruning: Pre-sorting candidates ensures that
 *     candidates[i] > target safely breaks out of the loop, avoiding
 *     redundant calls on remaining larger values.
 *   - Key Takeaway: The condition i > start is the secret to handling
 *     duplicate inputs in backtracking algorithms. It accurately
 *     distinguishes between picking duplicate values vertically down a single
 *     branch vs. picking duplicate values horizontally across sibling
 *     branches.
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
private:
    void backtrack(size_t start, int target, const std::vector<int>& candidates, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        const size_t n = candidates.size();
        for (size_t i = start; i < n; ++i) {
            // Early Pruning: Stop exploring since all subsequent candidates are larger
            if (candidates[i] > target) {
                break;
            }

            // Duplicate Pruning: Skip duplicate choices across the same decision level
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            current.push_back(candidates[i]);
            // Recurse with i + 1 to enforce single-use per element index
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            current.pop_back(); // Backtrack state
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> result;
        std::vector<int> current;

        // Sort candidates to enable early break pruning and duplicate suppression
        std::sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates, current, result);
        return result;
    }
};
