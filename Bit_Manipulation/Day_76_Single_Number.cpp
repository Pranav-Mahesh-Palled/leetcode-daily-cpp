/**
 * ============================================================================
 * Problem Name : Single Number
 * Day Number   : Day 76
 * Topic        : Bit_Manipulation
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass iteration over N integers.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Bitwise XOR Properties:
 *   - Zero Allocation Footprint:
 *   - C++ STL Functional Alternative:
 *   - Tech Interview Progression: The Single Number Trilogy In technical
 *     interviews, this problem serves as the baseline for a classic
 *     bit-manipulation series:
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    int singleNumber(const std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int result = 0;
        for (const int num : nums) {
            result ^= num;
        }

        return result;
    }
};

// ========================================================
// Approach 2: Functional C++ Idiom (std::accumulate)
// ========================================================
#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

class SolutionFunctional {
public:
    int singleNumber(const std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};
