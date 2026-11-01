/**
 * ============================================================================
 * Problem Name : Valid Palindrome
 * Day Number   : Day 55
 * Topic        : Two_Pointers
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass traversal across N characters.
 *   - Space Complexity : O(1) auxiliary space — Strict constant memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Out-of-Bounds Pointer Initialization (Critical Bug):
 *   - Safe Character Type Casting:
 *   - In-Place Two-Pointer Comparison:
 *   - Key Takeaway: Always verify right-side string bounds (s.length() - 1)
 *     when setting up right pointers to prevent out-of-bounds indexing before
 *     entering evaluation loops.
 * ============================================================================
 */
#include <string>
#include <cctype>
#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int left = 0;
        int right = static_cast<int>(s.length()) - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
            }
            // Skip non-alphanumeric characters from right
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
            }

            // Case-insensitive character comparison
            if (std::tolower(static_cast<unsigned char>(s[left])) != 
                std::tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
