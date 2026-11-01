/**
 * ============================================================================
 * Problem Name : Longest Palindromic Substring
 * Day Number   : Day 29
 * Topic        : Dynamic_Programming
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N^2) — Each of the 2N−1 centers expands up to O(N) bounds in the worst case (e.g., "aaaaa").
 *   - Space Complexity : O(1) auxiliary space — Only primitive integer variables (start, maxLen, pointers) are stored; s.substr is executed exactly once at the end.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Code Duplication:
 *   - Index Tracking vs String Building:
 *   - Tech Interview Note: While Manacher's Algorithm exists and achieves
 *     O(N) time complexity, standard tech interviews prefer and expect Expand
 *     Around Center ( O(N 2 ) time, O(1) space) because it is bug-free to
 *     write under timed conditions while maintaining optimal space usage.
 * ============================================================================
 */
#include <iostream>
#include <string>
#include <algorithm>

class Solution {
private:
    // Helper function to expand outward from a given center pair
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Length of palindrome found: (right - 1) - (left + 1) + 1
        return right - left - 1;
    }

public:
    std::string longestPalindrome(std::string s) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (s.empty()) return "";

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Expand for odd-length palindromes (center at i)
            int len1 = expandAroundCenter(s, i, i);
            // Expand for even-length palindromes (center between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = std::max(len1, len2);

            // Update bounds if a longer palindrome is found
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
