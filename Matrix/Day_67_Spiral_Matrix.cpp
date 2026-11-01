/**
 * ============================================================================
 * Problem Name : Spiral Matrix
 * Day Number   : Day 67
 * Topic        : Matrix
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(M×N) — Single pass processing M×N matrix elements. 1790409382729.jpeg
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint. 1790409382729.jpeg
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Asymmetric Boundary Safety:
 *   - Capacity Pre-allocation:
 *   - Fast I/O Optimization:
 *   - Adding std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); at
 *     the start eliminates C++ standard I/O stream synchronization overhead,
 *     bringing runtime down to 0ms.
 *   - Key Takeaway: For matrix ring traversal problems, using a 4-pointer
 *     boundary box (top, bottom, left, right) eliminates the need for dynamic
 *     visited matrices while guarding against central row/column overlaps via
 *     inner condition checks (top <= bottom and left <= right).
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());

        std::vector<int> result;
        result.reserve(m * n);

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // 1. Traverse Right
            for (int col = left; col <= right; ++col) {
                result.push_back(matrix[top][col]);
            }
            top++;

            // 2. Traverse Down
            for (int row = top; row <= bottom; ++row) {
                result.push_back(matrix[row][right]);
            }
            right--;

            // 3. Traverse Left (Check if bottom row is valid)
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            // 4. Traverse Up (Check if left column is valid)
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return result;
    }
};
