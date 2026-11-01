/**
 * ============================================================================
 * Problem Name : Next Permutation
 * Day Number   : Day 39
 * Topic        : Two_Pointers
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — At most 3N operations (one pass for pivot, one pass for successor, and one pass to reverse suffix).
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Leveraging std::reverse for Cleanliness:
 *   - Optimal Scan Strategy:
 *   - Competitive Fast I/O:
 *   - Key Takeaway: Reversing a descending suffix flips it into the smallest
 *     possible ascending prefix sequence. Replacing manual pointer-swapping
 *     loops with C++ STL utilities like std::reverse yields cleaner,
 *     production-ready code.
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right (pivot)
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If pivot exists, find the smallest element > nums[i] from the right
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }

        // Step 3: Reverse suffix after pivot to achieve smallest lexicographical order
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};
