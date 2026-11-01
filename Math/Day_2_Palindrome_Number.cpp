/**
 * ============================================================================
 * Problem Name : Palindrome Number
 * Day Number   : Day 2
 * Topic        : Math
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(log 10(n)) — We divide the input by 10 in every iteration, and we only process half the digits (e.g., for a 10-digit number, we loop at most 5 times).
 *   - Space Complexity : O(1) — Strictly constant space using standard 32-bit int arithmetic, completely immune to integer overflow.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Avoiding Overflow / long Usage: Reversing an entire 32-bit integer into
 *     another 32-bit integer can cause standard int overflow (e.g., reversing
 *     2147483647 gives 7463847412, which exceeds 32-bit max integer limits).
 *     While long prevents a runtime crash in C++, we can avoid 64-bit
 *     integers entirely by reversing only half of the number.
 *   - Early Exit for Trailing Zeros: Any number ending in 0 (except 0 itself)
 *     cannot be a palindrome because no positive integer starts with 0 (e.g.,
 *     10 reversed is 01). Adding a check for x % 10 == 0 lets us exit
 *     immediately without looping.
 *   - Key Takeaway: Reversing only half of an integer prevents overflow risks
 *     entirely, eliminates the need for 64-bit integer types like long, and
 *     cuts loop iterations in half.
 * ============================================================================
 */
class Solution {
public:
    bool isPalindrome(int x) {
        // Edge cases:
        // 1. Negative numbers are not palindromes (e.g., -121 -> 121-)
        // 2. Numbers ending in 0 (except 0 itself) are not palindromes (e.g., 10 -> 01)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reverted_number = 0;

        // Reverse only the trailing half of the number
        while (x > reverted_number) {
            reverted_number = (reverted_number * 10) + (x % 10);
            x /= 10;
        }

        // When the length is odd, we can get rid of the middle digit by reverted_number / 10
        // For example when the input is 12321, at the end of the loop we get x = 12, reverted_number = 123
        return x == reverted_number || x == reverted_number / 10;
    }
};
