/**
 * ============================================================================
 * Problem Name : Set Matrix Zeroes
 * Day Number   : Day 82
 * Topic        : Matrix
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(M×N) — Two linear passes over M×N elements.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - In-Place Marker Allocation:
 *   - Flag Disambiguation (col0):
 *   - Bottom-Up Update Traversal:
 *   - Tech Interview Progression: Space Complexity Evolution In technical
 *     interviews, this problem is frequently used to test space optimization
 *     capabilities:
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        bool col0 = false;

        // Step 1: Scan matrix and use first row & first column as flag markers
        for (int i = 0; i < m; ++i) {
            // Check if first column needs to be zeroed out
            if (matrix[i][0] == 0) {
                col0 = true;
            }

            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Traverse backwards to update interior cells and first column
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }

            // Zero out first column if col0 was marked
            if (col0) {
                matrix[i][0] = 0;
            }
        }
    }
};
