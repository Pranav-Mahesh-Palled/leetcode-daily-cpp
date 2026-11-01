/**
 * ============================================================================
 * Problem Name : Remove Element
 * Day Number   : Day 7
 * Topic        : Two_Pointers
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(n) — Both approaches traverse the array at most n times.
 *   - Space Complexity : O(1) — Modifies nums directly in memory without allocating additional data structures.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Key Takeaway: When element order doesn't matter, swapping target
 *     elements with the array's tail reduces redundant writes from O(n) down
 *     to at most the number of elements to remove.
 * ============================================================================
 */
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; // Write pointer for non-val elements
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Copy valid element
                k++;               // Move write pointer
            }
        }

        return k; // Number of valid elements
    }
};

// ========================================================
// Approach 2: Opposite Ends Pointer (Minimizes Array Writes)
// ========================================================
// If elements to remove are rare, swapping with the tail element minimizes unnecessary copy operations. (Note: This approach does not preserve element order, which the problem statement explicitly allows).

#include <vector>

class SolutionOppositeEnds {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1]; // Overwrite current with last element
                n--;                   // Reduce logical array size
            } else {
                i++;                   // Move forward only if current is safe
            }
        }

        return n; // Remaining size
    }
};

// ========================================================
// Modern C++ Alternative (std::remove)
// ========================================================

// ========================================================
// In production C++, this problem is typically solved using standard algorithms:
// ========================================================

#include <vector>
#include <algorithm>

class SolutionSTL {
public:
    int removeElement(std::vector<int>& nums, int val) {
        // std::remove moves matching elements to the end and returns an iterator to the new boundary
        auto it = std::remove(nums.begin(), nums.end(), val);
        return std::distance(nums.begin(), it);
    }
};
