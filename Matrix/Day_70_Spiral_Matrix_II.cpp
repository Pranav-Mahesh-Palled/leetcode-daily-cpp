/**
 * ============================================================================
 * Problem Name : Spiral Matrix II
 * Day Number   : Day 70
 * Topic        : Matrix
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N^2) — Visits each cell in the N×N matrix exactly once in linear order.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint (excluding required return storage).
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Consistency Across Variations: Reusing the 4-pointer layer traversal
 *     model from Spiral Matrix I makes the logic robust, bug-free, and
 *     instantly recognizable.
 *   - Symmetrical Grid Property: Because the grid is strictly square (
 *   - Exact Pre-allocation: Instantiating vector<vector<int>> matrix(n,
 *     vector<int>(n)) allocates memory up front for all
 *   - Key Takeaway: The 4-pointer boundary framework (top, bottom, left,
 *     right) is a universal pattern for 2D matrix ring processing. It scales
 *     seamlessly from reading existing grids to constructing new 2D
 *     structures in O(N 2 ) time.
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            // 1. Fill Top Row
            for (int col = left; col <= right; ++col) {
                matrix[top][col] = num++;
            }
            top++;

            // 2. Fill Right Column
            for (int row = top; row <= bottom; ++row) {
                matrix[row][right] = num++;
            }
            right--;

            // 3. Fill Bottom Row (Safeguard for center cell on odd N)
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    matrix[bottom][col] = num++;
                }
                bottom--;
            }

            // 4. Fill Left Column (Safeguard for center cell on odd N)
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    matrix[row][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};
