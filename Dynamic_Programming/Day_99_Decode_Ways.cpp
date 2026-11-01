/**
 * ============================================================================
 * Problem Name : Decode Ways
 * Day Number   : Day 99
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass evaluation of N characters.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - O(1) Space Compression:
 *   - Early Exit on Invalid Sequences:
 *   - Accepting const std::string& s instead of passing std::string s by
 *     value avoids making a copy of the input string upon function entry.
 *   - Tech Interview Progression: Decode Ways II (LeetCode 639) In technical
 *     interviews, the standard follow-up is Decode Ways II: The input string
 *     may contain wildcard character '*', which can represent any digit from
 *     '1' to '9'.
 * ============================================================================
 */
#include <string>
#include <iostream>

class Solution {
public:
    int numDecodings(const std::string& s) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Base case: empty string or leading zero cannot be decoded
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        const int n = static_cast<int>(s.length());
        int prev2 = 1; // Represents DP[i-2]
        int prev1 = 1; // Represents DP[i-1]

        for (int i = 1; i < n; ++i) {
            int current = 0;

            // Single digit decoding (1-9)
            if (s[i] != '0') {
                current += prev1;
            }

            // Two digit decoding (10-26)
            const int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            // If no valid transition exists at this character, string is invalid
            if (current == 0) {
                return 0;
            }

            // Shift DP state forward
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
