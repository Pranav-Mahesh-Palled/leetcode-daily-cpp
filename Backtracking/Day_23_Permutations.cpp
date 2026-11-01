/**
 * ============================================================================
 * Problem Name : Permutations
 * Day Number   : Day 23
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N⋅N!) — We generate all N! permutations, and pushing each copy of size N into result takes O(N) time.
 *   - Space Complexity : O(N) auxiliary space — Limited strictly to the O(N) recursion call stack depth. Zero extra arrays (used / current) allocated on the heap!
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Clean State Management:
 *   - Access Specifiers (private vs public):
 *   - Helper methods like backtrack() should ideally be placed under a
 *     private: section in C++ classes to avoid exposing internal
 *     implementation details to callers.
 *   - In-Place Swapping Optimization (Space Savings):
 *   - Key Takeaway: When generating permutations or combinations of unique
 *     elements, ask yourself if state can be tracked via in-place swapping
 *     instead of extra tracking containers. It drastically cleans up memory
 *     footprint and speeds up execution.
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
private:
    void backtrack(int start, std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Base case: all positions fixed
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // Choose: swap current element into the target index 'start'
            std::swap(nums[start], nums[i]);

            // Explore: recurse for the next index
            backtrack(start + 1, nums, result);

            // Unchoose / Backtrack: restore original state
            std::swap(nums[start], nums[i]);
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};
