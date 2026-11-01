/**
 * ============================================================================
 * Problem Name : 4Sum
 * Day Number   : Day 38
 * Topic        : Two_Pointers
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(n^3) worst-case, but runs significantly faster on average due to boundary pruning.
 *   - Space Complexity : O(1) auxiliary space — Operates in-place on the sorted array.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Safe Type Casting:
 *   - Loop Boundary Pruning (Major Performance Boost):
 *   - Minimum Sum Boundary: If nums[i] + nums[i+1] + nums[i+2] + nums[i+3] >
 *     target, any further quadruplets starting with nums[i] will also exceed
 *     target
 *   - Maximum Sum Boundary: If nums[i] + nums[n-1] + nums[n-2] + nums[n-3] <
 *     target, the current nums[i] is too small to reach target even with the
 *     largest available numbers
 *   - Fast I/O Unlinking:
 *   - Key Takeaway: Any k-Sum problem can be generalized to O(n k−1 ) using
 *     nested loops down to 2Sum with Two Pointers. Adding min/max boundary
 *     checks at each outer loop level is the single most effective way to
 *     eliminate unnecessary search paths.
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> result;
        int n = nums.size();

        if (n < 4) return result;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for 'i'
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Pruning 1: Smallest possible 4-sum is greater than target
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;

            // Pruning 2: Largest possible 4-sum is less than target
            if ((long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for 'j'
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Pruning 3: Smallest possible 3-sum with nums[i] & nums[j] is greater than target
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;

                // Pruning 4: Largest possible 3-sum with nums[i] & nums[j] is less than target
                if ((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } 
                    else if (sum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
