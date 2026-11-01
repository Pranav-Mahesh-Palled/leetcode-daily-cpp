/**
 * ============================================================================
 * Problem Name : Pascal's Triangle
 * Day Number   : Day 49
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(numRows^2) — Computes each element in the triangle exactly once.
 *   - Space Complexity : O(1) auxiliary space — Output memory of size O(numRows^2) is required by problem statement.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Boundary Initialization Trick: Initializing row i with 1s via .resize(i
 *     + 1, 1) eliminates manual boundary assignments for the start and end of
 *     every row.
 *   - Outer Vector Pre-allocation: Passing numRows to vector<vector<int>>
 *     triangle(numRows) reserves the exact outer array capacity up front,
 *     preventing dynamic vector reallocations.
 *   - Idiomatic Row Construction: Replacing .resize(i + 1, 1) with direct
 *     vector constructor assignment triangle[i] = std::vector<int>(i + 1, 1);
 *     makes intent explicit while maintaining optimal performance.
 *   - Tech Interview Follow-Up: Pascal's Triangle II ( O(k) Space)
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> triangle(numRows);

        for (int i = 0; i < numRows; ++i) {
            // Allocate row 'i' of size (i + 1) filled with default 1s
            triangle[i] = std::vector<int>(i + 1, 1);

            // Populate interior values using the row above
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        return triangle;
    }
};
