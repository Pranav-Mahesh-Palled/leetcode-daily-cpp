/**
 * ============================================================================
 * Problem Name : Valid Sudoku
 * Day Number   : Day 44
 * Topic        : Matrix
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(1) — Performs 81 iterations of O(1) bitwise operations.
 *   - Space Complexity : O(1) auxiliary space — Compresses grid tracking memory down to just 27 standard integer variables.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Avoid Hash Sets for Fixed Grids:
 *   - Sub-Box Formula:
 *   - Bitmasking Optimization (Tech Interview Level):
 *   - Tech Interview Level): Since digits range strictly from 1 to 9, you can
 *     replace the boolean arrays with a single 32-bit int array for rows,
 *     columns, and boxes. Checking if digit k exists simplifies to a bitwise
 *     AND operation (rows[r] & (1 << digit)), compressing space down to 27
 *     total integers.
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int digit = board[r][c] - '1';
                int mask = 1 << digit; // Bitmask corresponding to digit
                int boxIndex = (r / 3) * 3 + (c / 3);

                // Check if digit bit is already set in row, col, or box
                if ((rows[r] & mask) || (cols[c] & mask) || (boxes[boxIndex] & mask)) {
                    return false;
                }

                // Set bit for digit using bitwise OR
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIndex] |= mask;
            }
        }

        return true;
    }
};
