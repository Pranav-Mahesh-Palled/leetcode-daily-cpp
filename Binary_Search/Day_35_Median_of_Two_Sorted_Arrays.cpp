/**
 * ============================================================================
 * Problem Name : Median of Two Sorted Arrays
 * Day Number   : Day 35
 * Topic        : Binary_Search
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(log(min(m,n))) — Halves the search space of the smaller array at each step.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Integer Overflow Safety (low + (high - low) / 2):
 *   - Binary Search on Smaller Array:
 *   - Competitive Stream Unlinking:
 *   - Key Takeaway: When searching across multiple sorted arrays, think about
 *     partitioning indices rather than merging elements. Splitting the
 *     smaller array via Binary Search guarantees logarithmic time without
 *     consuming extra memory!
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Perform binary search on the smaller array to guarantee O(log(min(m, n)))
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Valid partition condition
            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 1) {
                    return std::max(left1, left2);
                }
                return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
            }

            // Move left if cut1 is too far right
            if (left1 > right2) {
                high = cut1 - 1;
            } 
            // Move right if cut1 is too far left
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};
