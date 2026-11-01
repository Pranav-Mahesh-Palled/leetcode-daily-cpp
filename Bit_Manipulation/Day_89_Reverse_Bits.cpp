/**
 * ============================================================================
 * Problem Name : Reverse Bits
 * Day Number   : Day 89
 * Topic        : Bit_Manipulation
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(1) — Exactly 5 constant-time arithmetic steps.
 *   - Space Complexity : O(1) auxiliary space — Strict constant register memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Parallel Bit-Swizzling Elegance:
 *   - Fast I/O Inclusion:
 *   - Tech Interview Follow-Up: High-Throughput Stream Processing
 *     (Memoization) In technical interviews, a standard follow-up is: "If
 *     reverseBits is called billions of times in a real-time stream (e.g.,
 *     packet processing or graphics rendering), how do you optimize it
 *     further?"
 * ============================================================================
 */
#include <cstdint>
#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        n = (n >> 16) | (n << 16);
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);

        return n;
    }
};
