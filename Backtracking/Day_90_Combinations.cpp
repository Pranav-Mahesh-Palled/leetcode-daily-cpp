/**
 * ============================================================================
 * Problem Name : Combinations
 * Day Number   : Day 90
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(k⋅( k n)) — Strictly proportional to the total number of output elements.
 *   - Space Complexity : O(k) auxiliary space — Constant stack depth k and single working vector footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Search Space Pruning (maxStart):
 *   - Working Buffer Capacity Reservation:
 *   - In-Place State Restoration:
 *   - Tech Interview Alternative: Bitwise Generation (Gosper's Hack) For
 *     constraints where n≤32, combinations can be generated iteratively
 *     without recursion using Gosper's Hack to manipulate bitmasks with k set
 *     bits in lexicographical order:
 * ============================================================================
 */
#include <vector>
#include <iostream>

class Solution {
private:
    void backtrack(int start, int n, int k, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (current.size() == static_cast<size_t>(k)) {
            result.push_back(current);
            return;
        }

        // Upper-bound search pruning
        const int remainingNeeded = k - static_cast<int>(current.size());
        const int maxStart = n - remainingNeeded + 1;

        for (int i = start; i <= maxStart; ++i) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, result);
            current.pop_back(); // Backtrack state
        }
    }

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> result;
        std::vector<int> current;
        current.reserve(k);

        backtrack(1, n, k, current, result);
        return result;
    }
};
