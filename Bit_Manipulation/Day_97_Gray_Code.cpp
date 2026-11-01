/**
 * ============================================================================
 * Problem Name : Gray Code
 * Day Number   : Day 97
 * Topic        : Bit_Manipulation
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(2^n) — Evaluates 2 n elements in a single linear bitwise pass.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Const Correctness:
 *   - Tech Interview Extension: Inverse Conversion (Gray Code to Binary) In
 *     technical interviews, interviewers often ask the inverse question:
 *     "Given a Gray code integer G, convert it back to standard binary B."
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const int totalCount = 1 << n;
        std::vector<int> result(totalCount);

        for (int i = 0; i < totalCount; ++i) {
            result[i] = i ^ (i >> 1);
        }

        return result;
    }
};
