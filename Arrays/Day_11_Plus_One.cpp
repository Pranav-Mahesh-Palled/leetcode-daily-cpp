/**
 * ============================================================================
 * Problem Name : Plus One
 * Day Number   : Day 11
 * Topic        : Arrays
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(n) worst-case (when digits are all 9s), O(1) average-case (terminates on the very first iteration most of the time).
 *   - Space Complexity : O(1) auxiliary space — Modifies the array in-place without vector element shifting.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Vector insert() Overhead:
 *   - Unused Primitive Variable:
 *   - Key Takeaway: Leveraging early return statements inside loops
 *     eliminates complex nested if-else blocks and eliminates redundant state
 *     tracking variables.
 * ============================================================================
 */
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();

        // Traverse right-to-left starting from least significant digit
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // Early Return: Carry propagation stops here
            }
            
            digits[i] = 0; // Carry over to the left
        }

        // If loop completes, all digits were 9 (e.g., [9,9,9] -> [0,0,0])
        // Transform [0, 0, 0] into [1, 0, 0, 0] in O(1) time
        digits[0] = 1;
        digits.push_back(0);

        return digits;
    }
};
