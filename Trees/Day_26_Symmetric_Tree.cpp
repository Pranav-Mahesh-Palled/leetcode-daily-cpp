/**
 * ============================================================================
 * Problem Name : Symmetric Tree
 * Day Number   : Day 26
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Exactly N/2 mirror pairs are checked in the worst case.
 *   - Space Complexity : O(H) auxiliary space — Recursion stack is bounded by the height of the tree.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Mirror Cross-Traversal:
 *   - Access Specifiers (private vs public):
 *   - Code Conciseness:
 *   - Tech Interview Alternative: Iterative Traversal (Using Queue) Just as
 *     with Same Tree, interviewers frequently follow up by asking: "Can you
 *     solve this iteratively without using recursion?" Here is how to perform
 *     an Iterative Breadth-First Search (BFS) using a queue to push node
 *     pairs in mirror order:
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
private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Base Case 1: Both nodes are null -> mirror match
        if (!t1 && !t2) return true;

        // Base Case 2: One node is null while the other is not -> mismatch
        if (!t1 || !t2) return false;

        // Base Case 3: Values must match AND outer/inner subtrees must mirror
        return (t1->val == t2->val) && 
               isMirror(t1->left, t2->right) && 
               isMirror(t1->right, t2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};
