/**
 * ============================================================================
 * Problem Name : Length of Last Word
 * Day Number   : Day 10
 * Topic        : Strings
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(k) — Where k is the index distance from the end of the string to the start of the last word. In the worst case (e.g., "hello" or "a "), it is O(n), but on average it finishes as soon as the last word ends without scanning the rest of the string.
 *   - Space Complexity : O(1) — Zero extra allocations.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Mixing Control Signals (continue + break): Skips and breaks inside the
 *     same loop make control flow harder to reason about at a glance.
 *   - Separation of Concerns: A cleaner design separates the process into two
 *     clear phases:
 *   - Phase 1: Skip trailing whitespace.
 *   - Phase 2: Count word length until hitting another space or the beginning
 *     of the string.
 *   - Key Takeaway: When processing data with distinct phases (e.g.,
 *     stripping padding vs. counting data), using dedicated loops for each
 *     phase simplifies control flow and completely removes boundary lookahead
 *     checks.
 * ============================================================================
 */
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int i = s.size() - 1;
        int length = 0;

        // Phase 1: Skip trailing spaces from the end
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Phase 2: Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
