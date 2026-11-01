/**
 * ============================================================================
 * Problem Name : Subsets
 * Day Number   : Day 91
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N⋅2 N ) — Generates and records 2 N subsets.
 *   - Space Complexity : O(N) auxiliary space — Maximum recursion depth N and working path vector footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Exact Power Set Allocation:
 *   - Working Vector Buffer Optimization:
 *   - In-Place Reusable State Path:
 *   - Tech Interview Alternative: Bitmask Iteration ( O(1) Auxiliary Memory)
 *     In technical interviews, interviewers frequently ask: "Can you generate
 *     all subsets iteratively without using recursion or stack frames?"
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
private:
    void backtrack(int start, const std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Record current valid subset
        result.push_back(current);

        for (int i = start; i < static_cast<int>(nums.size()); ++i) {
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back(); // Undo state choice
        }
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const int n = static_cast<int>(nums.size());
        std::vector<std::vector<int>> result;
        result.reserve(1 << n); // Pre-allocate exact 2^N capacity

        std::vector<int> current;
        current.reserve(n);

        backtrack(0, nums, current, result);
        return result;
    }
};
