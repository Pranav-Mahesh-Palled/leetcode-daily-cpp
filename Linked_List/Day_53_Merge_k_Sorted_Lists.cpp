/**
 * ============================================================================
 * Problem Name : Merge k Sorted Lists
 * Day Number   : Day 53
 * Topic        : Linked_List
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(NlogK) — Performs N pop and push operations on a heap of size ≤K.
 *   - Space Complexity : O(K) auxiliary space — Memory allocated for the priority queue.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Min-Heap Selection Efficiency: Keeping at most
 *   - Stack-Allocated Dummy Node: Your continued use of ListNode dummy(0)
 *     eliminates dynamic memory allocation overhead and keeps list re-wiring
 *     completely clean.
 *   - Tech Interview Alternative: Divide & Conquer ( O(1) Auxiliary Space)
 * ============================================================================
 */
#include <vector>
#include <queue>
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
    struct Compare {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;

        // Push non-null initial head pointers
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};
