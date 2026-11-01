/**
 * ============================================================================
 * Problem Name : Roman to Integer
 * Day Number   : Day 3
 * Topic        : Strings
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(n) — Performs a single pass over the string of length n. Each lookup via getValue is O(1).
 *   - Space Complexity : O(1) — Uses zero extra memory heap allocations.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Repetitive Lookahead Logic: Hardcoding every subtractive pair (IV, IX,
 *     XL, XC, CD, CM) leads to a lengthy switch statement that is hard to
 *     maintain. If new rules were introduced, every case branch would need
 *     updates.
 *   - Modifying Loop Variable Inside Loop Body: Mutating i (i++) inside
 *     specific switch cases while i is also managed by for (i = 0; ...; i++)
 *     makes control flow harder to trace during code reviews and debugging.
 *   - Variable Scoping: Declaring int i, sum = 0, n = s.size(); before the
 *     loop leaks i into the function scope. Keep int i = 0 scoped inside the
 *     for loop header.
 *   - Key Takeaway: Identifying a general mathematical pattern ( curr<next)
 *     eliminates complex branching and manual index manipulation, turning a
 *     60-line solution into clean, declarative code.
 * ============================================================================
 */
#include <string>

class Solution {
private:
    // Helper function to map Roman characters to integer values
    inline int getValue(char ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

public:
    int romanToInt(std::string s) {
        int total = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            int current = getValue(s[i]);
            int next = (i + 1 < n) ? getValue(s[i + 1]) : 0;

            // If current symbol is smaller than the next, subtract it; otherwise add it
            if (current < next) {
                total -= current;
            } else {
                total += current;
            }
        }

        return total;
    }
};
