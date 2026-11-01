/**
 * ============================================================================
 * Problem Name : Unique Binary Search Trees
 * Day Number   : Day 103
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single loop running N scalar arithmetic updates. 1793543019658.jpeg
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint. 1793543019658.jpeg
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Mathematical Reduction to Catalan Numbers:
 *   - Overflow Protection (long long C):
 *   - Guaranteed Exact Integer Division:
 *   - Tech Interview Contrast: LeetCode 96 vs. LeetCode 95 In technical
 *     interviews, this problem is frequently paired with Unique Binary Search
 *     Trees II (LeetCode 95):
 * ============================================================================
 */
#include <iostream>

class Solution {
public:
    int numTrees(int n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        long long C = 1; // Catalan number C_0 = 1

        for (int i = 1; i <= n; ++i) {
            C = C * 2 * (2 * i - 1) / (i + 1);
        }

        return static_cast<int>(C);
    }
};
