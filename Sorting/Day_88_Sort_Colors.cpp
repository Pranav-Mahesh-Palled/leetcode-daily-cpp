/**
 * ============================================================================
 * Problem Name : Sort Colors
 * Day Number   : Day 88
 * Topic        : Sorting
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single-pass linear scan with N pointer updates.
 *   - Space Complexity : O(1) auxiliary space — Strict constant memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Dutch National Flag Partitioning:
 *   - Maintaining four distinct regions ensures every element is placed in
 *     its proper location:
 *   - Crucial mid Pointer Handling on 2s:
 *   - Underflow Guard:
 *   - Tech Interview Extension: K-Color Partitioning In technical interviews,
 *     interviewers may ask: "How would you generalize this from 3 colors (
 *     0,1,2) to K distinct colors?"
 * ============================================================================
 */
#include <vector>
#include <utility>
#include <iostream>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int low = 0;
        int mid = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                std::swap(nums[mid], nums[high]);
                high--; // Do not increment mid; inspect swapped element next
            }
        }
    }
};
