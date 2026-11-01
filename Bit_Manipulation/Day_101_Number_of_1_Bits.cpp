/**
 * ============================================================================
 * Problem Name : Number of 1 Bits
 * Day Number   : Day 101
 * Topic        : Bit_Manipulation
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(K) — Bounded strictly by K≤32 bit clears.
 *   - Space Complexity : O(1) auxiliary space — Strict constant memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Output-Sensitive Efficiency:
 *   - Unsigned Type Casting:
 *   - Tech Interview Extension: Hardware Acceleration & C++20 <bit> In system
 *     software, OS kernel development, or high-performance C++ interviews,
 *     you may be asked: "Can we compute the population count faster than O(K)
 *     loops?"
 * ============================================================================
 */
#include <cstdint>
#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int count = 0;
        while (n != 0) {
            n &= (n - 1); // Clear the least significant set bit
            ++count;
        }

        return count;
    }
};
