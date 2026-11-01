/**
 * ============================================================================
 * Problem Name : Merge Sorted Array
 * Day Number   : Day 13
 * Topic        : Two_Pointers
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(m+n) — At most m+n comparisons and writes.
 *   - Space Complexity : O(1) auxiliary space — Merges directly in-place inside nums1.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Unnecessary Auxiliary Space:
 *   - Left-to-Right Overwrite Dilemma:
 *   - The Backwards Trick:
 *   - Key Takeaway: Whenever an array problem gives you pre-allocated
 *     trailing buffer space, think "Fill Backwards!" Merging right-to-left
 *     avoids overwriting active data and eliminates the need for extra memory
 *     allocations.
 * ============================================================================
 */
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int p1 = m - 1;      // Last valid element in nums1
        int p2 = n - 1;      // Last element in nums2
        int p = m + n - 1;   // Write pointer at end of nums1

        // Fill nums1 backwards as long as there are elements left in nums2
        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
    }
};
