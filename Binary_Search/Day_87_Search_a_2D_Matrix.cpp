/**
 * ============================================================================
 * Problem Name : Search a 2D Matrix
 * Day Number   : Day 87
 * Topic        : Binary_Search
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(log(M×N)) — Reduces search space by half in every iteration.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Virtual 1D Index Mapping:
 *   - Overflow-Safe Midpoint:
 *   - Const Correctness:
 *   - Declaring const std::vector<std::vector<int>>& matrix signals that the
 *     matrix is read-only and prevents accidental modifications.
 *   - Tech Interview Contrast: Search Matrix I vs. Search Matrix II In
 *     technical interviews, this problem is frequently contrasted with Search
 *     a 2D Matrix II (LeetCode 240):
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());

        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            const int mid = low + (high - low) / 2;
            const int val = matrix[mid / n][mid % n];

            if (val == target) {
                return true;
            } else if (val < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
