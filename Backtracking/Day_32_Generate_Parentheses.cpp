/**
 * ============================================================================
 * Problem Name : Generate Parentheses
 * Day Number   : Day 32
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O( n4 n) — Generates exactly C nvalid sequences without spending time on invalid branches.
 *   - Space Complexity : O(n) auxiliary space — Bounded by 2n call stack depth and a single reusable string buffer.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Fix: Keep result local to generateParenthesis() and pass it by
 *     reference (vector<string>& result) to your recursive helper.
 *   - Fix: Use standard backtracking with a single reference string
 *     (std::string& current). Modify it using current.push_back('(') before
 *     the call and current.pop_back() immediately after to undo the choice.
 *   - String Buffer Pre-allocation (reserve):
 *   - Key Takeaway: Avoid global or class-member result buffers in LeetCode
 *     functions to prevent state contamination across test runs. In recursive
 *     backtracking, mutating and restoring a single reference parameter with
 *     push_back and pop_back is drastically faster than string concatenation.
 * ============================================================================
 */
#include <vector>
#include <string>
#include <iostream>

class Solution {
private:
    void backtrack(std::vector<std::string>& result, std::string& current, int open, int close, int n) {
        // Base case: a valid sequence of length 2*n is formed
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Choice 1: Add opening parenthesis
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back(); // Backtrack
        }

        // Choice 2: Add closing parenthesis
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back(); // Backtrack
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::string> result;
        std::string current;
        current.reserve(2 * n); // Pre-allocate buffer for maximum efficiency

        backtrack(result, current, 0, 0, n);
        return result;
    }
};
