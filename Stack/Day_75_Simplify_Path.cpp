/**
 * ============================================================================
 * Problem Name : Simplify Path
 * Day Number   : Day 75
 * Topic        : Stack
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single-pass scan over N path characters.
 *   - Space Complexity : O(N) auxiliary space — Stack stores O(N) std::string_view non-allocating string pointers.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Zero-Allocation Token Slicing (std::string_view):
 *   - Temporary String Concatenation Avoidance:
 *   - Result Pre-allocation (reserve):
 *   - Key Takeaway: Replacing std::string::substr() with C++17
 *     std::string_view allows you to parse and manipulate string tokens
 *     entirely in-place without triggering extra heap allocations.
 * ============================================================================
 */
#include <string>
#include <vector>
#include <string_view>
#include <iostream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::string_view> stack;
        const size_t n = path.length();
        size_t i = 0;

        while (i < n) {
            // Skip consecutive slashes
            while (i < n && path[i] == '/') {
                ++i;
            }
            if (i >= n) break;

            size_t start = i;
            while (i < n && path[i] != '/') {
                ++i;
            }

            // Zero-allocation string slice using std::string_view
            std::string_view token(path.data() + start, i - start);

            if (token == ".") {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(token);
            }
        }

        // Base directory case
        if (stack.empty()) {
            return "/";
        }

        // Construct canonical output path cleanly
        std::string result = "";
        result.reserve(n); // Pre-allocate upper bound capacity

        for (const auto& dir : stack) {
            result.push_back('/');
            result.append(dir);
        }

        return result;
    }
};
