/**
 * ============================================================================
 * Problem Name : Add Two Numbers
 * Day Number   : Day 30
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(max(M,N)) — Single traversal through both lists.
 *   - Space Complexity : O(max(M,N)) — Required memory for the newly constructed output list. Auxiliary space remains O(1).
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Stack-Allocated Dummy Node:
 *   - Unified Termination Condition:
 *   - Idiomatic C++ Pointer Checks:
 *   - Key Takeaway: Using a stack-allocated dummy node (ListNode dummy(0);)
 *     is a standard C++ design pattern for linked list construction. It
 *     simplifies pointer wiring and guarantees clean memory handling without
 *     manual deletion.
 * ============================================================================
 */
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        // Process both lists and any remaining carry digit
        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }
};
