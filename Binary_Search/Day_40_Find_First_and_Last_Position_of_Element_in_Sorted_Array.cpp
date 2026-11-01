/**
 * ============================================================================
 * Problem Name : Find First and Last Position of Element in Sorted Array
 * Day Number   : Day 40
 * Topic        : Binary_Search
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(logN) — Strictly O(logN) with an early exit optimization if the element is absent.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra space.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Early Exit Optimization (Performance Boost):
 *   - Unified Helper Cleanliness:
 *   - Competitive Fast I/O:
 *   - Key Takeaway: When searching for the boundaries of duplicate elements
 *     in a sorted array, don't stop at nums[mid] == target. Record the index
 *     and continue shrinking the search space towards the target boundary!
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
private:
    int findBound(const std::vector<int>& nums, int target, bool isFirst) {
        int low = 0;
        int high = nums.size() - 1;
        int bound = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    high = mid - 1; // Keep searching left for first occurrence
                } else {
                    low = mid + 1;  // Keep searching right for last occurrence
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return bound;
    }

public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int first = findBound(nums, target, true);
        
        // Early Exit: If target isn't found, skip the second binary search
        if (first == -1) {
            return {-1, -1};
        }

        int last = findBound(nums, target, false);

        return {first, last};
    }
};
