/**
 * ============================================================================
 * Problem Name : Minimum Depth of Binary Tree
 * Day Number   : Day 47
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) worst-case — Halts immediately upon finding the first leaf node.
 *   - Space Complexity : O(W) auxiliary space — Queue holds at most W nodes where W is the maximum level width.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Queue Storage Optimization: Storing pair<TreeNode*, int> allocates
 *     extra memory for every node pushed to the queue. Tracking the queue
 *     level size (q.size()) in a loop allows using a leaner queue<TreeNode*>.
 *   - C++17 Features: Your use of C++17 structured bindings (auto [node,
 *     depth]) is modern and clean.
 *   - Key Takeaway: For maximum depth or full tree evaluation, recursive DFS
 *     is concise; for minimum depth or shortest path searches, level-order
 *     BFS is superior due to its early termination capability.
 * ============================================================================
 */
#include <queue>
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
public:
    int minDepth(TreeNode* root) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (!root) return 0;

        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // First leaf encountered -> return current depth immediately
                if (!node->left && !node->right) {
                    return depth;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            depth++; // Advance to next tree level
        }

        return depth;
    }
};
