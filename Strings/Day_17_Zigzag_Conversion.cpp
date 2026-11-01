/**
 * ============================================================================
 * Problem Name : Zigzag Conversion
 * Day Number   : Day 17
 * Topic        : Strings
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass to distribute N characters into rows, followed by O(N) total character concatenations.
 *   - Space Complexity : O(N) — Memory needed for storing N characters across numRows row strings.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Avoid Unnecessary String Copies (for (string row : rows)):
 *   - In your final loop:
 *   - for (string row : rows) {
 *   - Pre-allocating Result Memory (reserve):
 *   - Key Takeaway: Simulation solutions like row-bouncing are frequently
 *     preferred over formulaic index math in coding interviews because they
 *     are far less prone to off-by-one errors while maintaining the exact
 *     same optimal O(N) time and space complexity.
 * ============================================================================
 */
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Fast I/O for 0ms execution
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Base cases: single row or row count exceeds string length
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        // Traverse characters and bounce between boundaries
        for (char c : s) {
            rows[currentRow] += c;

            // Change direction at boundary ends
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        // Pre-allocate full string size to prevent reallocations
        std::string result;
        result.reserve(s.length());

        // Concatenate rows using const reference to avoid string copying
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};
