/**
 * ============================================================================
 * Problem Name : Maximum Depth of Binary Tree
 * Day Number   : Day 27
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Performs a single traversal across all N nodes.
 *   - Space Complexity : O(H) auxiliary space — Call stack memory scales with the tree height H.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Clean Base Case Handling:
 *   - Idiomatic C++ Style:
 *   - Competitive Fast I/O:
 *   - Tech Interview Alternative: Iterative BFS (Level-Order Traversal) If an
 *     interviewer asks for an iterative solution to avoid potential stack
 *     overflow on extremely deep trees ( N>10 5 ), you can perform a
 *     Level-Order Traversal using a std::queue. Each completed loop over a
 *     queue level increments your depth counter:
 * ============================================================================
 */
#include <algorithm>
#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (!root) return 0;

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
