/**
 * ============================================================================
 * Problem Name : Add Binary
 * Day Number   : Day 12
 * Topic        : Math
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(max(N,M)) — We perform a single pass over both strings and reverse the output string at the end.
 *   - Space Complexity : O(max(N,M)) — Auxiliary memory for the output string sum.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Fix: Convert the remainder directly to a char by adding '0':
 *     sum.push_back((currentSum % 2) + '0'); or using bitwise operations:
 *     sum.push_back((currentSum & 1) + '0');.
 *   - String Capacity Buffer (reserve):
 *   - Key Takeaway: You nailed the algorithmic logic! Moving from to_string()
 *     + += to push_back() + reserve() is a key C++ optimization trick that
 *     eliminates object creation overhead in high-performance loops.
 * ============================================================================
 */
#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string sum = "";
        
        // Pre-allocate memory to prevent buffer reallocations
        sum.reserve(std::max(a.size(), b.size()) + 1);

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int currentSum = carry;

            if (i >= 0) {
                currentSum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                currentSum += b[j] - '0';
                j--;
            }

            // Append character directly without creating temp std::string objects
            sum.push_back((currentSum % 2) + '0');
            
            carry = currentSum / 2;
        }

        std::reverse(sum.begin(), sum.end());
        return sum;
    }
};
