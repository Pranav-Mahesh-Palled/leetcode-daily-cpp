/**
 * ============================================================================
 * Problem Name : Swap Nodes in Pairs
 * Day Number   : Day 36
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass through the N nodes of the linked list.
 *   - Space Complexity : O(1) auxiliary space — Operates completely in-place using scalar pointers and a stack-allocated dummy node.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Fast I/O Inside Recursive Calls:
 *   - O(1) Space Preference:
 *   - Key Takeaway: While recursive pointer manipulation is elegant,
 *     converting linked list traversals to an iterative loop with a dummy
 *     node optimizes space complexity from O(N) call stack depth down to
 *     strict O(1) memory.
 * ============================================================================
 */
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Iterate as long as there is a pair of nodes left to swap
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Re-link pointers to perform the swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Advance prev pointer forward to prepared position for next pair
            prev = first;
        }

        return dummy.next;
    }
};
