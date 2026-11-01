/**
 * ============================================================================
 * Problem Name : Partition List
 * Day Number   : Day 96
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single linear pass across N nodes. 1792921321384.jpeg
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory usage. 1792921321384.jpeg
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Stack-Allocated Sentinels (ListNode lessHead(0)):
 *   - Preserving Relative Order (Stability):
 *   - Tech Interview Application: QuickSort on Linked Lists In technical
 *     interviews, this exact problem forms the core partitioning subroutine
 *     for implementing QuickSort on Linked Lists:
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
    ListNode* partition(ListNode* head, int x) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Stack-allocated sentinel head nodes
        ListNode lessHead(0);
        ListNode greaterHead(0);

        ListNode* less = &lessHead;
        ListNode* greater = &greaterHead;

        // Partition nodes into respective buckets
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Sever potential trailing cyclic references
        greater->next = nullptr;

        // Connect the end of the less list to the start of the greater list
        less->next = greaterHead.next;

        return lessHead.next;
    }
};
