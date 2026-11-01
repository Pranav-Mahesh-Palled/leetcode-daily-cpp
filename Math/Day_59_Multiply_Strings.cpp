/**
 * ============================================================================
 * Problem Name : Multiply Strings
 * Day Number   : Day 59
 * Topic        : Math
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N×M) — Multiplies each digit pair once in O(1) arithmetic steps.
 *   - Space Complexity : O(N+M) auxiliary space — Allocates an intermediate digit array of size N+M.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Position Indexing Elegance: Mapping the product of digits at positions
 *     i and j to indices i + j and i + j + 1 handles place values directly
 *     without needing string reversals or alignment padding.
 *   - Direct ASCII Increments: Using res[i+j] += sum / 10 takes advantage of
 *     ASCII offsets ('0' + carry). While functional, using a intermediate
 *     vector<int> array before converting to string improves code readability
 *     and avoids implicit character-level arithmetic.
 *   - Leading Zero Trimming: Your early exit check for "0" ensures that res
 *     contains at most one leading zero at index 0, making res.substr(start)
 *     robust and concise.
 *   - Key Takeaway: Using an intermediate vector<int> array to accumulate
 *     digit products before string building eliminates implicit ASCII
 *     character arithmetic while keeping your O(N×M) time complexity and 0ms
 *     performance intact.
 * ============================================================================
 */
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        const size_t n1 = num1.size();
        const size_t n2 = num2.size();
        std::vector<int> result(n1 + n2, 0);

        // Compute digit products right-to-left
        for (int i = static_cast<int>(n1) - 1; i >= 0; --i) {
            int d1 = num1[i] - '0';
            for (int j = static_cast<int>(n2) - 1; j >= 0; --j) {
                int d2 = num2[j] - '0';
                int sum = d1 * d2 + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert integer vector to result string
        std::string product = "";
        size_t start = (result[0] == 0) ? 1 : 0;
        product.reserve(n1 + n2 - start);

        for (size_t i = start; i < result.size(); ++i) {
            product.push_back(result[i] + '0');
        }

        return product;
    }
};
