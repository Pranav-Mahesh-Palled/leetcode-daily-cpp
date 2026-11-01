/**
 * ============================================================================
 * Problem Name : Excel Sheet Column Number
 * Day Number   : Day 85
 * Topic        : Math
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(L) — Single linear pass over L characters ( L≤7).
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Changing parameter pass-by-value string columnTitle to const
 *     std::string& columnTitle in standard production interfaces avoids
 *     unnecessary string copying when passing references.
 *   - Loop Range Qualifier:
 *   - Using for (const char c : columnTitle) enforces const-correctness
 *     during character iteration.
 *   - Tech Interview Summary: Complementary Dual Problems This problem
 *     completes the two-way Excel conversion pair:
 * ============================================================================
 */
#include <string>
#include <iostream>

class Solution {
public:
    int titleToNumber(const std::string& columnTitle) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int result = 0;

        for (const char c : columnTitle) {
            const int digit = c - 'A' + 1;
            result = result * 26 + digit;
        }

        return result;
    }
};
