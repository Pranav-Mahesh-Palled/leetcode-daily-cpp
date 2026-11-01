/**
 * ============================================================================
 * Problem Name : Restore IP Addresses
 * Day Number   : Day 102
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(1) — Evaluates at most 27 iterations with constant-time string construction.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Iterative 3-Loop Slicing:
 *   - Efficient Scalar Validation (isValid):
 *   - Eliminating Temporary String Allocations:
 *   - Tech Interview Contrast: Iterative Slicing vs. Recursive Backtracking
 *     In technical interviews, this problem can be approached via two
 *     paradigms:
 * ============================================================================
 */
#include <string>
#include <vector>
#include <iostream>

class Solution {
private:
    inline bool isValid(const std::string& s, int start, int len) {
        if (len == 1) {
            return true; // Single digit (0-9) is always valid
        }
        if (s[start] == '0') {
            return false; // Leading zeros disallowed for len > 1
        }
        if (len == 2) {
            return true; // Two digits (10-99) always valid
        }
        // 3-digit validation (100-255)
        const int val = (s[start] - '0') * 100 + (s[start + 1] - '0') * 10 + (s[start + 2] - '0');
        return val <= 255;
    }

public:
    std::vector<std::string> restoreIpAddresses(const std::string& s) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const int n = static_cast<int>(s.length());
        if (n < 4 || n > 12) {
            return {};
        }

        std::vector<std::string> result;
        result.reserve(19); // Max theoretical valid IPv4 addresses for 12 digits

        for (int i = 1; i <= 3 && i < n; ++i) {
            if (!isValid(s, 0, i)) continue;

            for (int j = 1; j <= 3 && i + j < n; ++j) {
                if (!isValid(s, i, j)) continue;

                for (int k = 1; k <= 3 && i + j + k < n; ++k) {
                    const int l = n - i - j - k;
                    if (l >= 1 && l <= 3) {
                        if (isValid(s, i + j, k) && isValid(s, i + j + k, l)) {
                            // Single string allocation using pre-reserved buffer
                            std::string ip;
                            ip.reserve(n + 3);
                            ip.append(s, 0, i).push_back('.');
                            ip.append(s, i, j).push_back('.');
                            ip.append(s, i + j, k).push_back('.');
                            ip.append(s, i + j + k, l);

                            result.push_back(std::move(ip));
                        }
                    }
                }
            }
        }

        return result;
    }
};
