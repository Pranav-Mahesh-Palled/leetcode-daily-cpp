/**
 * ============================================================================
 * Problem Name : Two Sum
 * Day Number   : Day 1
 * Topic        : Arrays
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(n) — We traverse the array of n elements exactly once. Inserting and searching in std::unordered_map takes O(1) average time.
 *   - Space Complexity : O(n) — In the worst case, we store up to n elements in the hash map.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Algorithm Efficiency: Your current implementation uses nested for
 *     loops. For every element
 *   - Variable Scoping (Modern C++ Best Practice): In C++, it's best practice
 *     to keep variable declarations as close to their usage as possible.
 *     Declaring int i, j; at the top of the function leaks their scope
 *     outside the loops. Declare them inside the loop header instead (for
 *     (int i = 0; ...)).
 *   - Key Takeaway: Trading O(n) extra space via a Hash Map drops our runtime
 *     from O(n 2 ) down to O(n), which is the theoretical lower bound for
 *     this problem.
 * ============================================================================
 */
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map to store array values and their corresponding indices
        std::unordered_map<int, int> num_to_index;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            
            // Check if complement exists in the map
            auto it = num_to_index.find(complement);
            if (it != num_to_index.end()) {
                return {it->second, i}; // Return pair of indices
            }
            
            // Store current value and its index for future lookups
            num_to_index[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no pair exists
    }
};
