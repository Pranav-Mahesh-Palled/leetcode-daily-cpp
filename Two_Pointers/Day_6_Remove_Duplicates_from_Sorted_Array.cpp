/**
 * ============================================================================
 * Problem Name : Remove Duplicates from Sorted Array
 * Day Number   : Day 6
 * Topic        : Two_Pointers
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(n) — We inspect each of the n elements exactly once.
 *   - Space Complexity : O(1) — Strictly in-place modification using constant auxiliary variables.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Spot-On Two-Pointer Strategy: You correctly realized that because the
 *     input array is sorted, identical elements will always be adjacent.
 *     Comparing nums[i] against nums[i-1] lets you identify unique boundaries
 *     without extra memory.
 *   - Defensive Programming (Handling Empty Arrays): While LeetCode
 *     constraints for this problem guarantee
 *   - C++ STL Equivalent (std::unique): Did you know the C++ Standard
 *     Template Library provides an algorithm that implements this exact
 *     algorithm? std::unique shifts duplicate consecutive elements to the end
 *     and returns an iterator to the end of the unique range.
 *   - Key Takeaway: You hit the optimal O(n) time and O(1) space on your
 *     first attempt! Adding defensive guards for empty inputs makes your code
 *     production-ready.
 * ============================================================================
 */
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // Edge case: Empty array check
        if (nums.empty()) {
            return 0;
        }

        int k = 1; // Slow pointer for writing unique elements
        int n = nums.size();

        // Fast pointer 'i' scans the rest of the array
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Place unique element at write position
                k++;               // Advance write pointer
            }
        }

        return k; // 'k' represents the count of unique elements
    }
};

// ========================================================
// Alternative One-Liner using Standard C++ Library:
// ========================================================
class SolutionSTL {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // std::unique moves duplicates to the back and returns an iterator to the new logical end
        return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
    }
};
