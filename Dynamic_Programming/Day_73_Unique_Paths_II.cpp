/**
 * ============================================================================
 * Problem Name : Unique Paths II
 * Day Number   : Day 73
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(M×N) — Single pass through all M×N matrix elements.
 *   - Space Complexity : O(N) auxiliary space — Allocates memory for only one row of width N.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - 1D Rolling DP Optimization:
 *   - Early Exit short-circuiting:
 *   - Obstacle State Reset:
 *   - Tech Interview Variation: In-Place Matrix DP ( O(1) Auxiliary Space) In
 *     technical interviews, if the interviewer permits modifying the input
 *     matrix obstacleGrid, you can achieve true O(1) auxiliary space:
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }

        const int m = static_cast<int>(obstacleGrid.size());
        const int n = static_cast<int>(obstacleGrid[0].size());

        // Early Exit: Start or End cell blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        // 1D DP table representing path counts for columns in the current row
        std::vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // Obstacle blocks all incoming paths
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // Combine top (old dp[j]) + left (dp[j-1])
                }
            }
        }

        return dp[n - 1];
    }
};
