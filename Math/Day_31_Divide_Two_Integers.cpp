/**
 * ============================================================================
 * Problem Name : Divide Two Integers
 * Day Number   : Day 31
 * Topic        : Math
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(log 2 N) — Binary bit-shift doubling reduces the dividend exponentially.
 *   - Space Complexity : O(1) auxiliary space — Strict 32-bit constant memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Strict 32-Bit Environment Constraint:
 *   - In 32-bit signed arithmetic:
 *   - The Negative Space Trick:
 *   - Key Takeaway: When faced with strict 32-bit signed integer limits where
 *     taking abs() causes overflow on INT_MIN, convert all numbers into
 *     negative space. It keeps the entire algorithm bounded inside standard
 *     32-bit memory!
 * ============================================================================
 */
#include <climits>
#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Edge Case: 32-bit overflow boundary
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of final quotient
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to negative to avoid INT_MIN overflow
        int a = (dividend < 0) ? dividend : -dividend;
        int b = (divisor < 0) ? divisor : -divisor;

        int quotient = 0;

        // Perform logarithmic division in negative space
        while (a <= b) {
            int temp = b;
            int count = 1;

            // Double 'temp' as long as it doesn't underflow INT_MIN
            while (temp >= (INT_MIN >> 1) && a <= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }

            a -= temp;
            quotient += count;
        }

        return negative ? -quotient : quotient;
    }
};
