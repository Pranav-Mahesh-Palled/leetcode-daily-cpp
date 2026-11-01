/**
 * ============================================================================
 * Problem Name : Container With Most Water
 * Day Number   : Day 34
 * Topic        : Two_Pointers
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass overall; each index is visited at most once by either pointer.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Optimal Greedy Strategy:
 *   - Inner Pointer Pruning (Micro-Optimization):
 *   - Fast I/O Stream Unlinking:
 *   - Key Takeaway: When faced with a two-pointer area or window problem,
 *     identify which boundary acts as the strict bottleneck. Advancing the
 *     bottleneck boundary is the only move that can improve your result
 *     state.
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int h = std::min(height[left], height[right]);
            int area = (right - left) * h;
            maxWater = std::max(maxWater, area);

            // Skip bars that are <= current bottleneck height 'h'
            while (left < right && height[left] <= h) {
                left++;
            }
            while (left < right && height[right] <= h) {
                right--;
            }
        }

        return maxWater;
    }
};
