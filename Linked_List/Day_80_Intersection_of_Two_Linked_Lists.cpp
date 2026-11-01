/**
 * ============================================================================
 * Problem Name : Intersection of Two Linked Lists
 * Day Number   : Day 80
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N+M) — Bounded by at most 2(N+M) pointer steps.
 *   - Space Complexity : O(1) auxiliary space — Strict constant extra memory footprint.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Length Equivalence Magic:
 *   - O(1) Auxiliary Space:
 *   - O(N) hash set (std::unordered_set<ListNode*>), your solution operates
 *     purely in
 *   - Null Pointer Safety:
 *   - Tech Interview Alternative: Explicit Length Difference Offset In
 *     technical interviews, interviewers often ask: "Can you solve this
 *     without switching pointers across lists?"
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (!headA || !headB) {
            return nullptr;
        }

        ListNode* pA = headA;
        ListNode* pB = headB;

        // Loop until pointers meet (either at intersection node or at nullptr)
        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};
