/**
 * ============================================================================
 * Problem Name : Longest Substring Without Repeating Characters
 * Day Number   : Day 33
 * Topic        : Strings
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass algorithm with strictly constant time operations per character.
 *   - Space Complexity : O(1) — Memory usage is strictly 256 integers.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Signed char Casting Safety:
 *   - Caching String Length:
 *   - Key Takeaway: For string problems where the alphabet size is bounded
 *     (such as ASCII or English letters), prefer fixed-size arrays over hash
 *     maps. It turns dynamic lookup overhead into constant-time array
 *     indexing while keeping space complexity at true O(1).
 * ============================================================================
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Fixed-size lookup array initialized to -1
        std::vector<int> lastIndex(256, -1);

        int maxLength = 0;
        int start = 0;
        const int n = s.length();

        for (int i = 0; i < n; ++i) {
            // Safely cast char to unsigned char to prevent negative array indexing
            unsigned char c = s[i];

            // If character occurred inside current window, jump 'start' past it
            if (lastIndex[c] >= start) {
                start = lastIndex[c] + 1;
            }

            lastIndex[c] = i; // Record latest index of character
            maxLength = std::max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};
