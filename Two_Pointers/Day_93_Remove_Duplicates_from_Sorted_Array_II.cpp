/**
 * ============================================================================
 * Problem Name : Remove Duplicates from Sorted Array II
 * Day Number   : Day 93
 * Topic        : Two_Pointers
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass over N elements.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - O(1) Auxiliary Space:
 *   - Clean Generalizability:
 *   - Tech Interview Generalization: Allow At Most K Duplicates In technical
 *     interviews, interviewers often ask: "How would you generalize this to
 *     allow at most K duplicates of each element?"
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const int n = static_cast<int>(nums.size());
        
        // Base case: arrays of size <= 2 already satisfy "at most 2 duplicates"
        if (n <= 2) {
            return n;
        }

        int k = 2; // Write pointer for valid prefix
        for (int i = 2; i < n; ++i) {
            // Include element if it differs from the element two positions back
            if (nums[i] != nums[k - 2]) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};
