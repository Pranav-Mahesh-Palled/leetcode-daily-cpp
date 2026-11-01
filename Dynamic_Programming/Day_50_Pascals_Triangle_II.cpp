/**
 * ============================================================================
 * Problem Name : Pascal's Triangle II
 * Day Number   : Day 50
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Runs strictly N/2 loop iterations due to row symmetry.
 *   - Space Complexity : O(1) auxiliary space — Excludes required output array memory.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - O(N) Optimization: Computing row elements directly via
 *   - Integer Overflow Safety: Using long long current safely prevents 32-bit
 *     signed integer overflow during intermediate multiplication before
 *     division occurs.
 *   - Exploiting Row Symmetry: Pascal's triangle rows are symmetric (
 *   - Key Takeaway: When generating combinatorial sequences like Pascal's
 *     triangle rows, combining algebraic recurrence relations with row
 *     symmetry collapses O(N 2 ) dynamic programming down to O(N) linear time
 *     using half the arithmetic operations.
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<int> row(rowIndex + 1, 1);
        long long current = 1;

        // Compute up to midpoint and mirror across row symmetry
        for (int i = 1; i <= rowIndex / 2; ++i) {
            current = current * (rowIndex - i + 1) / i;
            row[i] = current;
            row[rowIndex - i] = current; // Mirror value to right side
        }

        return row;
    }
};
