/**
 * ============================================================================
 * Problem Name : Search in Rotated Sorted Array II
 * Day Number   : Day 94
 * Topic        : Binary_Search
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(logN) average, O(N) worst-case. 1792732459393.jpeg
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint. 1792732459393.jpeg
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Contiguous Half Identification:
 *   - Target Containment Bounding:
 *   - Const Correctness:
 *   - Passing const std::vector<int>& nums in production interfaces
 *     guarantees that input data remains unmodified.
 *   - Tech Interview Comparison: Rotated Search I vs. II Problem Element
 *     Constraints Worst-Case Time Key Strategy Search in Rotated Sorted Array
 *     I (LC 33) Distinct elements O(logN) Standard 2-way binary search on
 *     sorted half Search in Rotated Sorted Array II (LC 81) Duplicates
 *     allowed 1792732459393.jpeg
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    bool search(const std::vector<int>& nums, int target) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (low <= high) {
            const int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Ambiguity case: Cannot determine which half is sorted
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            // Left half is sorted
            else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};
