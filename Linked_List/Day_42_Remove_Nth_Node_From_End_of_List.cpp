/**
 * ============================================================================
 * Problem Name : Remove Nth Node From End of List
 * Day Number   : Day 42
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Exactly N+1 total pointer moves in a single pass.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Dummy Node Simplification: Using a stack-allocated dummy head node
 *     (ListNode dummy(0, head);) eliminates the special if (fast == nullptr)
 *     check. Since slow starts at dummy, it naturally stops at the node
 *     immediately preceding the target node—even when removing the very first
 *     element.
 *   - C++ Memory Management: In production C++ and system interviews,
 *     unlinking a node without deallocating it causes a memory leak.
 *     Explicitly deleting the removed node with delete toDelete; makes your
 *     solution memory-safe.
 *   - Fast I/O Stream Unlinking: Adding ios_base::sync_with_stdio(false);
 *     cin.tie(nullptr); guarantees 0ms execution on submission platforms.
 *   - Key Takeaway: When performing deletions on singly-linked lists,
 *     starting pointer traversals from a dummy node unifies edge-case logic
 *     (like head node removal) into a single code path while keeping memory
 *     usage at strict O(1).
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Advance fast pointer so that fast and slow are separated by n + 1 nodes
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move both pointers simultaneously until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow->next is the node to be removed
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete; // Deallocate heap memory to prevent memory leak

        return dummy.next;
    }
};
