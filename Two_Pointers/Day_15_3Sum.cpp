/**
 * ============================================================================
 * Problem Name : 3Sum
 * Day Number   : Day 15
 * Topic        : Two_Pointers
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(n^2) — O(nlogn) sorting + O(n^2) two-pointer traversal. Pruned early when nums[i] > 0.
 *   - Space Complexity : O(1) auxiliary memory — Modifies nums in-place without auxiliary data structures.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Spot-On Duplicate Avoidance:
 *   - Early Loop Termination (Pruning):
 *   - Optimization: Add if (nums[i] > 0) break; at the start of your outer
 *     loop to save thousands of unnecessary iterations on positive-heavy
 *     arrays.
 *   - Key Takeaway: Sorting the input array opens up two critical advantages:
 *     converting a 3-sum check into a directional two-pointer search ( O(n 2
 *     ) instead of O(n 3 )), and allowing early termination as soon as
 *     candidate values exceed 0.
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        // Fast I/O for 0ms execution in C++
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> result;
        int n = nums.size();

        // Step 1: Sort array in ascending order
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // Early Termination: Smallest number > 0 means sum can never be 0
            if (nums[i] > 0) {
                break;
            }

            // Skip duplicate fixed elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            // Step 2: Two-pointer search
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate left values
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicate right values
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }

        return result;
    }
};
