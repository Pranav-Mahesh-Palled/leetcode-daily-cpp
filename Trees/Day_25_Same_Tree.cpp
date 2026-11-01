/**
 * ============================================================================
 * Problem Name : Same Tree
 * Day Number   : Day 25
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(min(N,M)) — Halts early on mismatched nodes; checks at most N nodes when identical.
 *   - Space Complexity : O(min(H p,H q)) auxiliary space — Stack space bounded by the tree height.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Short-Circuit Evaluation:
 *   - Base Case Order:
 *   - Competitive Programming Fast I/O:
 *   - Tech Interview Alternative: Iterative BFS (Using Queue) In technical
 *     interviews, you may be asked to avoid recursion to prevent call stack
 *     overflow on very deep trees. Here is the Iterative Breadth-First Search
 *     (BFS) equivalent:
 * ============================================================================
 */
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        // Case 1: Both nodes are null -> structural match
        if (!p && !q) return true;

        // Case 2: One node is null while the other is not -> structural mismatch
        if (!p || !q) return false;

        // Case 3: Both nodes exist -> check value equality & recursively check subtrees
        return (p->val == q->val) && 
               isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};
