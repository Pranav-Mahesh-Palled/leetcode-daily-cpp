/**
 * ============================================================================
 * Problem Name : Rotate Image
 * Day Number   : Day 63
 * Topic        : Matrix
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N^2) — Visits each matrix element a constant number of times.
 *   - Space Complexity : O(1) auxiliary space — Strict constant memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Two-Step Linear Transformation:
 *   - O(1) Space Compliance:
 *   - Standard Library Qualification:
 *   - Explicitly qualifying standard algorithm utilities as std::swap and
 *     std::reverse adheres to strict production C++ guidelines.
 *   - Tech Interview Summary: Matrix Transformations All 2D grid rotations
 *     can be built by combining diagonal transpose with horizontal/vertical
 *     row reflections:
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const int n = static_cast<int>(matrix.size());

        // Step 1: Transpose matrix in-place (swap matrix[i][j] with matrix[j][i])
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row horizontally
        for (int i = 0; i < n; ++i) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
