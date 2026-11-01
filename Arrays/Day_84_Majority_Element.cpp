/**
 * ============================================================================
 * Problem Name : Majority Element
 * Day Number   : Day 84
 * Topic        : Arrays
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Evaluates N elements in a single O(1) scalar loop.
 *   - Space Complexity : O(1) auxiliary space — Operates using zero extra memory allocations.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Boyer-Moore Voting Mechanics:
 *   - Const Correctness:
 *   - Changing for (int num : nums) to for (const int num : nums) (or passing
 *     const std::vector<int>& nums when read-only) enforces const-correctness
 *     and prevents accidental modification of input values.
 *   - Branchless Counter Increment:
 *   - Tech Interview Progression: Majority Element II (LeetCode 229) In
 *     technical interviews, the standard follow-up is Majority Element II:
 *     Find all elements that appear strictly more than ⌊n/3⌋ times.
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
public:
    int majorityElement(const std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int candidate = 0;
        int count = 0;

        for (const int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
