/**
 * ============================================================================
 * Problem Name : Search in Rotated Sorted Array
 * Day Number   : Day 41
 * Topic        : Binary_Search
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(logN) — Halves the search range at every iteration.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Identifying the Sorted Half: In a rotated array, dividing at mid
 *     guarantees that at least one half ([left...mid] or [mid...right]) is
 *     strictly sorted. Your check nums[left] <= nums[mid] handles this
 *     property cleanly.
 *   - Inclusive Range Conditions: Testing nums[left] <= target && target <
 *     nums[mid] and nums[mid] < target && target <= nums[right] accurately
 *     determines whether target falls inside the sorted segment before
 *     eliminating a half.
 *   - Fast I/O Unlinking: Adding standard C++ competitive programming stream
 *     unlinking (ios_base::sync_with_stdio(false); cin.tie(nullptr);)
 *     guarantees a 0ms submission time on online judges.
 *   - Tech Interview Follow-Up: What if the array contains duplicates? In
 *     technical interviews, a common follow-up is Search in Rotated Sorted
 *     Array II (where elements are not distinct):
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Case 1: Left half [left...mid] is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Target is inside sorted left half
                } else {
                    left = mid + 1;  // Target is inside right half
                }
            } 
            // Case 2: Right half [mid...right] is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Target is inside sorted right half
                } else {
                    right = mid - 1; // Target is inside left half
                }
            }
        }

        return -1;
    }
};
