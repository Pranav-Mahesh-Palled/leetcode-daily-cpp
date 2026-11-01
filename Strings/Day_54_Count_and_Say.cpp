/**
 * ============================================================================
 * Problem Name : Count and Say
 * Day Number   : Day 54
 * Topic        : Strings
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(2^n) — Bounded strictly by O(L n), where L nis the sequence length at term n.
 *   - Space Complexity : O(2^n) auxiliary space — Bounded by the storage required for term n.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Replacing std::to_string Heap Overhead:
 *   - Buffer Capacity Pre-allocation (reserve):
 *   - Move Semantics (std::move):
 *   - Key Takeaway: Avoid std::to_string inside tight inner loops when
 *     converting small single-digit values. Converting counts directly using
 *     '0' + count combined with push_back() eliminates heap allocation
 *     overhead.
 * ============================================================================
 */
#include <string>
#include <iostream>
#include <utility>

class Solution {
public:
    std::string countAndSay(int n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::string s = "1";

        for (int i = 1; i < n; ++i) {
            std::string next_s;
            next_s.reserve(s.length() * 2); // Pre-allocate buffer space

            int count = 1;
            const size_t len = s.length();

            for (size_t j = 0; j < len; ++j) {
                if (j + 1 < len && s[j] == s[j + 1]) {
                    count++;
                } else {
                    // Append char values directly to avoid std::to_string heap overhead
                    next_s.push_back('0' + count);
                    next_s.push_back(s[j]);
                    count = 1;
                }
            }
            s = std::move(next_s); // Transfer buffer ownership
        }

        return s;
    }
};
