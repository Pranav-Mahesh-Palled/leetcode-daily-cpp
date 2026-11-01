/**
 * ============================================================================
 * Problem Name : Unique Paths
 * Day Number   : Day 72
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(min(m,n)) — Executes strictly min(m−1,n−1) constant-time arithmetic operations.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Minimizing Loop Iterations:
 *   - Exact Integer Division Guarantee:
 *   - Signed Overflow Prevention:
 *   - Tech Interview Context: Dynamic Programming Alternative In technical
 *     interviews, interviewers often present this problem as an introduction
 *     to Dynamic Programming:
 * ============================================================================
 */
#include <algorithm>
#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Total steps required: N = (m - 1) + (n - 1)
        const int N = m + n - 2;
        const int k = std::min(m - 1, n - 1);

        long long result = 1;

        // Compute C(N, k) = (N * (N-1) * ... * (N-k+1)) / (k * (k-1) * ... * 1)
        for (int i = 1; i <= k; ++i) {
            result = result * (N - k + i) / i;
        }

        return static_cast<int>(result);
    }
};
