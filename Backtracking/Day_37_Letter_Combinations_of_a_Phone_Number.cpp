/**
 * ============================================================================
 * Problem Name : Letter Combinations of a Phone Number
 * Day Number   : Day 37
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(4 N ⋅N) — Explores every valid leaf combination in the search tree.
 *   - Space Complexity : O(N) auxiliary space — Bounded by N call stack frames and the single string buffer.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - std::function Wrapper Overhead:
 *   - Declaring std::function<void(int)> backtrack introduces type-erasure
 *     and function call wrapper overhead on every recursive step. Moving the
 *     logic to a private member function eliminates this extra layer of
 *     runtime overhead.
 *   - String Buffer Pre-allocation:
 *   - Key Takeaway: Replace std::unordered_map with fixed-size array lookups
 *     whenever keys can be converted directly into integer array indices
 *     (like char - '0'). Combining flat array indexing with private helper
 *     functions removes hash map overhead and function wrapper costs.
 * ============================================================================
 */
#include <vector>
#include <string>
#include <iostream>

class Solution {
private:
    // Direct array lookup indexed by digit integer value
    const std::string mapping[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const std::string& digits, int index, std::string& current, std::vector<std::string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        const std::string& letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, result);
            current.pop_back(); // Backtrack state
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (digits.empty()) return {};

        std::vector<std::string> result;
        std::string current;
        current.reserve(digits.size());

        backtrack(digits, 0, current, result);
        return result;
    }
};
