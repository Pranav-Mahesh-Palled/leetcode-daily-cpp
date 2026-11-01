/**
 * ============================================================================
 * Problem Name : Reverse Linked List II
 * Day Number   : Day 100
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass up to position right.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - In-Place Front-Insertion (1-Pass Reversal):
 *   - Invariant Maintenance:
 *   - Tech Interview Progression: Reverse Nodes in k-Group (LeetCode 25) In
 *     technical interviews, this exact sublist front-insertion logic is the
 *     core building block for Reverse Nodes in k-Group:
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (!head || left == right) {
            return head;
        }

        // Stack-allocated sentinel dummy node
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        // Step 1: Advance prev to node at position (left - 1)
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // Step 2: Front-insert nodes between left and right
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy.next;
    }
};
