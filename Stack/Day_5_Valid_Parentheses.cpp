/**
 * ============================================================================
 * Problem Name : Valid Parentheses
 * Day Number   : Day 5
 * Topic        : Stack
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(n) — Single pass over string s of length n. Stack push, pop, and top operations run in O(1) constant time.
 *   - Space Complexity : O(n) — In the worst-case scenario, the stack stores up to n/2 characters.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Early Exit for Odd Length Strings:
 *   - Complex Conditionals:
 *   - Your closing bracket check:
 *   - Modern C++ Idioms:
 *   - Using a range-based for loop (for (char c : s)) avoids indexing s[i],
 *     avoids signed/unsigned compiler warnings, and eliminates the outer
 *     variable declaration char top;.
 *   - Key Takeaway: Storing the expected target state (the closing bracket)
 *     rather than the current state (the opening bracket) eliminates
 *     conditional complexity and makes code far easier to read and maintain.
 * ============================================================================
 */
#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        // Fast exit: odd length strings can never have matching pairs
        if (s.size() % 2 != 0) {
            return false;
        }

        std::stack<char> st;

        for (char c : s) {
            // Push the expected CLOSING bracket onto the stack
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } 
            // If stack is empty OR current char doesn't match the expected top
            else if (st.empty() || st.top() != c) {
                return false;
            } 
            else {
                st.pop(); // Valid match found, pop from stack
            }
        }

        // Returns true if all opened brackets were properly matched and popped
        return st.empty();
    }
};
