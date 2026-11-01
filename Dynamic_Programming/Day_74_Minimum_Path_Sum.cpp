/**
 * ============================================================================
 * Problem Name : Minimum Path Sum
 * Day Number   : Day 74
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : In-Place DP: O(M×N) / 1D Rolling DP: O(M×N)
 *   - Space Complexity : In-Place DP: O(1) / 1D Rolling DP: O(N)
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - O(1) Auxiliary Memory:
 *   - Prefix Sum Initialization:
 *   - Standard Library Qualification:
 *   - Explicitly using std::min avoids potential naming conflicts across
 *     template headers.
 *   - Non-Destructive Alternative (Production Best Practice):
 *   - Key Takeaway: Grid path minimization problems with down/right
 *     constraints can be computed in-place in O(M×N) time and O(1) space. If
 *     input mutability is restricted, rolling 1D DP preserves the grid while
 *     reducing memory usage from O(M×N) to O(N).
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());

        // Step 1: Initialize first row (can only arrive from left)
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        // Step 2: Initialize first column (can only arrive from top)
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        // Step 3: Populate interior DP cells
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};

// ========================================================
// Approach 2: Non-Destructive 1D Rolling DP (
// ========================================================
O(N) Space)
// If mutating input data is disallowed by function contract, use a 1D vector of length
N:

#include <vector>
#include <algorithm>
#include <iostream>

class SolutionNonDestructive {
public:
    int minPathSum(const std::vector<std::vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());

        std::vector<int> dp(n, 0);
        dp[0] = grid[0][0];

        // Initialize first row in rolling vector
        for (int j = 1; j < n; ++j) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; ++i) {
            dp[0] += grid[i][0]; // Update first column element
            for (int j = 1; j < n; ++j) {
                dp[j] = grid[i][j] + std::min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};
