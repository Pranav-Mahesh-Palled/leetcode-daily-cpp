/**
 * ============================================================================
 * Problem Name : Longest Common Prefix
 * Day Number   : Day 4
 * Topic        : Strings
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : * Worst Case: O(S) — where S is the sum of all characters across all strings (when all strings are identical). Average / Best Case: O(N⋅K) — where K is the length of the longest common prefix. The algorithm terminates immediately at the first mismatch character without scanning the rest of the strings.
 *   - Space Complexity : O(1) auxiliary space — substr() constructs the final answer once at the end.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Key Takeaway: "Fail-Fast" logic is a fundamental algorithmic principle.
 *     Whenever a condition for failure is met (a character mismatch), exit
 *     immediately rather than maintaining counters to verify failure at the
 *     end of the iteration.
 * ============================================================================
 */
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        // Iterate through each character position of the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            char currentChar = strs[0][i];

            // Compare character at index 'i' with all other strings
            for (int j = 1; j < strs.size(); ++j) {
                // If index exceeds current string's length OR character mismatches
                if (i == strs[j].size() || strs[j][i] != currentChar) {
                    return strs[0].substr(0, i); // Fail-fast: return prefix found so far
                }
            }
        }

        // If loop completes without mismatch, the entire first string is the prefix
        return strs[0];
    }
};
