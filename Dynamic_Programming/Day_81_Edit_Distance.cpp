/**
 * ============================================================================
 * Problem Name : Edit Distance
 * Day Number   : Day 81
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(M×N) — Single grid pass over all character combinations.
 *   - Space Complexity : O(min(M,N)) auxiliary space — Strict linear vector memory proportional to the shorter string.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Minimizing Memory Dimension:
 *   - Diagonal Preserving 1D DP State:
 *   - Clean Mapping of Operations:
 *   - prev (Top-Left Diagonal): Replace a character in word1.
 *   - Tech Interview Variation: Reconstructing the Edit Script vs. Space
 *     Trade-offs In technical interviews and real-world software engineering
 *     (e.g., git diff, spell checkers, DNA sequence alignment):
 * ============================================================================
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minDistance(const std::string& word1, const std::string& word2) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int m = static_cast<int>(word1.length());
        int n = static_cast<int>(word2.length());

        // Base cases: Converting from/to empty string
        if (m == 0) return n;
        if (n == 0) return m;

        // Space optimization: Ensure word2 is the shorter string
        if (m < n) {
            return minDistance(word2, word1);
        }

        // 1D DP table representing edits required for the shorter string
        std::vector<int> dp(n + 1);
        for (int j = 0; j <= n; ++j) {
            dp[j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            int prev = dp[0]; // Stores DP[i-1][j-1]
            dp[0] = i;       // Base case: Deleting i characters from word1

            for (int j = 1; j <= n; ++j) {
                int temp = dp[j]; // Store DP[i-1][j] for the next iteration's prev

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = 1 + std::min({dp[j], dp[j - 1], prev});
                }

                prev = temp;
            }
        }

        return dp[n];
    }
};
