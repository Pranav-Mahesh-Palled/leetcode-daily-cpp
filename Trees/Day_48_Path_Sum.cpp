/**
 * ============================================================================
 * Problem Name : Path Sum
 * Day Number   : Day 48
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass traversal in the worst case.
 *   - Space Complexity : O(H) auxiliary space — Call stack memory scales with tree height H.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Recursive Fast I/O Trap: Placing ios_base::sync_with_stdio(false);
 *     directly inside hasPathSum() causes C++ stream-unlinking statements to
 *     re-run on every single recursive call across all
 *   - Strict Leaf Node Validation: Checking !root->left && !root->right
 *     prevents false positives on internal nodes that have only one child.
 *   - Short-Circuit Evaluation: Using || between the left and right subtree
 *     calls ensures that as soon as one valid path is found, remaining search
 *     branches are skipped immediately.
 *   - Tech Interview Alternative: Explicit Stack DFS (Iterative)
 * ============================================================================
 */
#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool dfs(TreeNode* node, int target) {
        if (!node) return false;

        // Base case: Leaf node check
        if (!node->left && !node->right) {
            return target == node->val;
        }

        int remaining = target - node->val;
        return dfs(node->left, remaining) || dfs(node->right, remaining);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Fast I/O optimization executed once
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        return dfs(root, targetSum);
    }
};
