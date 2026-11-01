/**
 * ============================================================================
 * Problem Name : Find the Index of the First Occurrence in a String
 * Day Number   : Day 8
 * Topic        : Strings
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O((n−m+1)⋅m) worst-case, but O(n) on average because the inner loop breaks early on the first mismatch.
 *   - Space Complexity : O(1) auxiliary constant space.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Excessive Branching Conditionals:
 *   - Key Takeaway: Avoid manual index rewinding (i-- or i = previous_index)
 *     by expressing string matching through a two-loop sliding window. It
 *     eliminates hidden pointer state bugs while keeping code readable and
 *     interviewer-friendly.
 * ============================================================================
 */
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.size();
        int m = needle.size();

        // Edge case: if needle is longer than haystack, it can never match
        if (m > n) {
            return -1;
        }

        // Iterate outer index up to (n - m)
        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            // Compare haystack[i + j] with needle[j]
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            
            // If all m characters matched, return the starting index
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};

// ========================================================
// Approach 2: Modern C++ Idiomatic Solution (std::string::find)
// ========================================================

// ========================================================
// In production C++, string matching is built into the standard library:
// ========================================================

#include <string>

class SolutionSTL {
public:
    int strStr(std::string haystack, std::string needle) {
        size_t found = haystack.find(needle);
        return (found != std::string::npos) ? static_cast<int>(found) : -1;
    }
};
