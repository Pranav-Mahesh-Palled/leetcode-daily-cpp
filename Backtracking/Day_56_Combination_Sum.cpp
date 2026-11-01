/**
 * ============================================================================
 * Problem Name : Combination Sum
 * Day Number   : Day 56
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N M T) worst-case, but runs significantly faster in practice due to sorted array branch pruning.
 *   - Space Complexity : O( M T) auxiliary space — Strict bound on call stack depth and path state tracking.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Sorting + Early Pruning: Sorting candidates upfront allows you to break
 *     out of the loop immediately when candidates[i] > target. Because the
 *     array is sorted, subsequent elements are guaranteed to exceed target,
 *     saving thousands of redundant recursive branches.
 *   - Unlimited Element Reuse: Passing i (instead of i + 1) into backtrack(i,
 *     target - candidates[i], ...) cleanly implements the requirement that
 *     the same candidate can be chosen an unlimited number of times.
 *   - Signed/Unsigned Comparison Warning: Comparing int i with
 *     candidates.size() (which returns size_t) raises compiler warnings.
 *     Storing const int n = candidates.size() or using size_t keeps your
 *     build warning-free.
 *   - Tech Interview Follow-Up: Combination Sum II
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

            current.push_back(candidates[i]);
            // Recurse with index 'i' to allow unlimited reuse of the current element
            backtrack(i, target - candidates[i], candidates, current, result);
            current.pop_back(); // Backtrack state
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> result;
        std::vector<int> current;

        // Sort candidates to enable early break pruning
        std::sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates, current, result);
        return result;
    }
};
