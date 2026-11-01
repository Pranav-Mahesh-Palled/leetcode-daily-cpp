/**
 * ============================================================================
 * Problem Name : Excel Sheet Column Title
 * Day Number   : Day 83
 * Topic        : Math
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(log 26(columnNumber)) — Executes ≤7 operations.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Bijective Base-26 Offset Shift (columnNumber--):
 *   - Optimal LIFO Character Accumulation:
 *   - Capacity Reserve Optimization:
 *   - Tech Interview Companion: Excel Sheet Column Number (LeetCode 171) In
 *     technical interviews, interviewers frequently ask for the inverse
 *     operation (converting a string title like "AB" back into its 1-based
 *     integer equivalent 28):
 * ============================================================================
 */
#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::string result = "";
        result.reserve(8); // Upper bound for 32-bit int string length

        while (columnNumber > 0) {
            --columnNumber; // Shift 1-based index to 0-based domain
            result.push_back(static_cast<char>('A' + (columnNumber % 26)));
            columnNumber /= 26;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
