/**
 * ============================================================================
 * Problem Name : 3Sum Closest
 * Day Number   : Day 19
 * Topic        : Two_Pointers
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(n^2) — O(nlogn) sorting + O(n^2) two-pointer traversal.
 *   - Space Complexity : O(1) auxiliary space — Operates in-place on the input array.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Best Practice: Store int n = nums.size(); first, or cast it before
 *     arithmetic.
 *   - Duplicate Skipping Pruning (Optional Speedup):
 *   - Fast I/O Unlinking:
 *   - Key Takeaway: The two-pointer pattern works just as well for
 *     optimization problems (like finding the minimum distance/closest sum)
 *     as it does for exact matching problems, provided the input array is
 *     sorted first.
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Fast I/O for optimal execution time
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            // Pruning: skip identical fixed elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // Early exit on exact match
                if (currentSum == target) {
                    return currentSum;
                }

                // Update closest sum if distance is smaller
                if (std::abs(target - currentSum) < std::abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                // Directional pointer movement
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};
