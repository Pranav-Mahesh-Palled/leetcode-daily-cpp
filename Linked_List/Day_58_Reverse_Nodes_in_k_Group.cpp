/**
 * ============================================================================
 * Problem Name : Reverse Nodes in k-Group
 * Day Number   : Day 58
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass traversal visiting each node O(1) times.
 *   - Space Complexity : O(1) auxiliary space — Strict constant memory usage operating in-place.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Clean Recursion Structure: Isolating the fast I/O setup in
 *     reverseKGroup and running recursion in reversekGroup avoids redundant
 *     stream-unlinking setup calls across stack frames.
 *   - Call Stack Space Footprint: For a list of size
 *   - O(1) Space Optimization: Technical interviews almost always push for an
 *     iterative
 *   - Key Takeaway: Using a dummy header alongside a getKthNode boundary
 *     helper converts recursive segment reversal into a linear iterative
 *     loop, dropping call stack memory overhead from O(N/k) down to strict
 *     O(1).
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
private:
    // Helper to find the k-th node from a starting node
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (!head || k == 1) return head;

        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break; // Fewer than k nodes remaining -> stop

            ListNode* groupNext = kth->next;
            
            // Reversing the k-group in-place
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Re-link group bounds
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp; // Advance groupPrev to original head (now group tail)
        }

        return dummy.next;
    }
};
