/**
 * ============================================================================
 * Problem Name : Rotate List
 * Day Number   : Day 71
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass to measure length and close the ring, plus a second partial pass of length N−k to sever the ring.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Ring Creation Strategy: Linking the tail to the head (tail->next =
 *     head) transforms the list into a ring, simplifying rotation into a
 *     single cut operation rather than requiring complex two-pointer gap
 *     tracking.
 *   - Modulo Boundary Reduction: Calculating k = k % length handles cases
 *     where
 *   - Comprehensive Edge Case Guards: The early return if (!head ||
 *     !head->next || k == 0) safely catches empty lists, single-node lists,
 *     and zero-shift rotations before measuring list length.
 *   - Key Takeaway: Converting linear lists into circular rings before
 *     severing them at calculated offsets eliminates pointer offset tracking
 *     and avoids extra array allocation.
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
    ListNode* rotateRight(ListNode* head, int k) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Edge case guards: Empty list, single node, or no rotation needed
        if (!head || !head->next || k == 0) {
            return head;
        }

        // Step 1: Compute list length and locate tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Normalize k
        k = k % length;
        if (k == 0) {
            return head;
        }

        // Step 3: Form circular ring
        tail->next = head;

        // Step 4: Advance length - k steps to find new tail
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        // Step 5: Sever circular ring and extract new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
