/**
 * ============================================================================
 * Problem Name : Linked List Cycle
 * Day Number   : Day 77
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single linear pass bounded by O(K+C) where K is tail length and C is cycle length.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Robust Boundary Checks:
 *   - Constant Memory Advantage:
 *   - Compared to storing visited node addresses in a hash set
 *     (std::unordered_set<ListNode*>) which requires
 *   - Tech Interview Follow-Up: Linked List Cycle II (Find Cycle Entry Node)
 *     In technical interviews, the standard follow-up is Linked List Cycle II
 *     (LeetCode 142): Return the exact node where the cycle begins.
 * ============================================================================
 */
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Early exit for empty list or single node without cycle
        if (!head || !head->next) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Advance fast by 2 steps and slow by 1 step
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // Meeting point indicates a cycle
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
