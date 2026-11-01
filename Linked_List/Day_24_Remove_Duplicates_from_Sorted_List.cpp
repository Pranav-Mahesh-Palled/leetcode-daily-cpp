/**
 * ============================================================================
 * Problem Name : Remove Duplicates from Sorted List
 * Day Number   : Day 24
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single traversal through the N nodes of the list.
 *   - Space Complexity : O(1) auxiliary space — Strictly constant space usage.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Handling Multiple Duplicates:
 *   - C++ Memory Management (Interview Consideration):
 *   - Key Takeaway: When deleting nodes from dynamic data structures in C++,
 *     always remember to explicitly free dynamic heap allocations with
 *     delete. It turns acceptable problem-solving code into production-ready
 *     software!
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
    ListNode* deleteDuplicates(ListNode* head) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // Free duplicate node memory to prevent leaks
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
