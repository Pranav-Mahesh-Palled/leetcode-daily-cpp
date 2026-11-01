/**
 * ============================================================================
 * Problem Name : Integer to Roman
 * Day Number   : Day 22
 * Topic        : Math
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(1) — Hard limit of 13 value checks and at most 15 character appends.
 *   - Space Complexity : O(1) auxiliary space — Memory is fully static and zero runtime allocations are performed for lookup structures.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Eliminate Heap Allocations on Every Call:
 *   - In your implementation:
 *   - Each invocation of intToRoman() constructs 13 dynamic std::string
 *     objects on the stack.
 *   - Best Practice: Mark the mapping as static constexpr using plain string
 *     literals (const char* or std::string_view). This embeds the static
 *     array in read-only compiled binary data, eliminating memory allocations
 *     on function execution entirely.
 *   - Structure with std::pair or Parallel Arrays:
 *   - Grouping values and symbols into a single data structure (like
 *     std::pair<int, const char*>) improves code maintainability and prevents
 *     index mismatch bugs if the mapping ever needs modification.
 *   - String Pre-allocation (reserve):
 *   - Key Takeaway: When working with fixed lookup tables in C++, always
 *     prefer static constexpr arrays of primitive types or const char* over
 *     standard containers like std::string or std::vector inside function
 *     bodies. This guarantees maximum memory efficiency and speed.
 * ============================================================================
 */
#include <string>
#include <utility>
#include <iostream>

class Solution {
public:
    std::string intToRoman(int num) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Pre-computed static lookup stored in read-only memory
        static constexpr std::pair<int, const char*> ROMAN_MAP[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
            {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
            {1,    "I"}
        };

        std::string result;
        result.reserve(15); // Max length for num <= 3999 is 15 ("MMMDCCCLXXXVIII")

        for (const auto& [value, symbol] : ROMAN_MAP) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};
