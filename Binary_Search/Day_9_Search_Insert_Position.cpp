/**
 * ============================================================================
 * Problem Name : Search Insert Position
 * Day Number   : Day 9
 * Topic        : Binary_Search
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(logn) — Performs logarithmic division of the search space.
 *   - Space Complexity : O(1) — Zero extra allocations.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Redundant index Variable: Inside your loop, you execute index = left;
 *     on every single iteration. When binary search terminates (left >
 *     right), left is guaranteed to be the correct insertion index. You can
 *     remove index entirely and simply return left; outside the while loop.
 *   - Avoiding Integer Overflow:
 *   - Variable Scoping:
 *   - Key Takeaway: In Binary Search, when left > right, left naturally
 *     settles at the exact insertion position for missing elements. You don't
 *     need extra state tracking variables inside the loop!
 * ============================================================================
 */
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // Prevents potential integer overflow
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            } 
            else if (nums[mid] < target) {
                left = mid + 1; // Search right half
            } 
            else {
                right = mid - 1; // Search left half
            }
        }

        // When not found, 'left' points to the insertion index
        return left;
    }
};

// ========================================================
// Modern C++ Alternative (std::lower_bound)
// ========================================================
In C++, std::lower_bound returns an iterator pointing to the first element that is not less than target. Subtracting nums.begin() gives the exact index in 
O(logn) time:

#include <vector>
#include <algorithm>

class SolutionSTL {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        return std::distance(nums.begin(), it);
    }
};
