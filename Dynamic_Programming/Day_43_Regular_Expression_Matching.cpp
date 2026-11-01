/**
 * ============================================================================
 * Problem Name : Regular Expression Matching
 * Day Number   : Day 43
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(∣S∣×∣P∣) — Nested loops compute each table entry in O(1) time.
 *   - Space Complexity : O(∣S∣×∣P∣) auxiliary space — Strict table allocation with zero recursion stack overhead.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Class Member State Encapsulation:
 *   - Boolean Matrix Efficiency:
 *   - Iterative Tabular (Bottom-Up) Alternative:
 *   - Key Takeaway: When handling pattern-matching algorithms with *
 *     wildcards, working backwards (bottom-up from the end of the strings)
 *     simplifies boundary condition checks and transforms recursive branching
 *     into straightforward table lookups.
 * ============================================================================
 */
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const int m = s.length();
        const int n = p.length();

        // dp[i][j] represents whether s[i...] matches p[j...]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // Base case: empty string matches empty pattern
        dp[m][n] = true;

        // Populate table from bottom-right (end of strings) to top-left (start)
        for (int i = m; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                bool firstMatch = (i < m && (s[i] == p[j] || p[j] == '.'));

                // Case 1: Pattern contains '*' as next character
                if (j + 1 < n && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                } 
                // Case 2: Standard single-character comparison
                else {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};
