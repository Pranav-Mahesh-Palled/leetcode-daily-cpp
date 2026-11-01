/**
 * ============================================================================
 * Problem Name : Permutations II
 * Day Number   : Day 62
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N⋅ n 1!n 2!…n k! N!) — Proportional to generating only valid, unique permutations.
 *   - Space Complexity : O(N) auxiliary space — Strict linear call stack and state array memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Duplicate Pruning via Relative Order:
 *   - Bit-Packed Boolean Vector:
 *   - Signed/Unsigned Mismatch:
 *   - Key Takeaway: Combining std::sort with !used[i - 1] enforces a
 *     canonical picking order among identical elements, reducing duplicate
 *     permutation search spaces down to exact unique output generation.
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
private:
    void backtrack(const std::vector<int>& nums, std::vector<bool>& used,
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        const size_t n = nums.size();
        for (size_t i = 0; i < n; ++i) {
            // Skip already placed elements in current branch
            if (used[i]) {
                continue;
            }

            // Duplicate Pruning: Skip duplicate elements across the same decision level
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, used, current, result);

            current.pop_back();
            used[i] = false;
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> used(nums.size(), false);

        // Sort nums so identical elements are adjacent
        std::sort(nums.begin(), nums.end());

        backtrack(nums, used, current, result);
        return result;
    }
};
