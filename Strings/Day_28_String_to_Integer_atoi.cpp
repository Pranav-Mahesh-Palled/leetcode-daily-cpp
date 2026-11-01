/**
 * ============================================================================
 * Problem Name : String to Integer (atoi)
 * Day Number   : Day 28
 * Topic        : Strings
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass over string s of length N.
 *   - Space Complexity : O(1) auxiliary space — Strict 32-bit constant space.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Signed Integer Overflow (Undefined Behavior in C++):
 *   - Interview Constraint (32-Bit Arithmetic Only):
 *   - Key Takeaway: Relying on larger types (long) to prevent smaller type
 *     overflow (int) can lead to Undefined Behavior with arbitrarily large
 *     inputs. Checking bounds prior to arithmetic operations ensures
 *     rock-solid 32-bit compliance!
 * ============================================================================
 */
#include <iostream>
#include <string>
#include <climits>
#include <cctype>

class Solution {
public:
    int myAtoi(std::string s) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int i = 0;
        const int n = s.length();

        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Determine sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Process digits with strict 32-bit overflow check
        int result = 0;
        while (i < n && std::isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow before multiplying/adding
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
