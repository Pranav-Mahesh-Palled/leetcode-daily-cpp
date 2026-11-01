/**
 * ============================================================================
 * Problem Name : Remove Duplicates from Sorted List II
 * Day Number   : Day 95
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass traversal across N list nodes.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Cluster Bypassing via Rewiring:
 *   - Linear Pointer Progression:
 *   - Tech Interview Contrast: LeetCode 83 vs. LeetCode 82 In technical
 *     interviews, this pair of problems is frequently contrasted:
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
    ListNode* deleteDuplicates(ListNode* head) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Stack-allocated sentinel dummy node
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head != nullptr) {
            // Check if current node starts a sequence of duplicates
            if (head->next != nullptr && head->val == head->next->val) {
                // Move head to the last node of the duplicate sequence
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Link prev to skip all duplicate nodes
                prev->next = head->next;
            } else {
                // No duplicate found; advance prev
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy.next;
    }
};
