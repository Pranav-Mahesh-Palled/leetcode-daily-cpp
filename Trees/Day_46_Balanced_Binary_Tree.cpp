/**
 * ============================================================================
 * Problem Name : Balanced Binary Tree
 * Day Number   : Day 46
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Visits every node once in the worst case; faster on imbalanced trees due to early pruning.
 *   - Space Complexity : O(H) auxiliary space — Call stack memory bounded by the maximum height H of the binary tree.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Bottom-Up Pruning Efficiency: Returning -1 as soon as an imbalanced
 *     subtree is detected short-circuits execution, preventing unnecessary
 *     recursive calls on remaining subtrees.
 *   - ) Redundancy: A naive top-down approach computes height() repeatedly
 *     for every node, resulting in
 *   - Standard Library Qualification: Explicitly qualifying std::abs and
 *     std::max ensures compatibility across strict C++ compilers and
 *     eliminates potential macro name collisions.
 *   - Key Takeaway: Passing sentinel return values (like -1 for invalid
 *     states) up a post-order recursion tree allows you to calculate
 *     properties (like height) while checking constraints (like balance) in a
 *     single O(N) pass.
 * ============================================================================
 */
#include <algorithm>
#include <cmath>
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
    // Helper function returning tree height or -1 if imbalanced
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Short-circuit early

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Short-circuit early

        if (std::abs(leftHeight - rightHeight) > 1) {
            return -1; // Imbalance detected
        }

        return 1 + std::max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        return checkHeight(root) != -1;
    }
};
