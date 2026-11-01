/**
 * ============================================================================
 * Problem Name : Merge Two Sorted Lists
 * Day Number   : Day 18
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N+M) — At most N+M comparisons and pointer reassignment operations.
 *   - Space Complexity : O(1) auxiliary space — Merges the original nodes directly in-place without creating new objects.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Clean Pointer Stitching:
 *   - Remainder Handling:
 *   - Key Takeaway: Always prefer allocating dummy nodes on the stack
 *     (ListNode dummy;) over the heap (new ListNode()) when solving linked
 *     list problems in C++. It eliminates heap allocation overhead and
 *     prevents memory leaks.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Anchor node allocated on the stack
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Compare and stitch nodes in sorted order
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining chain
        tail->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};
