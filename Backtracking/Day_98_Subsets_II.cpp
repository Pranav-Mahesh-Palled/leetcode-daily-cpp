/**
 * ============================================================================
 * Problem Name : Subsets II
 * Day Number   : Day 98
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N⋅2 N ) — Generates all unique subsets strictly without visiting duplicate states.
 *   - Space Complexity : O(N) auxiliary space — Strict depth- N stack frame and path vector memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Sorting Requirement (std::sort):
 *   - Tech Interview Alternative: Iterative Cascading ( 0 ms Non-Recursive
 *     Approach) In technical interviews, interviewers often ask: "Can you
 *     avoid recursion stack overhead entirely and solve this iteratively?"
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
private:
    void backtrack(int start, const std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        result.push_back(current);

        const int n = static_cast<int>(nums.size());
        for (int i = start; i < n; ++i) {
            // Skip duplicate elements at the same recursion depth
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back(); // Backtrack state
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::sort(nums.begin(), nums.end());

        const int n = static_cast<int>(nums.size());
        std::vector<std::vector<int>> result;
        result.reserve(1 << n); // Reserve max theoretical power set capacity

        std::vector<int> current;
        current.reserve(n);

        backtrack(0, nums, current, result);
        return result;
    }
};
